$NetBSD: patch-src_gallium_winsys_radeon_drm_radeon__drm__winsys.c,v 1.1 2015/04/25 11:19:18 tnn Exp $

Don't create pipe thread on NetBSD. It triggers some kernel bug.
kern/49838.

--- src/gallium/winsys/radeon/drm/radeon_drm_winsys.c.orig	2015-03-28 18:20:39.000000000 +0000
+++ src/gallium/winsys/radeon/drm/radeon_drm_winsys.c
@@ -704,8 +704,10 @@ radeon_drm_winsys_create(int fd, radeon_
 
     ws->ncs = 0;
     pipe_semaphore_init(&ws->cs_queued, 0);
+#if !defined(__NetBSD__)
     if (ws->num_cpus > 1 && debug_get_option_thread())
         ws->thread = pipe_thread_create(radeon_drm_cs_emit_ioctl, ws);
+#endif
 
     /* Create the screen at the end. The winsys must be initialized
      * completely.
