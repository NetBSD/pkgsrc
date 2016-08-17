$NetBSD: patch-src_utils_common.h,v 1.1 2016/08/17 04:57:47 maya Exp $

--- src/utils/common.h.orig	2015-09-27 19:02:05.000000000 +0000
+++ src/utils/common.h
@@ -11,6 +11,14 @@
 
 #include "os.h"
 
+/*
+ * NetBSD net/if.h defines if_type as a macro,
+ * which conflicts with the use of it in the code.
+ */
+#if defined(__NetBSD__)
+#undef if_type
+#endif
+
 #if defined(__linux__) || defined(__GLIBC__)
 #include <endian.h>
 #include <byteswap.h>
