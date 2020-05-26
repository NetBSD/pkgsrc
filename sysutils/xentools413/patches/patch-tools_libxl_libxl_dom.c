$NetBSD: patch-tools_libxl_libxl_dom.c,v 1.1 2020/05/26 11:12:11 bouyer Exp $

--- tools/libxl/libxl_dom.c.orig
+++ tools/libxl/libxl_dom.c
@@ -1361,7 +1361,7 @@ const char *libxl__userdata_path(libxl__gc *gc, uint32_t domid,
         goto out;
     }
     uuid_string = GCSPRINTF(LIBXL_UUID_FMT, LIBXL_UUID_BYTES(info.uuid));
-    path = GCSPRINTF(XEN_LIB_DIR "/userdata-%s.%u.%s.%s",
+    path = GCSPRINTF(XEN_RUN_DIR "/userdata-%s.%u.%s.%s",
                      wh, domid, uuid_string, userdata_userid);
 
  out:
