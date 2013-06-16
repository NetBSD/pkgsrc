$NetBSD: patch-lily_key-signature-interface.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/key-signature-interface.cc.orig	2013-06-16 19:28:17.000000000 +0000
+++ lily/key-signature-interface.cc
@@ -19,6 +19,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "accidental-interface.hh"
 #include "font-interface.hh"
 #include "international.hh"
