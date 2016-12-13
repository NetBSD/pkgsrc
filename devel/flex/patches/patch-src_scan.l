$NetBSD: patch-src_scan.l,v 1.1 2016/12/13 17:07:23 wiedi Exp $

Pull in two upstream commits:
 - https://github.com/westes/flex/commit/e1038db19a6fda98a19a1df4d5f62c74c63b57d5
	"Fix another escaping bug"
 - https://github.com/westes/flex/commit/c8ad3d682fb0ea39e30a70449c7f88b8cd8da6b4
	"Fixes a major bug in Flex's own lexing of literals"

--- src/scan.l.orig	2016-10-23 18:04:57.000000000 +0000
+++ src/scan.l
@@ -102,20 +102,22 @@ extern const char *escaped_qstart, *esca
 		posix_compat = true;
 
 #define START_CODEBLOCK(x) do { \
-     /* Emit the needed line directive... */\
-     if (indented_code == false) { \
-         linenum++; \
-         line_directive_out(NULL, 1); \
-     } \
-     add_action(M4QSTART); \
-     yy_push_state(CODEBLOCK); \
-     if ((indented_code = x)) ACTION_ECHO; \
-     } while(0)
+    /* Emit the needed line directive... */\
+    if (indented_code == false) { \
+        linenum++; \
+        line_directive_out(NULL, 1); \
+    } \
+    add_action(M4QSTART); \
+    yy_push_state(CODEBLOCK); \
+    if ((indented_code = x)) ACTION_ECHO; \
+} while(0)
+
 #define END_CODEBLOCK do { \
-     yy_pop_state();\
+    yy_pop_state();\
     add_action(M4QEND); \
-     if (!indented_code) line_directive_out(NULL, 0);\
-      } while (0)
+    if (!indented_code) line_directive_out(NULL, 0);\
+} while (0)
+
 %}
 
 %option caseless nodefault noreject stack noyy_top_state
@@ -486,17 +488,18 @@ COMMENT,CODE_COMMENT>{
 
 	^{WS} START_CODEBLOCK(true); /* indented code in prolog */
 
-	^{NOT_WS}.*	{	/* non-indented code */
-			if ( bracelevel <= 0 )
-				{ /* not in %{ ... %} */
-				yyless( 0 );	/* put it all back */
-				yy_set_bol( 1 );
-				mark_prolog();
-				BEGIN(SECT2);
-				}
-			else
-				ACTION_ECHO;
-			}
+	^{NOT_WS}.*	{
+        /* non-indented code */
+		if ( bracelevel <= 0 ) {
+            /* not in %{ ... %} */
+            yyless( 0 );	/* put it all back */
+            yy_set_bol( 1 );
+            mark_prolog();
+            BEGIN(SECT2);
+        } else {
+            START_CODEBLOCK(true);
+        }
+    }
 
 	.		ACTION_ECHO;
 	{NL}	++linenum; ACTION_ECHO;
@@ -903,30 +906,28 @@ nmstr[yyleng - 2 - end_is_ws] = '\0';  /
 	<ACTION>"/*"		ACTION_ECHO; yy_push_state( CODE_COMMENT );
 
 	<CODEBLOCK,ACTION>{
-		"reject"	{
-			ACTION_ECHO;
-			CHECK_REJECT(yytext);
-			}
-		"yymore"	{
-			ACTION_ECHO;
-			CHECK_YYMORE(yytext);
-			}
+		"reject" {
+            ACTION_ECHO;
+            CHECK_REJECT(yytext);
+        }
+		"yymore" {
+            ACTION_ECHO;
+            CHECK_YYMORE(yytext);
+        }
 	}
 
-    .           ACTION_ECHO;
-	{NL}		{
-			++linenum;
-			ACTION_ECHO;
-			if ( bracelevel == 0 ||
-			     (doing_codeblock && indented_code) )
-				{
-				if ( doing_rule_action )
-					add_action( "\tYY_BREAK]""]\n" );
-
-				doing_rule_action = doing_codeblock = false;
-				BEGIN(SECT2);
-				}
-			}
+    .       ACTION_ECHO;
+	{NL}	{
+		++linenum;
+		ACTION_ECHO;
+		if (bracelevel == 0 || (doing_codeblock && indented_code)) {
+            if ( doing_rule_action )
+                add_action( "\tYY_BREAK]""]\n" );
+
+            doing_rule_action = doing_codeblock = false;
+            BEGIN(SECT2);
+        }
+    }
 }
 
 
@@ -935,38 +936,37 @@ nmstr[yyleng - 2 - end_is_ws] = '\0';  /
 	"{"		ACTION_ECHO; ++bracelevel;
 	"}"		ACTION_ECHO; --bracelevel;
 	[^[:alpha:]_{}\"'/\n\[\]]+	ACTION_ECHO;
-    [\[\]]      ACTION_ECHO;
-	{NAME}		ACTION_ECHO;
+        {NAME}		ACTION_ECHO;
         "'"([^\'\\\n]|\\.)"'" ACTION_ECHO; /* character constant */
-        "'"             ACTION_ECHO; yy_push_state(CHARACTER_CONSTANT);
+        "'"             ACTION_ECHO; BEGIN(CHARACTER_CONSTANT);
 	\"		ACTION_ECHO; BEGIN(ACTION_STRING);
-	{NL}		{
+	{NL} {
 			++linenum;
 			ACTION_ECHO;
-			if ( bracelevel == 0 )
-				{
+			if (bracelevel == 0) {
 				if ( doing_rule_action )
-					add_action( "\tYY_BREAK]""]\n" );
+                    add_action( "\tYY_BREAK]""]\n" );
 
-				doing_rule_action = false;
-				BEGIN(SECT2);
-				}
-			}
-	.		ACTION_ECHO;
+                doing_rule_action = false;
+                BEGIN(SECT2);
+            }
+        }
+        .      ACTION_ECHO;
 }
 
 <ACTION_STRING>{
-	[^\]\"\\\n\[MmY]+	ACTION_ECHO;
+	[^\[\]\"\\\n]+	ACTION_ECHO;
 	\"		ACTION_ECHO; BEGIN(ACTION);
 }
 <CHARACTER_CONSTANT>{
-	[^\[\]\'\\\nMmY]+       ACTION_ECHO;
-        \'              ACTION_ECHO; yy_pop_state();
+	[^\[\]\'\\\n]+  ACTION_ECHO;
+        \'              ACTION_ECHO; BEGIN(ACTION);
 }
 <ACTION_STRING,CHARACTER_CONSTANT>{
-	\\.		ACTION_ECHO;
-	{NL}		++linenum; ACTION_ECHO;
-	.		ACTION_ECHO;
+        (\\\n)*         ACTION_ECHO;
+	\\(\\\n)*.	ACTION_ECHO;
+	{NL}	++linenum; ACTION_ECHO; BEGIN(ACTION);
+        .	ACTION_ECHO;
 }
 
 <COMMENT,CODE_COMMENT,COMMENT_DISCARD,ACTION,ACTION_STRING,CHARACTER_CONSTANT><<EOF>>	{
@@ -991,8 +991,8 @@ nmstr[yyleng - 2 - end_is_ws] = '\0';  /
 <SECT3>{
     {M4QSTART}   fputs(escaped_qstart, yyout);
     {M4QEND}     fputs(escaped_qend, yyout);
-    [^\[\]\n]*(\n?) ECHO;
-    .|\n         ECHO;
+    [^\[\]]*     ECHO;
+    [][]         ECHO;
     <<EOF>>      {
         sectnum = 0;
         yyterminate();
@@ -1001,8 +1001,8 @@ nmstr[yyleng - 2 - end_is_ws] = '\0';  /
 <SECT3_NOESCAPE>{
     {M4QSTART}  fprintf(yyout, "[""[%s]""]", escaped_qstart);
     {M4QEND}    fprintf(yyout, "[""[%s]""]", escaped_qend);
-    [^\[\]\n]*(\n?) ECHO;
-    (.|\n)      ECHO;
+    [^][]*      ECHO;
+    [][]        ECHO;
     <<EOF>>		{
        sectnum = 0;
        yyterminate();
