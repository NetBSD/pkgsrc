$NetBSD: patch-flower_polynomial.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- flower/polynomial.cc.orig	2013-06-16 18:38:24.000000000 +0000
+++ flower/polynomial.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "polynomial.hh"
 
 #include "warn.hh"
