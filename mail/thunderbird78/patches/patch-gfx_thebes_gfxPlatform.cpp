$NetBSD: patch-gfx_thebes_gfxPlatform.cpp,v 1.1 2023/02/05 08:32:24 he Exp $

--- gfx/thebes/gfxPlatform.cpp.orig	2020-08-28 21:32:36.000000000 +0000
+++ gfx/thebes/gfxPlatform.cpp
@@ -2927,6 +2927,10 @@ bool gfxPlatform::UsesOffMainThreadCompo
 }
 
 bool gfxPlatform::UsesTiling() const {
+#ifdef __NetBSD__
+  // Avoid relying on CrossProcessSemaphore
+  return true;
+#else
   bool usesSkia = GetDefaultContentBackend() == BackendType::SKIA;
 
   // We can't just test whether the PaintThread is initialized here because
@@ -2939,6 +2943,7 @@ bool gfxPlatform::UsesTiling() const {
   return StaticPrefs::layers_enable_tiles_AtStartup() ||
          (StaticPrefs::layers_enable_tiles_if_skia_pomtp_AtStartup() &&
           usesSkia && usesPOMTP);
+#endif
 }
 
 bool gfxPlatform::ContentUsesTiling() const {
