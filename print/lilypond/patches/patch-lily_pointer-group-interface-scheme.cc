$NetBSD: patch-lily_pointer-group-interface-scheme.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/pointer-group-interface-scheme.cc.orig	2013-06-16 19:28:18.000000000 +0000
+++ lily/pointer-group-interface-scheme.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "pointer-group-interface.hh"
 #include "grob.hh"
 
