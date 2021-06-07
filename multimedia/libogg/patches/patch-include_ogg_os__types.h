$NetBSD: patch-include_ogg_os__types.h,v 1.2 2021/06/07 09:12:32 adam Exp $

use stdint.h on macos
This was broken by a recent change.  See comments in:
https://gitlab.xiph.org/xiph/ogg/issues/2294

--- include/ogg/os_types.h.orig	2021-06-07 08:37:18.000000000 +0000
+++ include/ogg/os_types.h
@@ -70,7 +70,7 @@
 
 #elif (defined(__APPLE__) && defined(__MACH__)) /* MacOS X Framework build */
 
-#  include <sys/types.h>
+#  include <stdint.h>
    typedef int16_t ogg_int16_t;
    typedef u_int16_t ogg_uint16_t;
    typedef int32_t ogg_int32_t;
