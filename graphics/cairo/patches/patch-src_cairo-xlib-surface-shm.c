$NetBSD: patch-src_cairo-xlib-surface-shm.c,v 1.3 2012/10/20 00:55:07 wiz Exp $

First chunk:
Whilst reading through other users of XShm, it became apparent that
IPC_RMID behaves differently across the platforms. Linux allows
processes to attach to an existing ShmSegment id after a IPC_RMID, but
for others the IPC_RMID takes immediate effect. On those platforms
without a "deferred" IPC_RMID, we then need to perform the XShmAttach
synchronously before perfomring the IPC_RMID.
 
Reported-by: Thomas Klausner <wiz@NetBSD.org>
Signed-off-by: Chris Wilson <chris@chris-wilson.co.uk>

Rest:
Prevent application crashes under old version of X.org e.g. under
Mac OS X Lion. Patch taken from here:

http://cgit.freedesktop.org/cairo/commit/?id=b1532f465e05d566f6d160c5ca916a5a12614067

--- src/cairo-xlib-surface-shm.c.orig	2012-10-05 13:06:00.000000000 +0000
+++ src/cairo-xlib-surface-shm.c
@@ -449,6 +449,9 @@ _cairo_xlib_shm_pool_create(cairo_xlib_d
 
     pool->attached = NextRequest (dpy);
     success = XShmAttach (dpy, &pool->shm);
+#if !IPC_RMID_DEFERRED_RELEASE
+    XSync (dpy, FALSE);
+#endif
     shmctl (pool->shm.shmid, IPC_RMID, NULL);
 
     if (! success)
@@ -1121,6 +1124,24 @@ _cairo_xlib_shm_surface_is_idle (cairo_s
     return shm->idle > 0;
 }
 
+#define XORG_VERSION_ENCODE(major,minor,patch,snap) \
+    (((major) * 10000000) + ((minor) * 100000) + ((patch) * 1000) + snap)
+
+static cairo_bool_t
+xorg_has_buggy_send_event(Display *dpy)
+{
+    /* Avoid incurring the wrath fixed by:
+     *
+     * commit 2d2dce558d24eeea0eb011ec9ebaa6c5c2273c39
+     * Author: Sam Spilsbury <sam.spilsbury@canonical.com>
+     * Date:   Wed Sep 14 09:58:34 2011 +0800
+     *
+     * Remove the SendEvent bit (0x80) before doing range checks on event type.
+     */
+    return (strstr (ServerVendor (dpy), "X.Org") != NULL &&
+	    VendorRelease (dpy) < XORG_VERSION_ENCODE(1,11,0,1));
+}
+
 void
 _cairo_xlib_display_init_shm (cairo_xlib_display_t *display)
 {
@@ -1153,6 +1174,9 @@ _cairo_xlib_display_init_shm (cairo_xlib
 				 DefaultVisual (display->display, scr),
 				 CWOverrideRedirect, &attr);
 
+    if (xorg_has_buggy_send_event(display->display))
+	has_pixmap = 0;
+
     shm->has_pixmaps = has_pixmap ? MIN_PIXMAP_SIZE : 0;
     cairo_list_init (&shm->pool);
 
