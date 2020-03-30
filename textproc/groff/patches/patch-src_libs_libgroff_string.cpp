$NetBSD: patch-src_libs_libgroff_string.cpp,v 1.1 2020/03/30 19:32:24 joerg Exp $

--- src/libs/libgroff/string.cpp.orig	2020-03-29 11:16:35.446496528 +0000
+++ src/libs/libgroff/string.cpp
@@ -17,6 +17,10 @@ for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>. */
 
+#ifdef HAVE_CONFIG_H
+# include "config.h"
+#endif
+
 #include <stdlib.h>
 
 #include "lib.h"
