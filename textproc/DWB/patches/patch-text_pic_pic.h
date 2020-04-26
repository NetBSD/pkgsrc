$NetBSD: patch-text_pic_pic.h,v 1.1 2020/04/26 20:23:39 rillig Exp $

Fix error message about unfinished macro argument to sprintf.

--- text/pic/pic.h.orig	2015-05-17 16:28:51.000000000 +0000
+++ text/pic/pic.h
@@ -9,7 +9,7 @@
 #define	dprintf	if(dbg)printf
 
 extern	char	errbuf[200];
-#define	ERROR	sprintf(errbuf,
+#define	ERROR	(sprintf)(errbuf,
 #define	FATAL	), yyerror(errbuf), exit(1)
 #define	WARNING	), yyerror(errbuf)
 
