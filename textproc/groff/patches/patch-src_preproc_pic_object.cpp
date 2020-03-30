$NetBSD: patch-src_preproc_pic_object.cpp,v 1.1 2020/03/30 19:32:24 joerg Exp $

--- src/preproc/pic/object.cpp.orig	2020-03-29 11:20:12.373241574 +0000
+++ src/preproc/pic/object.cpp
@@ -17,6 +17,10 @@ for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>. */
 
+#ifdef HAVE_CONFIG_H
+# include "config.h"
+#endif
+
 #include <stdlib.h>
 
 #include "pic.h"
