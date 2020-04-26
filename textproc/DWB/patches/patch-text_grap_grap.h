$NetBSD: patch-text_grap_grap.h,v 1.1 2020/04/26 20:23:39 rillig Exp $

Fix error message about unfinished macro argument to sprintf.

--- text/grap/grap.h.orig	2015-05-17 16:28:51.000000000 +0000
+++ text/grap/grap.h
@@ -1,6 +1,6 @@
 #include <stdlib.h>
 extern	char	errbuf[200];
-#define	ERROR	sprintf(errbuf,
+#define	ERROR	(sprintf)(errbuf,
 #define	FATAL	), yyerror(errbuf), exit(1)
 #define	WARNING	), yyerror(errbuf)
 
