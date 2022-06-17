$NetBSD: patch-src_proto__sockpair.c,v 1.3 2022/06/17 08:07:31 adam Exp $

Special handling for XPG4_2 on SunOS.

--- src/proto_sockpair.c.orig	2022-05-31 14:58:21.000000000 +0000
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
 #include <pwd.h>
