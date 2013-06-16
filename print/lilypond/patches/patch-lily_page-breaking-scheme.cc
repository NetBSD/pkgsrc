$NetBSD: patch-lily_page-breaking-scheme.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/page-breaking-scheme.cc.orig	2013-06-16 18:45:30.000000000 +0000
+++ lily/page-breaking-scheme.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "paper-book.hh"
 #include "page-turn-page-breaking.hh"
 #include "one-line-page-breaking.hh"
