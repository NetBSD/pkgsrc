$NetBSD: patch-src_s3fs.cpp,v 1.2 2026/05/10 14:40:43 vins Exp $

Fix build on NetBSD: <sys/wait.h> is required for WIFEXITED()
TODO: Upstream this

--- src/s3fs.cpp.orig	2025-12-07 20:44:50.000000000 +0000
+++ src/s3fs.cpp
@@ -18,6 +18,8 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
  */
 
+#include "config.h"
+
 #include <algorithm>
 #include <atomic>
 #include <cerrno>
@@ -31,6 +33,9 @@
 #include <utility>
 #include <dirent.h>  // NOLINT(misc-include-cleaner)
 #include <sys/types.h>
+#if defined(HAVE_SYS_WAIT_H)
+#  include <sys/wait.h>
+#endif
 #include <getopt.h>  // NOLINT(misc-include-cleaner)
 
 #include "common.h"
