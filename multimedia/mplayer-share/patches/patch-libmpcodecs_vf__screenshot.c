$NetBSD: patch-libmpcodecs_vf__screenshot.c,v 1.1 2018/04/04 11:02:07 triaxx Exp $

Fix crash with screenshot filter.
From upstream r37875.

--- libmpcodecs/vf_screenshot.c.orig	2016-02-14 20:36:28.000000000 +0000
+++ libmpcodecs/vf_screenshot.c
@@ -81,6 +81,8 @@ static int config(struct vf_instance *vf
         vf->priv->avctx->pix_fmt = AV_PIX_FMT_RGB24;
         vf->priv->avctx->width = d_width;
         vf->priv->avctx->height = d_height;
+        vf->priv->avctx->time_base.num = 1;
+        vf->priv->avctx->time_base.den = 1;
         vf->priv->avctx->compression_level = 0;
         if (avcodec_open2(vf->priv->avctx, avcodec_find_encoder(AV_CODEC_ID_PNG), NULL)) {
             mp_msg(MSGT_VFILTER, MSGL_FATAL, "Could not open libavcodec PNG encoder\n");
