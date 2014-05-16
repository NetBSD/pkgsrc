$NetBSD: patch-lib_roken_vis.c,v 1.1 2014/05/16 12:49:42 ryoon Exp $

--- lib/roken/vis.c.orig	2012-12-09 22:06:44.000000000 +0000
+++ lib/roken/vis.c
@@ -55,6 +55,11 @@
  * POSSIBILITY OF SUCH DAMAGE.
  */
 
+/* OpenBSD 5.5 has not VIS_HTTPSTYLE. */
+#if defined(__OpenBSD__)
+#define VIS_HTTPSTYLE	0x0080
+#endif
+
 #if 1
 #include <config.h>
 #include "roken.h"
