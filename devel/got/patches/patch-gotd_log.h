$NetBSD: patch-gotd_log.h,v 1.2 2024/06/09 13:25:05 vins Exp $

Provide a declaration of va_list

--- lib/log.h.orig	2024-01-14 16:07:41.039068602 +0000
+++ lib/log.h
@@ -14,6 +14,7 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#include <stdarg.h>
 #include "got_compat.h"
 
 void	log_init(int, int);
