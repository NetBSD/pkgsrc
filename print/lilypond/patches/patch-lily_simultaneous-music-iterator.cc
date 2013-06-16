$NetBSD: patch-lily_simultaneous-music-iterator.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/simultaneous-music-iterator.cc.orig	2013-06-16 19:28:18.000000000 +0000
+++ lily/simultaneous-music-iterator.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "simultaneous-music-iterator.hh"
 #include "music.hh"
 #include "context.hh"
@@ -63,7 +64,7 @@ Simultaneous_music_iterator::construct_c
 
       SCM name = ly_symbol2scm (get_outlet ()->context_name ().c_str ());
       Context *c = (j && create_separate_contexts_)
-                   ? get_outlet ()->find_create_context (name, to_string (j), SCM_EOL)
+                   ? get_outlet ()->find_create_context (name, ::to_string (j), SCM_EOL)
                    : get_outlet ();
 
       if (!c)
