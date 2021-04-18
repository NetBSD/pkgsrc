$NetBSD: patch-tools_libxl_libxl_dom.c,v 1.1 2021/04/18 12:31:26 bouyer Exp $

--- tools/libs/light/libxl_dom.c.orig	2020-12-08 15:28:31.000000000 +0100
+++ tools/libs/light/libxl_dom.c	2020-12-09 15:59:56.104509990 +0100
@@ -1228,7 +1228,7 @@
         goto out;
     }
     uuid_string = GCSPRINTF(LIBXL_UUID_FMT, LIBXL_UUID_BYTES(info.uuid));
-    path = GCSPRINTF(XEN_LIB_DIR "/userdata-%s.%u.%s.%s",
+    path = GCSPRINTF(XEN_RUN_DIR "/userdata-%s.%u.%s.%s",
                      wh, domid, uuid_string, userdata_userid);
 
  out:
