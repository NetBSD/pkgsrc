$NetBSD: patch-lily_spacing-loose-columns.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/spacing-loose-columns.cc.orig	2013-06-16 18:57:45.000000000 +0000
+++ lily/spacing-loose-columns.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "system.hh"
 #include "paper-column.hh"
 #include "column-x-positions.hh"
