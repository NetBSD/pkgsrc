$NetBSD: patch-src_x11_fg__internal__x11.h,v 1.1 2019/10/21 09:38:08 maya Exp $

<sys/joystick.h> should work for all netbsd.
(not all archs have a machine/joystick.h, and it just includes sys/joystick.h)

--- src/x11/fg_internal_x11.h.orig	2014-10-20 15:27:04.000000000 +0000
+++ src/x11/fg_internal_x11.h
@@ -139,17 +139,8 @@ struct tagSFG_PlatformWindowState
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
