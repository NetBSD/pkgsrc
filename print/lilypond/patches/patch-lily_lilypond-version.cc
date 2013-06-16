$NetBSD: patch-lily_lilypond-version.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/lilypond-version.cc.orig	2013-06-16 19:22:55.000000000 +0000
+++ lily/lilypond-version.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include <ctype.h>
 
 #include "lilypond-version.hh"
