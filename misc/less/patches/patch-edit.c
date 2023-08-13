$NetBSD: patch-edit.c,v 1.1 2023/08/13 19:41:47 leot Exp $

Unconditionally include <signal.h> due several SIG* references also
outside OS2 ifdef-s.

--- edit.c.orig	2023-07-20 22:43:14.000000000 +0000
+++ edit.c
@@ -16,9 +16,7 @@
 #if HAVE_SYS_WAIT_H
 #include <sys/wait.h>
 #endif
-#if OS2
 #include <signal.h>
-#endif
 
 public int fd0 = 0;
 
