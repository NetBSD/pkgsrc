$NetBSD: patch-gfx_thebes_gfxPlatform.cpp,v 1.1 2020/06/15 15:44:22 nia Exp $

Don't rely on CrossProcessSemaphore on NetBSD. It has some implementation
issues that cause issues (kern/55386, not available on NetBSD<9)

This idea is borrowed from macOS which has the same limitation.

--- gfx/thebes/gfxPlatform.cpp.orig	2020-06-02 14:07:53.000000000 +0000
+++ gfx/thebes/gfxPlatform.cpp
@@ -2991,6 +2991,9 @@ bool gfxPlatform::UsesOffMainThreadCompo
 }
 
 bool gfxPlatform::UsesTiling() const {
+#ifdef __NetBSD__
+  return true;
+#else
   bool usesSkia = GetDefaultContentBackend() == BackendType::SKIA;
 
   // We can't just test whether the PaintThread is initialized here because
@@ -3002,6 +3005,7 @@ bool gfxPlatform::UsesTiling() const {
 
   return gfxPrefs::LayersTilesEnabled() ||
          (gfxPrefs::LayersTilesEnabledIfSkiaPOMTP() && usesSkia && usesPOMTP);
+#endif
 }
 
 bool gfxPlatform::ContentUsesTiling() const {
