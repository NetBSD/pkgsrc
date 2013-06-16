$NetBSD: patch-flower_std-string.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- flower/std-string.cc.orig	2013-06-16 18:38:42.000000000 +0000
+++ flower/std-string.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "std-string.hh"
 #include "string-convert.hh"
 
