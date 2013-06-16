$NetBSD: patch-lily_flag.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/flag.cc.orig	2013-06-16 19:24:59.000000000 +0000
+++ lily/flag.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "stem.hh"
 
 #include "directional-element-interface.hh"
@@ -106,7 +107,7 @@ Flag::print (SCM smob)
 
   char dir = (d == UP) ? 'u' : 'd';
   string font_char = flag_style
-                     + to_string (dir) + staffline_offs + to_string (log);
+                     + ::to_string (dir) + staffline_offs + ::to_string (log);
   Font_metric *fm = Font_interface::get_default_font (me);
   Stencil flag = fm->find_by_name ("flags." + font_char);
   if (flag.is_empty ())
