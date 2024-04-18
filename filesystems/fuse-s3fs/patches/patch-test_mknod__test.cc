$NetBSD: patch-test_mknod__test.cc,v 1.1 2024/04/18 04:02:26 pho Exp $

Fix build on NetBSD: <sys/sysmacros.h> doesn't exist on this OS.
TODO: Upstream this.

--- test/mknod_test.cc.orig	2024-04-17 14:07:06.018370712 +0000
+++ test/mknod_test.cc
@@ -18,6 +18,8 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
  */
 
+#include "config.h"
+
 #include <cerrno>
 #include <cstdio>
 #include <cstdlib>
@@ -26,8 +28,8 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
-#ifndef __APPLE__
-#include <sys/sysmacros.h>
+#if defined(HAVE_SYS_SYSMACROS_H)
+#  include <sys/sysmacros.h>
 #endif
 
 //---------------------------------------------------------
