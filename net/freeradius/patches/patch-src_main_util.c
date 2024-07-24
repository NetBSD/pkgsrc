$NetBSD: patch-src_main_util.c,v 1.2 2024/07/24 14:28:05 manu Exp $

O_DIRECTORY to open(2) is a Linuxism.

--- src/main/util.c.orig	2024-07-08 22:29:24.000000000 +0200
+++ src/main/util.c	2024-07-19 11:18:24.524415048 +0200
@@ -30,8 +30,16 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 
 /*
+ *      Not all libc implmenetations have O_DIRECTORY to pass to
+ *      open(2)
+ */
+#ifndef O_DIRECTORY
+#define O_DIRECTORY 0
+#endif
+
+/*
  *	The signal() function in Solaris 2.5.1 sets SA_NODEFER in
  *	sa_flags, which causes grief if signal() is called in the
  *	handler before the cause of the signal has been cleared.
  *	(Infinite recursion).
