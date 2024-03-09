$NetBSD: patch-openbsd-compat_imsg-buffer.c,v 1.1 2024/03/09 23:55:46 vins Exp $

Fix build on SmartOS

--- openbsd-compat/imsg-buffer.c.orig	2024-03-09 21:39:43.809503619 +0000
+++ openbsd-compat/imsg-buffer.c
@@ -16,6 +16,15 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+/* needed for CMSG_* functions on SunOS */
+#if defined(__sun)
+#if (__STDC_VERSION__ - 0 < 199901L)
+#define _XOPEN_SOURCE 500
+#else
+#define _XOPEN_SOURCE 600
+#endif
+#endif
+
 #include "includes.h"
 
 #include <sys/param.h>
