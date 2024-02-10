$NetBSD: patch-src_lib_fcitx-utils_uuid__p.h,v 1.1 2024/02/10 09:58:33 ryoon Exp $

Make sure uuiod.h from libuuid is included, when using <uuid.h>
the risk is that uuid.h from /usr/include gets included on BSD
systems and it does not have uuid_generate causeing build failure.

--- src/lib/fcitx-utils/uuid_p.h.orig	2023-11-25 13:47:31.641844962 +0000
+++ src/lib/fcitx-utils/uuid_p.h
@@ -21,7 +21,7 @@
 #endif
 
 #ifdef ENABLE_LIBUUID
-#include <uuid.h>
+#include <uuid/uuid.h>
 #endif
 
 namespace fcitx {
