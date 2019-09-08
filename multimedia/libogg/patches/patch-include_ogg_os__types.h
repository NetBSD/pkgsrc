$NetBSD: patch-include_ogg_os__types.h,v 1.1 2019/09/08 19:11:30 dbj Exp $

use stdint.h on macos
This was broken by a recent change.  See comments in:
https://gitlab.xiph.org/xiph/ogg/issues/2294

--- include/ogg/os_types.h.orig	2019-08-13 16:31:53.000000000 +0000
+++ include/ogg/os_types.h
@@ -70,7 +70,7 @@
 
 #elif (defined(__APPLE__) && defined(__MACH__)) /* MacOS X Framework build */
 
-#  include <sys/types.h>
+#  include <stdint.h>
    typedef int16_t ogg_int16_t;
    typedef uint16_t ogg_uint16_t;
    typedef int32_t ogg_int32_t;
