$NetBSD: patch-xen_common_libelf_libelf-loader.c,v 1.1 2011/05/07 07:11:22 tnn Exp $

--- xen/common/libelf/libelf-loader.c.orig	2011-03-25 10:43:00.000000000 +0000
+++ xen/common/libelf/libelf-loader.c
@@ -16,7 +16,7 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
  */
 
-#include <stdarg.h>
+#include "../../include/xen/stdarg.h"
 
 #include "libelf-private.h"
 
