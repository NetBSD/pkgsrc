$NetBSD: patch-src_gallium_winsys_svga_drm_vmw__screen__ioctl.c,v 1.5 2020/03/08 10:35:03 tnn Exp $

conditionalise Linuxism

--- src/gallium/winsys/svga/drm/vmw_screen_ioctl.c.orig	2020-03-05 21:34:31.000000000 +0000
+++ src/gallium/winsys/svga/drm/vmw_screen_ioctl.c
@@ -694,7 +694,9 @@ vmw_ioctl_region_map(struct vmw_region *
 	 return NULL;
       }
 
+#ifdef MADV_HUGEPAGE
       (void) madvise(map, region->size, MADV_HUGEPAGE);
+#endif
       region->data = map;
    }
 
