$NetBSD: patch-lily_spacing-options.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/spacing-options.cc.orig	2013-06-16 19:02:52.000000000 +0000
+++ lily/spacing-options.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "spacing-options.hh"
 #include "spacing-spanner.hh"
 #include "grob.hh"
