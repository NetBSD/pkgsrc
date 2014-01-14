$NetBSD: patch-lib_cgraph_scan.l,v 1.1.2.3 2014/01/14 10:52:47 tron Exp $

http://secunia.com/advisories/55666/

https://github.com/ellson/graphviz/commit/7aaddf52cd98589fb0c3ab72a393f8411838438a#diff-0
https://github.com/ellson/graphviz/commit/d266bb2b4154d11c27252b56d86963aef4434750
https://github.com/ellson/graphviz/commit/1d1bdec6318746f6f19f245db589eddc887ae8ff

--- lib/cgraph/scan.l.orig	2013-09-07 01:07:52.000000000 +0000
+++ lib/cgraph/scan.l
@@ -16,6 +16,7 @@
 %{
 #include <grammar.h>
 #include <cghdr.h>
+#include <agxbuf.h>
 #include <ctype.h>
 #define GRAPH_EOF_TOKEN		'@'		/* lex class must be defined below */
 	/* this is a workaround for linux flex */
@@ -128,15 +129,32 @@ static void ppDirective (void)
  * and report this to the user.
  */
 static int chkNum(void) {
-  unsigned char	c = (unsigned char)yytext[yyleng-1];   /* last character */
-  if (!isdigit(c) && (c != '.')) {  /* c is letter */
-	char	buf[BUFSIZ];
-	sprintf(buf,"syntax error - badly formed number '%s' in line %d of %s\n",yytext,line_num, InputFile);
-    strcat (buf, "splits into two name tokens\n");
-	agerr(AGWARN,buf);
-    return 1;
-  }
-  else return 0;
+    unsigned char c = (unsigned char)yytext[yyleng-1];   /* last character */
+    if (!isdigit(c) && (c != '.')) {  /* c is letter */
+        unsigned char xbuf[BUFSIZ];
+        char buf[BUFSIZ];
+        agxbuf  xb;
+        char* fname;
+
+        if (InputFile)
+            fname = InputFile;
+        else
+            fname = "input";
+
+        agxbinit(&xb, BUFSIZ, xbuf);
+
+        agxbput(&xb,"syntax ambiguity - badly delimited number '");
+        agxbput(&xb,yytext);
+        sprintf(buf,"' in line %d of ", line_num);
+        agxbput(&xb,buf);
+        agxbput(&xb,fname);
+        agxbput(&xb, " splits into two tokens\n");
+        agerr(AGWARN,agxbuse(&xb));
+
+        agxbfree(&xb);
+        return 1;
+    }
+    else return 0;
 }
 
 /* The LETTER class below consists of ascii letters, underscore, all non-ascii
@@ -191,13 +209,22 @@ ID		({NAME}|{NUMBER})
 %%
 void yyerror(char *str)
 {
+	unsigned char  xbuf[BUFSIZ];
 	char	buf[BUFSIZ];
-	if (InputFile)
-		sprintf(buf,"%s:%d: %s in line %d near '%s'\n",InputFile, line_num,
-			str,line_num,yytext);
-	else
-		sprintf(buf," %s in line %d near '%s'\n", str,line_num,yytext);
-	agerr(AGWARN,buf);
+	agxbuf  xb;
+
+	agxbinit(&xb, BUFSIZ, xbuf);
+	if (InputFile) {
+		agxbput (&xb, InputFile);
+		agxbput (&xb, ": ");
+	}
+	agxbput (&xb, str);
+	sprintf(buf," in line %d near '", line_num);
+	agxbput (&xb, buf);
+	agxbput (&xb, yytext);
+	agxbput (&xb,"'\n");
+	agerr(AGWARN,agxbuse(&xb));
+	agxbfree(&xb);
 }
 /* must be here to see flex's macro defns */
 void aglexeof() { unput(GRAPH_EOF_TOKEN); }
