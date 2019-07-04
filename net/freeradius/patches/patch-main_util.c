$NetBSD: patch-main_util.c,v 1.2 2019/07/04 07:44:52 adam Exp $

O_DIRECTORY to open(2) is a Linuxism.

--- src/main/util.c.orig	2016-09-29 15:19:48.000000000 +0000
+++ src/main/util.c
@@ -31,6 +31,14 @@ RCSID("$Id: 22299f8c8d6bc98616fa025ee3da
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
