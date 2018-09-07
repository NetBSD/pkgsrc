$NetBSD: patch-include_mgba-util_common.h,v 1.1 2018/09/07 18:54:02 nia Exp $

Make sure the locale definitions are defined properly.

--- include/mgba-util/common.h.orig	2018-04-14 20:49:19.000000000 +0000
+++ include/mgba-util/common.h
@@ -16,6 +16,13 @@
 
 CXX_GUARD_START
 
+#ifndef _POSIX_C_SOURCE
+#define _POSIX_C_SOURCE 200112L
+#endif
+#ifndef _XOPEN_SOURCE
+#define _XOPEN_SOURCE 600
+#endif
+
 #include <ctype.h>
 #include <fcntl.h>
 #include <inttypes.h>
