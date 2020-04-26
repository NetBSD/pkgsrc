$NetBSD: patch-text_eqn_e.h,v 1.1 2020/04/26 20:23:39 rillig Exp $

Fix error message about unfinished macro argument to sprintf.

--- text/eqn/e.h.orig	2015-05-17 16:28:51.000000000 +0000
+++ text/eqn/e.h
@@ -21,7 +21,7 @@ extern int class[LAST][LAST];
 
 extern	char	errbuf[200];
 extern	char	*cmdname;
-#define	ERROR	sprintf(errbuf,
+#define	ERROR	(sprintf)(errbuf,
 #define	FATAL	), error(1, errbuf)
 #define	WARNING	), error(0, errbuf)
 #define	SYNTAX	), yyerror(errbuf)
