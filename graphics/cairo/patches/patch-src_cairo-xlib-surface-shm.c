$NetBSD: patch-src_cairo-xlib-surface-shm.c,v 1.6 2012/10/30 23:30:19 wiz Exp $

Recognize Xorg servers as well as X.org servers. From Chris Wilson (upstream);
fixes some more firefox issues.

Also, handle old-style shm headers, also from upstream.

--- src/cairo-xlib-surface-shm.c.orig	2012-10-21 08:13:41.000000000 +0000
+++ src/cairo-xlib-surface-shm.c
@@ -41,17 +41,114 @@
 
 #include "cairo-xlib-private.h"
 #include "cairo-xlib-surface-private.h"
-#include "cairo-image-surface-private.h"
-#include "cairo-mempool-private.h"
+
+#if !HAVE_X11_EXTENSIONS_XSHM_H || !(HAVE_X11_EXTENSIONS_SHMPROTO_H || HAVE_X11_EXTENSIONS_SHMSTR_H)
+void _cairo_xlib_display_init_shm (cairo_xlib_display_t *display) {}
+
+cairo_surface_t *
+_cairo_xlib_surface_get_shm (cairo_xlib_surface_t *surface,
+			     cairo_bool_t overwrite)
+{
+    return NULL;
+}
+
+cairo_int_status_t
+_cairo_xlib_surface_put_shm (cairo_xlib_surface_t *surface)
+{
+    ASSERT_NOT_REACHED;
+    return CAIRO_INT_STATUS_SUCCESS;
+}
+
+cairo_surface_t *
+_cairo_xlib_surface_create_shm (cairo_xlib_surface_t *other,
+				pixman_format_code_t format,
+				int width, int height)
+{
+    return NULL;
+}
+
+cairo_surface_t *
+_cairo_xlib_surface_create_shm__image (cairo_xlib_surface_t *surface,
+				       pixman_format_code_t format,
+				       int width, int height)
+{
+    return NULL;
+}
+
+cairo_surface_t *
+_cairo_xlib_surface_create_similar_shm (void *other,
+					cairo_format_t format,
+					int width, int height)
+{
+    return cairo_image_surface_create (format, width, height);
+}
+
+void
+_cairo_xlib_shm_surface_mark_active (cairo_surface_t *_shm)
+{
+    ASSERT_NOT_REACHED;
+}
+
+void
+_cairo_xlib_shm_surface_get_ximage (cairo_surface_t *surface,
+				    XImage *ximage)
+{
+    ASSERT_NOT_REACHED;
+}
+
+void *
+_cairo_xlib_shm_surface_get_obdata (cairo_surface_t *surface)
+{
+    ASSERT_NOT_REACHED;
+    return NULL;
+}
+
+Pixmap
+_cairo_xlib_shm_surface_get_pixmap (cairo_surface_t *surface)
+{
+    ASSERT_NOT_REACHED;
+    return 0;
+}
+
+XRenderPictFormat *
+_cairo_xlib_shm_surface_get_xrender_format (cairo_surface_t *surface)
+{
+    ASSERT_NOT_REACHED;
+    return NULL;
+}
+
+cairo_bool_t
+_cairo_xlib_shm_surface_is_active (cairo_surface_t *surface)
+{
+    ASSERT_NOT_REACHED;
+    return FALSE;
+}
+
+cairo_bool_t
+_cairo_xlib_shm_surface_is_idle (cairo_surface_t *surface)
+{
+    ASSERT_NOT_REACHED;
+    return TRUE;
+}
+
+void _cairo_xlib_display_fini_shm (cairo_xlib_display_t *display) {}
+
+#else
 
 #include "cairo-damage-private.h"
 #include "cairo-default-context-private.h"
+#include "cairo-image-surface-private.h"
 #include "cairo-list-inline.h"
+#include "cairo-mempool-private.h"
 
 #include <X11/Xlibint.h>
 #include <X11/Xproto.h>
 #include <X11/extensions/XShm.h>
+#if HAVE_X11_EXTENSIONS_SHMPROTO_H
 #include <X11/extensions/shmproto.h>
+#elif HAVE_X11_EXTENSIONS_SHMSTR_H
+#include <X11/extensions/shmstr.h>
+#endif
 #include <sys/ipc.h>
 #include <sys/shm.h>
 
@@ -1141,7 +1238,8 @@ xorg_has_buggy_send_shm_completion_event
      *
      * Remove the SendEvent bit (0x80) before doing range checks on event type.
      */
-    return (strstr (ServerVendor (dpy), "X.Org") != NULL &&
+    return ((strstr (ServerVendor (dpy), "X.Org") != NULL ||
+    		strstr (ServerVendor (dpy), "Xorg") != NULL ) &&
 	    VendorRelease (dpy) < XORG_VERSION_ENCODE(1,11,0,1));
 }
 
@@ -1220,5 +1318,5 @@ _cairo_xlib_display_fini_shm (cairo_xlib
     free (shm);
     display->shm = NULL;
 }
-
+#endif
 #endif
