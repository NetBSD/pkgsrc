$NetBSD: patch-flower_interval-set.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- flower/interval-set.cc.orig	2013-06-16 18:41:26.000000000 +0000
+++ flower/interval-set.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "interval-set.hh"
 
 /*
