$NetBSD: patch-lib_extras_dec_pnm.cc,v 1.1 2026/06/01 14:14:20 wiz Exp $

Fix CVE-2025-70103
https://github.com/libjxl/libjxl/commit/49fb89f23473e57fa1dac416adce7c7679e5d051

--- lib/extras/dec/pnm.cc.orig	2026-02-10 13:53:22.000000000 +0000
+++ lib/extras/dec/pnm.cc
@@ -497,13 +497,26 @@ Status DecodeImagePNM(const Span<const uint8_t> bytes,
     }
   }
 
+  // No align - pixels are tightly packed.
+  constexpr size_t kAlign = 0;
+  size_t twidth = PackedImage::BitsPerChannel(data_type) / 8;
   const JxlPixelFormat format{
       /*num_channels=*/num_interleaved_channels,
       /*data_type=*/data_type,
       /*endianness=*/header.big_endian ? JXL_BIG_ENDIAN : JXL_LITTLE_ENDIAN,
-      /*align=*/0,
+      kAlign,
   };
-  const JxlPixelFormat ec_format{1, format.data_type, format.endianness, 0};
+  // EC format is same as color, but 1-channel.
+  JxlPixelFormat ec_format = format;
+  ec_format.num_channels = 1;
+  size_t required_pnm_size =
+      header.ysize * header.xsize *
+      (num_interleaved_channels + header.ec_types.size()) * twidth;
+  size_t pnm_remaining_size = bytes.data() + bytes.size() - pos;
+  if (pnm_remaining_size < required_pnm_size) {
+    return JXL_FAILURE("PNM file too small");
+  }
+
   ppf->frames.clear();
   {
     JXL_ASSIGN_OR_RETURN(
@@ -512,42 +525,47 @@ Status DecodeImagePNM(const Span<const uint8_t> bytes,
     ppf->frames.emplace_back(std::move(frame));
   }
   auto* frame = &ppf->frames.back();
+  uint8_t* out = reinterpret_cast<uint8_t*>(frame->color.pixels());
+  std::vector<uint8_t*> ec_out;
   for (size_t i = 0; i < header.ec_types.size(); ++i) {
     JXL_ASSIGN_OR_RETURN(
         PackedImage ec,
         PackedImage::Create(header.xsize, header.ysize, ec_format));
     frame->extra_channels.emplace_back(std::move(ec));
+    ec_out.emplace_back(
+        reinterpret_cast<uint8_t*>(frame->extra_channels.back().pixels()));
+    JXL_DASSERT(frame->extra_channels.back().stride == header.xsize * twidth);
   }
-  size_t pnm_remaining_size = bytes.data() + bytes.size() - pos;
-  if (pnm_remaining_size < frame->color.pixels_size) {
-    return JXL_FAILURE("PNM file too small");
-  }
-
-  uint8_t* out = reinterpret_cast<uint8_t*>(frame->color.pixels());
-  std::vector<uint8_t*> ec_out(header.ec_types.size());
-  for (size_t i = 0; i < ec_out.size(); ++i) {
-    ec_out[i] = reinterpret_cast<uint8_t*>(frame->extra_channels[i].pixels());
-  }
+  JXL_DASSERT(frame->color.stride ==
+              header.xsize * num_interleaved_channels * twidth);
   if (ec_out.empty()) {
-    const bool flipped_y = header.bits_per_sample == 32;  // PFMs are flipped
-    for (size_t y = 0; y < header.ysize; ++y) {
-      size_t y_in = flipped_y ? header.ysize - 1 - y : y;
-      const uint8_t* row_in = &pos[y_in * frame->color.stride];
-      uint8_t* row_out = &out[y * frame->color.stride];
-      memcpy(row_out, row_in, frame->color.stride);
+    const bool flipped_y = (header.bits_per_sample == 32);  // PFMs are flipped
+    if (!flipped_y) {
+    // When there are no EC and input is not flipped we can copy the whole
+    // image at once.
+      memcpy(out, pos, header.ysize * frame->color.stride);
+    } else {
+      // Otherwise copy row-by-row.
+      for (size_t y = 0; y < header.ysize; ++y) {
+        size_t y_out = header.ysize - 1 - y;
+        const uint8_t* row_in = pos + y * frame->color.stride;
+        uint8_t* row_out = out + y_out * frame->color.stride;
+        memcpy(row_out, row_in, frame->color.stride);
+      }
     }
   } else {
+    // In case there are EC, we have to deinterleave data pixel-wise.
     JXL_RETURN_IF_ERROR(PackedImage::ValidateDataType(data_type));
-    size_t pwidth = PackedImage::BitsPerChannel(data_type) / 8;
+    size_t color_stride = twidth * num_interleaved_channels;
     for (size_t y = 0; y < header.ysize; ++y) {
       for (size_t x = 0; x < header.xsize; ++x) {
         memcpy(out, pos, frame->color.pixel_stride());
-        out += frame->color.pixel_stride();
-        pos += frame->color.pixel_stride();
+        out += color_stride;
+        pos += color_stride;
         for (auto& p : ec_out) {
-          memcpy(p, pos, pwidth);
-          pos += pwidth;
-          p += pwidth;
+          memcpy(p, pos, twidth);
+          pos += twidth;
+          p += twidth;
         }
       }
     }
