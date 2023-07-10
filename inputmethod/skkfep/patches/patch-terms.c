$NetBSD: patch-terms.c,v 1.2 2023/07/10 08:12:15 nia Exp $

--- terms.c.orig	1998-09-21 16:45:15.000000000 +0000
+++ terms.c
@@ -1,5 +1,7 @@
 #include	"config.h"
 #include	"fep.h"
+#include	<termcap.h>
+#include	<stdlib.h>
 
 /*#define SHOW_ESCSEQ		/* show escape sequences for debugging */
 
@@ -17,13 +19,8 @@ char	*T_TS, *T_FS, *T_SS,*T_HS,*T_ES;
 int     columns, lines;
 StatusType status;
 
-extern char *getenv();
 extern char ReverseStatus;
 
-/* termcap functions */
-extern char *tgetstr();
-extern char *tgoto();
-
 #ifdef SHOW_ESCSEQ
 printe(s,v)
 char *s,*v;
@@ -124,7 +121,7 @@ getTCstr()
 	}
 }
 
-setEnvirons()
+void setEnvirons(void)
 {
 	extern char *version;
 	char buf[1024], *p, *q, *e, c1, c2;
