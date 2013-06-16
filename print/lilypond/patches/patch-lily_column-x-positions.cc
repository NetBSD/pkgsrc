$NetBSD: patch-lily_column-x-positions.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/column-x-positions.cc.orig	2013-06-16 19:28:17.000000000 +0000
+++ lily/column-x-positions.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "column-x-positions.hh"
 
 Column_x_positions::Column_x_positions ()
