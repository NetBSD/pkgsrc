$NetBSD: patch-gfx_webrender__bindings_webrender__ffi.h,v 1.1 2022/11/03 22:18:41 gutteridge Exp $

Fix build with cbindgen > 0.23:
https://bugzilla.mozilla.org/show_bug.cgi?id=1773259

--- gfx/webrender_bindings/webrender_ffi.h.orig	2020-08-24 19:17:01.000000000 +0000
+++ gfx/webrender_bindings/webrender_ffi.h
@@ -71,8 +71,6 @@ struct WrWindowId;
 struct DocumentId;
 struct WrPipelineInfo;
 
-const uint64_t ROOT_CLIP_CHAIN = ~0;
-
 }  // namespace wr
 }  // namespace mozilla
 
