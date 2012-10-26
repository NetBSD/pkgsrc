$NetBSD: patch-src_cairo-xlib-surface-shm.c,v 1.5 2012/10/26 21:49:23 wiz Exp $

Recognize Xorg servers as well as X.org servers. From Chris Wilson (upstream);
fixes some more firefox issues.

--- src/cairo-xlib-surface-shm.c.orig	2012-10-21 08:13:41.000000000 +0000
+++ src/cairo-xlib-surface-shm.c
@@ -1141,7 +1141,8 @@ xorg_has_buggy_send_shm_completion_event
      *
      * Remove the SendEvent bit (0x80) before doing range checks on event type.
      */
-    return (strstr (ServerVendor (dpy), "X.Org") != NULL &&
+    return ((strstr (ServerVendor (dpy), "X.Org") != NULL ||
+    		strstr (ServerVendor (dpy), "Xorg") != NULL ) &&
 	    VendorRelease (dpy) < XORG_VERSION_ENCODE(1,11,0,1));
 }
 
