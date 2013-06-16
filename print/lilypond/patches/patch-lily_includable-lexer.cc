$NetBSD: patch-lily_includable-lexer.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/includable-lexer.cc.orig	2013-06-16 19:23:45.000000000 +0000
+++ lily/includable-lexer.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "includable-lexer.hh"
 
 #include <sstream>
