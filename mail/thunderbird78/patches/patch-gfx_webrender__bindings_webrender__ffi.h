$NetBSD: patch-gfx_webrender__bindings_webrender__ffi.h,v 1.1 2023/02/05 08:32:24 he Exp $

Fix build with cbindgen > 0.23:
https://bugzilla.mozilla.org/show_bug.cgi?id=1773259

--- gfx/webrender_bindings/webrender_ffi.h.orig	2022-09-07 07:34:33.698723611 +0000
+++ gfx/webrender_bindings/webrender_ffi.h
@@ -78,8 +78,6 @@ struct WrPipelineInfo;
 struct WrPipelineIdAndEpoch;
 using WrPipelineIdEpochs = nsTArray<WrPipelineIdAndEpoch>;
 
-const uint64_t ROOT_CLIP_CHAIN = ~0;
-
 }  // namespace wr
 }  // namespace mozilla
 
