$NetBSD: patch-src_shared_util.h,v 1.2 2023/06/04 09:06:16 plunky Exp $

Linux vs BSD incompatibilities

--- src/shared/util.h.orig	2022-03-16 15:06:20.000000000 +0000
+++ src/shared/util.h
@@ -11,8 +11,7 @@
 #include <stdint.h>
 #include <stdlib.h>
 #include <stdarg.h>
-#include <alloca.h>
-#include <byteswap.h>
+#include <endian.h>
 #include <string.h>
 #include <sys/types.h>
 
