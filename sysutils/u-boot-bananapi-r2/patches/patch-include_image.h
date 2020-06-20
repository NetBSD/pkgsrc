$NetBSD: patch-include_image.h,v 1.1 2020/06/20 17:42:34 thorpej Exp $

Ensure the correct byte order macros are used when image.h is included
in a host tool.

--- include/image.h.orig	2020-06-20 13:48:00.000000000 +0000
+++ include/image.h	2020-06-20 13:51:12.000000000 +0000
@@ -16,7 +16,6 @@
 #define __IMAGE_H__
 
 #include "compiler.h"
-#include <asm/byteorder.h>
 #include <stdbool.h>
 
 /* Define this to avoid #ifdefs later on */
@@ -26,6 +25,13 @@ struct fdt_region;
 #ifdef USE_HOSTCC
 #include <sys/types.h>
 
+#include <endian.h>
+#if _BYTE_ORDER == _BIG_ENDIAN
+#  include <linux/byteorder/big_endian.h>
+#else
+#  include <linux/byteorder/little_endian.h>
+#endif
+
 /* new uImage format support enabled on host */
 #define IMAGE_ENABLE_FIT	1
 #define IMAGE_ENABLE_OF_LIBFDT	1
@@ -40,6 +46,7 @@ struct fdt_region;
 
 #else
 
+#include <asm/byteorder.h>
 #include <lmb.h>
 #include <asm/u-boot.h>
 #include <command.h>
