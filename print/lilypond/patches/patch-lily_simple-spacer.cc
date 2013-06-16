$NetBSD: patch-lily_simple-spacer.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/simple-spacer.cc.orig	2013-06-16 19:01:36.000000000 +0000
+++ lily/simple-spacer.cc
@@ -20,6 +20,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include <cstdio>
 
 #include "column-x-positions.hh"
