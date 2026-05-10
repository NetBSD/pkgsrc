$NetBSD: patch-test_mknod__test.cc,v 1.2 2026/05/10 14:40:43 vins Exp $

Fix build on NetBSD: <sys/sysmacros.h> doesn't exist on this OS.
TODO: Upstream this.

--- test/mknod_test.cc.orig	2025-12-07 20:44:50.000000000 +0000
+++ test/mknod_test.cc
@@ -18,6 +18,8 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
  */
 
+#include "config.h"
+
 #include <cerrno>
 #include <cstdio>
 #include <cstdlib>
@@ -26,7 +28,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
-#if !defined(__APPLE__) && !defined(__FreeBSD__)
+#if defined(HAVE_SYS_SYSMACROS_H)
 #include <sys/sysmacros.h>
 #endif
 
