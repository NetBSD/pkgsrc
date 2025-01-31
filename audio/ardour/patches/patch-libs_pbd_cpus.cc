$NetBSD: patch-libs_pbd_cpus.cc,v 1.3 2025/01/31 22:01:23 wiz Exp $

Fix build on NetBSD and OpenBSD.
https://tracker.ardour.org/view.php?id=9886

--- libs/pbd/cpus.cc.orig	2024-02-04 02:25:51.019870123 +0000
+++ libs/pbd/cpus.cc
@@ -25,7 +25,7 @@
 
 #ifdef __linux__
 #include <unistd.h>
-#elif defined(__APPLE__) || defined(__FreeBSD__)
+#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <stddef.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
