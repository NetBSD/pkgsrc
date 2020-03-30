$NetBSD: patch-src_libs_libgroff_assert.cpp,v 1.1 2020/03/30 19:32:24 joerg Exp $

--- src/libs/libgroff/assert.cpp.orig	2020-03-29 11:10:06.073227505 +0000
+++ src/libs/libgroff/assert.cpp
@@ -16,6 +16,10 @@ for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>. */
 
+#ifdef HAVE_CONFIG_H
+# include "config.h"
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include "assert.h"
