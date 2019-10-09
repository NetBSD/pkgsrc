$NetBSD: patch-src_wayland_fg__internal__wl.h,v 1.1 2019/10/09 23:52:10 maya Exp $

<sys/joystick.h> should work for all netbsd.
(not all archs have a machine/joystick.h, and it just includes sys/joystick.h)

--- src/wayland/fg_internal_wl.h.orig	2015-04-04 18:43:27.000000000 +0000
+++ src/wayland/fg_internal_wl.h
@@ -105,17 +105,8 @@ struct tagSFG_PlatformWindowState
 /* XXX The below hack is done until freeglut's autoconf is updated. */
 #        define HAVE_USB_JS    1
 
-#        if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#        if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 #            include <sys/joystick.h>
-#        else
-/*
- * XXX NetBSD/amd64 systems may find that they have to steal the
- * XXX /usr/include/machine/joystick.h from a NetBSD/i386 system.
- * XXX I cannot comment whether that works for the interface, but
- * XXX it lets you compile...(^&  I do not think that we can do away
- * XXX with this header.
- */
-#            include <machine/joystick.h>         /* For analog joysticks */
 #        endif
 #        define JS_DATA_TYPE joystick
 #        define JS_RETURN (sizeof(struct JS_DATA_TYPE))
