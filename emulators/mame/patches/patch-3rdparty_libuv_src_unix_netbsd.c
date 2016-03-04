$NetBSD: patch-3rdparty_libuv_src_unix_netbsd.c,v 1.1 2016/03/04 12:47:13 wiz Exp $

--- 3rdparty/libuv/src/unix/netbsd.c.orig	2016-02-24 07:02:17.000000000 +0000
+++ 3rdparty/libuv/src/unix/netbsd.c
@@ -18,6 +18,9 @@
  * IN THE SOFTWARE.
  */
 
+/* needs kernel internal types */
+#define _KMEMUSER 1
+
 #include "uv.h"
 #include "internal.h"
 
