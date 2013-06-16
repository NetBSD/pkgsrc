$NetBSD: patch-lily_least-squares.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/least-squares.cc.orig	2013-06-16 19:19:17.000000000 +0000
+++ lily/least-squares.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "least-squares.hh"
 
 #include "warn.hh"
