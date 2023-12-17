$NetBSD: patch-enhance.c,v 1.1 2023/12/17 18:48:02 nros Exp $

* Fix implicit declaration of ioctl on NetBSD,
  sys/ioctl.h is included directly without configure ifdefs
  in other parts of the code.

--- enhance.c.orig	2023-12-17 18:39:17.507725147 +0000
+++ enhance.c
@@ -15,6 +15,7 @@
 #endif
 
 #include <fcntl.h>
+#include <sys/ioctl.h>
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/wait.h>
