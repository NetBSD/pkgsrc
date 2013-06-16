$NetBSD: patch-flower_file-name.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- flower/file-name.cc.orig	2013-06-16 18:41:41.000000000 +0000
+++ flower/file-name.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "file-name.hh"
 
 #include <cstdio>
