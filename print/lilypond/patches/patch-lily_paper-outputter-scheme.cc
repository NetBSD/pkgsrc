$NetBSD: patch-lily_paper-outputter-scheme.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/paper-outputter-scheme.cc.orig	2013-06-16 19:27:50.000000000 +0000
+++ lily/paper-outputter-scheme.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "paper-outputter.hh"
 
 #include "international.hh"
