$NetBSD: patch-src_libs_libgroff_error.cpp,v 1.1 2020/03/30 19:32:24 joerg Exp $

--- src/libs/libgroff/error.cpp.orig	2020-03-29 11:11:17.837577107 +0000
+++ src/libs/libgroff/error.cpp
@@ -17,6 +17,10 @@ for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>. */
 
+#ifdef HAVE_CONFIG_H
+# include "config.h"
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
