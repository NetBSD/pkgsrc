$NetBSD: patch-mozilla_gfx_thebes_gfxPlatform.cpp,v 1.1 2012/04/28 16:56:58 ryoon Exp $

--- mozilla/gfx/thebes/gfxPlatform.cpp.orig	2012-04-20 22:40:03.000000000 +0000
+++ mozilla/gfx/thebes/gfxPlatform.cpp
@@ -436,6 +436,7 @@ void SourceBufferDestroy(void *srcBuffer
   static_cast<SourceSurface*>(srcBuffer)->Release();
 }
 
+#ifdef MOZ_TREE_CAIRO
 void SourceSnapshotDetached(cairo_surface_t *nullSurf)
 {
   gfxImageSurface* origSurf =
@@ -443,6 +444,7 @@ void SourceSnapshotDetached(cairo_surfac
 
   origSurf->SetData(&kSourceSurface, NULL, NULL);
 }
+#endif
 
 RefPtr<SourceSurface>
 gfxPlatform::GetSourceSurfaceForSurface(DrawTarget *aTarget, gfxASurface *aSurface)
@@ -512,6 +514,7 @@ gfxPlatform::GetSourceSurfaceForSurface(
                                                      imgSurface->Stride(),
                                                      format);
 
+    #ifdef MOZ_TREE_CAIRO
     cairo_surface_t *nullSurf =
 	cairo_null_surface_create(CAIRO_CONTENT_COLOR_ALPHA);
     cairo_surface_set_user_data(nullSurf,
@@ -520,6 +523,7 @@ gfxPlatform::GetSourceSurfaceForSurface(
 				NULL);
     cairo_surface_attach_snapshot(imgSurface->CairoSurface(), nullSurf, SourceSnapshotDetached);
     cairo_surface_destroy(nullSurf);
+    #endif
   }
 
   srcBuffer->AddRef();
