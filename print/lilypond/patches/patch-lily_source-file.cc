$NetBSD: patch-lily_source-file.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/source-file.cc.orig	2013-06-16 19:14:53.000000000 +0000
+++ lily/source-file.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #if GCC_MAJOR < 4
 #define _GLIBCXX_HAVE_MBSTATE_T
 #include <wchar.h>
@@ -181,8 +182,8 @@ Source_file::file_line_column_string (ch
       int l, ch, col, offset;
       get_counts (context_str0, &l, &ch, &col, &offset);
 
-      return name_string () + ":" + to_string (l)
-             + ":" + to_string (col);
+      return name_string () + ":" + ::to_string (l)
+             + ":" + ::to_string (col);
     }
 }
 
