$NetBSD: patch-lily_quote-iterator.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/quote-iterator.cc.orig	2013-06-16 19:20:57.000000000 +0000
+++ lily/quote-iterator.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "music-wrapper-iterator.hh"
 
 #include "context.hh"
