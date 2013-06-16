$NetBSD: patch-flower_file-path.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- flower/file-path.cc.orig	2013-06-16 18:36:33.000000000 +0000
+++ flower/file-path.cc
@@ -18,12 +18,12 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "file-path.hh"
 
 #include <cstdio>
 #include <cerrno>
 
-#include "config.hh"
 #if HAVE_SYS_STAT_H
 #include <sys/stat.h>
 #endif
