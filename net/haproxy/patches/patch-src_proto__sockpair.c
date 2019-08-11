$NetBSD: patch-src_proto__sockpair.c,v 1.1 2019/08/11 09:09:41 maya Exp $

--- src/proto_sockpair.c.orig	2019-07-23 13:21:26.000000000 +0000
+++ src/proto_sockpair.c
@@ -10,6 +10,14 @@
  *
  */
 
+#if defined(__sun) && !defined(_XOPEN_SOURCE)
+#  if (__STDC_VERSION__-0 < 199901L)
+#define _XOPEN_SOURCE 500
+#  else
+#define _XOPEN_SOURCE 600
+#  endif
+#endif
+
 #include <ctype.h>
 #include <errno.h>
 #include <fcntl.h>
