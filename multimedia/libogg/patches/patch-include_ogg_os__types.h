$NetBSD: patch-include_ogg_os__types.h,v 1.3 2022/05/15 05:50:49 dholland Exp $

use stdint.h on macos
also use the types that are defined by stdint.h, not the legacy ones.

See https://gitlab.xiph.org/xiph/ogg/issues/2294

--- include/ogg/os_types.h.orig	2020-05-04 17:14:04.000000000 +0000
+++ include/ogg/os_types.h
@@ -70,13 +70,13 @@
 
 #elif (defined(__APPLE__) && defined(__MACH__)) /* MacOS X Framework build */
 
-#  include <sys/types.h>
+#  include <stdint.h>
    typedef int16_t ogg_int16_t;
-   typedef u_int16_t ogg_uint16_t;
+   typedef uint16_t ogg_uint16_t;
    typedef int32_t ogg_int32_t;
-   typedef u_int32_t ogg_uint32_t;
+   typedef uint32_t ogg_uint32_t;
    typedef int64_t ogg_int64_t;
-   typedef u_int64_t ogg_uint64_t;
+   typedef uint64_t ogg_uint64_t;
 
 #elif defined(__HAIKU__)
 
