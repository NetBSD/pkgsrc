$NetBSD: patch-flower_warn.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- flower/warn.cc.orig	2013-06-16 18:37:26.000000000 +0000
+++ flower/warn.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "warn.hh"
 
 #include <cstdlib>
