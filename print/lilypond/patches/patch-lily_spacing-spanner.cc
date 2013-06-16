$NetBSD: patch-lily_spacing-spanner.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/spacing-spanner.cc.orig	2013-06-16 19:05:36.000000000 +0000
+++ lily/spacing-spanner.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "spacing-spanner.hh"
 
 #include <math.h>
