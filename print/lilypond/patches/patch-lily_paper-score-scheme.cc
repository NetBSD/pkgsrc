$NetBSD: patch-lily_paper-score-scheme.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/paper-score-scheme.cc.orig	2013-06-16 19:56:35.000000000 +0000
+++ lily/paper-score-scheme.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "paper-score.hh"
 
 LY_DEFINE (ly_paper_score_paper_systems, "ly:paper-score-paper-systems",
