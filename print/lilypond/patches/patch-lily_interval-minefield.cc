$NetBSD: patch-lily_interval-minefield.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/interval-minefield.cc.orig	2013-06-16 18:46:53.000000000 +0000
+++ lily/interval-minefield.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "interval-minefield.hh"
 #include "grob.hh"
 Interval_minefield::Interval_minefield (Interval feasible_placements, Real bulk)
