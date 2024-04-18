$NetBSD: patch-src_s3fs.cpp,v 1.1 2024/04/18 04:02:26 pho Exp $

Fix build on NetBSD: <sys/wait.h> is required for WIFEXITED()
TODO: Upstream this

--- src/s3fs.cpp.orig	2024-04-17 13:55:35.890317856 +0000
+++ src/s3fs.cpp
@@ -18,6 +18,8 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
  */
 
+#include "config.h"
+
 #include <algorithm>
 #include <atomic>
 #include <cerrno>
@@ -28,6 +30,9 @@
 #include <unistd.h>
 #include <dirent.h>
 #include <sys/types.h>
+#if defined(HAVE_SYS_WAIT_H)
+#  include <sys/wait.h>
+#endif
 #include <getopt.h>
 
 #include "common.h"
