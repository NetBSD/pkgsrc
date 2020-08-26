$NetBSD: patch-backends_oss_oss-backend.c,v 1.1 2020/08/26 21:22:13 jmcneill Exp $

Fix for https://github.com/mate-desktop/libmatemixer/issues/28

--- backends/oss/oss-backend.c.orig	2020-02-10 11:18:28.000000000 +0000
+++ backends/oss/oss-backend.c
@@ -61,7 +61,7 @@ static void oss_backend_finalize       (
 
 #pragma clang diagnostic push
 #pragma clang diagnostic ignored "-Wunused-function"
-G_DEFINE_DYNAMIC_TYPE_EXTENDED (OssBackend, oss_backend, MATE_MIXER_TYPE_BACKEND, 0, G_ADD_PRIVATE (OssBackend))
+G_DEFINE_DYNAMIC_TYPE_EXTENDED (OssBackend, oss_backend, MATE_MIXER_TYPE_BACKEND, 0, G_ADD_PRIVATE_DYNAMIC (OssBackend))
 #pragma clang diagnostic pop
 
 static gboolean     oss_backend_open             (MateMixerBackend *backend);
