$NetBSD: patch-as31.y,v 1.1 2012/07/03 18:13:26 joerg Exp $

--- as31.y.orig	2012-07-03 10:49:15.000000000 +0000
+++ as31.y
@@ -28,6 +28,10 @@
 
 #define YYSTYPE union ystack
 
+void genbyte(int);
+void emitbyte(int);
+void emitaddr(unsigned long);
+
 extern int lineno;
 extern int dashl;
 extern char *asmfile;
@@ -948,6 +952,10 @@ relative	: expr
 
 %%
 
+#include <stdarg.h>
+void error(const char *, ...);
+void warning(const char *, ...);
+
 /* ---------------------------------------------------------------------- */
 
 yyerror(s)
@@ -963,11 +971,13 @@ char *s;
  *	termination.
  */
 
-error(cs,a1,a2,a3,a4,a5,a6)
-char *cs,*a1,*a2,*a3,*a4,*a5,*a6;
+void error(const char *cs, ...)
 {
+	va_list ap;
+	va_start(ap, cs);
 	fprintf(stderr,"File: %s, line: %d, ",asmfile,lineno);
-	fprintf(stderr,cs,a1,a2,a3,a4,a5,a6);
+	vfprintf(stderr,cs, ap);
+	va_end(ap);
 	fprintf(stderr,".\n");
 	longjmp(main_env,1);
 }
@@ -979,12 +989,14 @@ char *cs,*a1,*a2,*a3,*a4,*a5,*a6;
  *
  */
 
-warning(cs,a1,a2,a3,a4,a5,a6)
-char *cs,*a1,*a2,*a3,*a4,*a5,*a6;
+void warning(const char *cs, ...)
 {
+	va_list ap;
+	va_start(ap, cs);
 	fatal++;
 	fprintf(stderr,"File: %s, line: %d, ",asmfile,lineno);
-	fprintf(stderr,cs,a1,a2,a3,a4,a5,a6);
+	vfprintf(stderr,cs, ap);
+	va_end(ap);
 	fprintf(stderr,".\n");
 }
 
@@ -1095,7 +1107,7 @@ char *txt;
 {
 	int i,j;
 
-	fprintf(listing,show?"%04X: ":"      ",lc);
+	fprintf(listing,show?"%04lX: ":"      ",lc);
 
 	j=0;
 	for(i=0; i<bytecount; i++ ) {
@@ -1118,8 +1130,7 @@ char *txt;
  *
  */
 
-genbyte(b)
-int b;
+void genbyte(int b)
 {
 	if( bytecount < sizeof(bytebuf) )
 		bytebuf[bytecount++] = b;
