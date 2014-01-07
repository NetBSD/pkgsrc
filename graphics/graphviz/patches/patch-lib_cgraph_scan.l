$NetBSD: patch-lib_cgraph_scan.l,v 1.1.2.2 2014/01/07 19:49:15 tron Exp $

http://secunia.com/advisories/55666/

https://github.com/ellson/graphviz/commit/7aaddf52cd98589fb0c3ab72a393f8411838438a#diff-0

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
@@ -191,13 +192,21 @@ ID		({NAME}|{NUMBER})
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
+	sprintf(buf," %s in line %d near '", str,line_num);
+	agxbput (&xb, buf);
+	agxbput (&xb, yytext);
+	agxbput (&xb,"'\n");
+	agerr(AGWARN,agxbuse(&xb));
+	agxbfree(&xb);
 }
 /* must be here to see flex's macro defns */
 void aglexeof() { unput(GRAPH_EOF_TOKEN); }
