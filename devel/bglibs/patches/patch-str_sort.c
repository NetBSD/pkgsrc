$NetBSD: patch-str_sort.c,v 1.1 2025/12/20 12:29:24 nia Exp $

Fix implicit declaration of alloca(3).

--- str/sort.c.orig	2025-12-20 12:19:51.760569287 +0000
+++ str/sort.c
@@ -15,6 +15,9 @@
  * License along with this library; if not, write to the Free Software
  * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
  */
+#if defined(__linux__) || defined(__sun)
+#include <alloca.h>
+#endif
 #include <stdlib.h>
 #include <string.h>
 #include "str.h"
