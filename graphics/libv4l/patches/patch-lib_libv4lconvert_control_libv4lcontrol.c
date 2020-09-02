$NetBSD: patch-lib_libv4lconvert_control_libv4lcontrol.c,v 1.1 2020/09/02 09:54:33 ryoon Exp $

--- lib/libv4lconvert/control/libv4lcontrol.c.orig	2020-05-02 12:16:20.000000000 +0000
+++ lib/libv4lconvert/control/libv4lcontrol.c
@@ -20,7 +20,7 @@
  */
 
 #include <sys/types.h>
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 #include <sys/sysmacros.h>
 #endif
 #include <sys/mman.h>
@@ -38,7 +38,7 @@
 #include "libv4lcontrol.h"
 #include "libv4lcontrol-priv.h"
 #include "../libv4lsyscall-priv.h"
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
