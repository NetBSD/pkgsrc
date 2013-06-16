$NetBSD: patch-lily_page-spacing-result.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/page-spacing-result.cc.orig	2013-06-16 19:12:54.000000000 +0000
+++ lily/page-spacing-result.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "page-spacing-result.hh"
 #include <cstdio>
 
