$NetBSD: patch-lily_lily-lexer-scheme.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/lily-lexer-scheme.cc.orig	2013-06-16 19:27:04.000000000 +0000
+++ lily/lily-lexer-scheme.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "lily-lexer.hh"
 
 LY_DEFINE (ly_lexer_keywords, "ly:lexer-keywords",
