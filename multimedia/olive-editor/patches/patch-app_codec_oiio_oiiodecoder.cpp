$NetBSD: patch-app_codec_oiio_oiiodecoder.cpp,v 1.1 2025/12/19 20:10:58 maya Exp $

Fix build with openimageio 3.x

From https://github.com/olive-editor/olive/pull/2393


--- app/codec/oiio/oiiodecoder.cpp.orig	2023-09-24 11:40:23.000000000 +0000
+++ app/codec/oiio/oiiodecoder.cpp
@@ -134,10 +134,18 @@ TexturePtr OIIODecoder::RetrieveVideoInt
 
     if (p.divider == 1) {
       // Just upload straight to the buffer
+#if OIIO_VERSION >= OIIO_MAKE_VERSION(3,0,0)
+      image_->read_image(0, 0, 0, -1, oiio_pix_fmt_, buffer_.data(), OIIO::AutoStride, buffer_.linesize_bytes());
+#else
       image_->read_image(oiio_pix_fmt_, buffer_.data(), OIIO::AutoStride, buffer_.linesize_bytes());
+#endif
     } else {
       OIIO::ImageBuf buf(image_->spec());
+#if OIIO_VERSION >= OIIO_MAKE_VERSION(3,0,0)
+      image_->read_image(0, 0, 0, -1, image_->spec().format, buf.localpixels(), buf.pixel_stride(), buf.scanline_stride(), buf.z_stride());
+#else
       image_->read_image(image_->spec().format, buf.localpixels(), buf.pixel_stride(), buf.scanline_stride(), buf.z_stride());
+#endif
 
       // Roughly downsample image for divider (for some reason OIIO::ImageBufAlgo::resample failed here)
       int px_sz = vp.GetBytesPerPixel();
