$NetBSD: patch-lily_spacing-basic.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/spacing-basic.cc.orig	2013-06-16 18:45:13.000000000 +0000
+++ lily/spacing-basic.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "spacing-spanner.hh"
 
 #include "spacing-options.hh"
