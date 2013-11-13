$NetBSD: patch-mozilla_gfx_thebes_gfxPlatform.cpp,v 1.1 2013/11/13 13:27:45 ryoon Exp $

--- mozilla/gfx/thebes/gfxPlatform.cpp.orig	2012-08-25 00:31:09.000000000 +0000
+++ mozilla/gfx/thebes/gfxPlatform.cpp
@@ -443,6 +443,7 @@ void SourceBufferDestroy(void *srcBuffer
   static_cast<SourceSurface*>(srcBuffer)->Release();
 }
 
+#ifdef MOZ_TREE_CAIRO
 void SourceSnapshotDetached(cairo_surface_t *nullSurf)
 {
   gfxImageSurface* origSurf =
@@ -450,6 +451,7 @@ void SourceSnapshotDetached(cairo_surfac
 
   origSurf->SetData(&kSourceSurface, NULL, NULL);
 }
+#endif
 
 RefPtr<SourceSurface>
 gfxPlatform::GetSourceSurfaceForSurface(DrawTarget *aTarget, gfxASurface *aSurface)
@@ -544,6 +546,7 @@ gfxPlatform::GetSourceSurfaceForSurface(
 
     }
 
+    #ifdef MOZ_TREE_CAIRO
     cairo_surface_t *nullSurf =
 	cairo_null_surface_create(CAIRO_CONTENT_COLOR_ALPHA);
     cairo_surface_set_user_data(nullSurf,
@@ -552,6 +555,7 @@ gfxPlatform::GetSourceSurfaceForSurface(
                                 NULL);
     cairo_surface_attach_snapshot(imgSurface->CairoSurface(), nullSurf, SourceSnapshotDetached);
     cairo_surface_destroy(nullSurf);
+    #endif
   }
 
   srcBuffer->AddRef();
