$NetBSD: patch-src_gallium_drivers_nouveau_nouveau__vp3__video.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

Fix build on platforms without close-on-exec.

--- src/gallium/drivers/nouveau/nouveau_vp3_video.c.orig	2017-02-13 11:55:49.000000000 +0000
+++ src/gallium/drivers/nouveau/nouveau_vp3_video.c
@@ -294,7 +294,11 @@ nouveau_vp3_load_firmware(struct nouveau
    if (nouveau_bo_map(dec->fw_bo, NOUVEAU_BO_WR, dec->client))
       return 1;
 
+#ifdef O_CLOEXEC
    fd = open(path, O_RDONLY | O_CLOEXEC);
+#else
+   fd = open(path, O_RDONLY);
+#endif
    if (fd < 0) {
       fprintf(stderr, "opening firmware file %s failed: %m\n", path);
       return 1;
