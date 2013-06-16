$NetBSD: patch-lily_performance-scheme.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/performance-scheme.cc.orig	2013-06-16 18:43:44.000000000 +0000
+++ lily/performance-scheme.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "performance.hh"
 
 LY_DEFINE (ly_performance_write, "ly:performance-write",
