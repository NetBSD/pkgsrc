$NetBSD: patch-lily_system.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/system.cc.orig	2013-06-16 18:54:24.000000000 +0000
+++ lily/system.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "system.hh"
 
 #include "align-interface.hh"
@@ -222,7 +223,7 @@ System::get_paper_systems ()
       scm_vector_set_x (lines, scm_from_int (i),
                         system->get_paper_system ());
 
-      debug_output (to_string (i) + "]", false);
+      debug_output (::to_string (i) + "]", false);
     }
   return lines;
 }
