$NetBSD: patch-gotd_log.h,v 1.1 2024/01/15 19:41:19 vins Exp $

Provide a declaration of va_list

--- gotd/log.h.orig	2024-01-14 16:07:41.039068602 +0000
+++ gotd/log.h
@@ -14,6 +14,7 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#include <stdarg.h>
 #include "got_compat.h"
 
 void	log_init(int, int);
