$NetBSD: patch-src_libs_libgroff_strsave.cpp,v 1.1 2020/03/30 19:32:24 joerg Exp $

--- src/libs/libgroff/strsave.cpp.orig	2020-03-29 11:17:43.644694801 +0000
+++ src/libs/libgroff/strsave.cpp
@@ -17,6 +17,10 @@ for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>. */
 
+#ifdef HAVE_CONFIG_H
+# include "config.h"
+#endif
+
 #include <string.h>
 #include <stdlib.h>
 
