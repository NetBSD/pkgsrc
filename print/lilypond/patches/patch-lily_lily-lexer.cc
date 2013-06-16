$NetBSD: patch-lily_lily-lexer.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/lily-lexer.cc.orig	2013-06-16 18:55:24.000000000 +0000
+++ lily/lily-lexer.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "lily-lexer.hh"
 
 #include <cctype>
