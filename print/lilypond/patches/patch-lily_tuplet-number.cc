$NetBSD: patch-lily_tuplet-number.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/tuplet-number.cc.orig	2013-06-16 19:03:29.000000000 +0000
+++ lily/tuplet-number.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "tuplet-bracket.hh"
 #include "moment.hh"
 #include "paper-column.hh"
