$NetBSD: patch-src_sysfiles.c,v 1.1 2013/07/18 12:07:25 joerg Exp $

--- src/sysfiles.c.orig	2013-07-18 09:51:28.000000000 +0000
+++ src/sysfiles.c
@@ -52,6 +52,7 @@ const char * Revision_sysfiles_c =
 
 #include        <sys/time.h>
 #include        <sys/types.h>
+#include        <termios.h>
 #endif
 #endif
 
