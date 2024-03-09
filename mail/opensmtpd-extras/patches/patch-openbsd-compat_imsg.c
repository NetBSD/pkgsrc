$NetBSD: patch-openbsd-compat_imsg.c,v 1.1 2024/03/09 23:55:46 vins Exp $

Fix build on SmartOS 

--- openbsd-compat/imsg.c.orig	2024-03-09 21:33:04.519759277 +0000
+++ openbsd-compat/imsg.c
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
