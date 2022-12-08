$NetBSD: patch-src_lib_fy-ctype.h,v 1.1 2022/12/08 19:16:20 khorben Exp $

Replace <alloca.h> by <stdlib.h>
Already merged upstream (https://github.com/pantoniou/libfyaml/pull/50)

--- src/lib/fy-ctype.h.orig	2022-01-19 10:32:21.000000000 +0000
+++ src/lib/fy-ctype.h
@@ -13,7 +13,7 @@
 #endif
 
 #include <stdint.h>
-#include <alloca.h>
+#include <stdlib.h>
 #include <string.h>
 #include <assert.h>
 
