$NetBSD: patch-src_process.c,v 1.1 2013/12/04 09:27:43 dholland Exp $

WCONTINUED does not universally exist.

--- src/process.c~	2013-11-26 03:15:49.000000000 +0000
+++ src/process.c
@@ -138,6 +138,10 @@ extern int sys_select (int, fd_set *, fd
 # define SOCK_CLOEXEC 0
 #endif
 
+#ifndef WCONTINUED
+#define WCONTINUED 0
+#endif
+
 #ifndef HAVE_ACCEPT4
 
 /* Emulate GNU/Linux accept4 and socket well enough for this module.  */
