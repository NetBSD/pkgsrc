$NetBSD: patch-misc.c,v 1.1 2025/04/29 14:18:00 tnn Exp $

--- misc.c.orig	2025-04-29 13:24:23.152144242 +0000
+++ misc.c
@@ -19,8 +19,6 @@ static char sccsic[] = "@(#) misc.c 1.2
 
 #include "tcpd.h"
 
-extern char *fgets();
-
 #ifndef	INADDR_NONE
 #define	INADDR_NONE	(-1)		/* XXX should be 0xffffffff */
 #endif
