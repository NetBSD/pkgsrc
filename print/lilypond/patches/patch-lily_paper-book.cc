$NetBSD: patch-lily_paper-book.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/paper-book.cc.orig	2013-06-16 19:22:05.000000000 +0000
+++ lily/paper-book.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "paper-book.hh"
 
 #include "grob.hh"
