$NetBSD: patch-lily_grace-iterator.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/grace-iterator.cc.orig	2013-06-16 19:04:30.000000000 +0000
+++ lily/grace-iterator.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "grace-iterator.hh"
 #include "global-context.hh"
 #include "warn.hh"
