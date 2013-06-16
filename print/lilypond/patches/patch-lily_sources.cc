$NetBSD: patch-lily_sources.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/sources.cc.orig	2013-06-16 19:28:18.000000000 +0000
+++ lily/sources.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "sources.hh"
 
 #include "config.hh"
