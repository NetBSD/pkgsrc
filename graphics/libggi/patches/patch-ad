$NetBSD: patch-ad,v 1.3 2007/03/16 22:28:56 joerg Exp $

--- display/vgl/mode.c.orig	2007-03-16 22:04:49.000000000 +0000
+++ display/vgl/mode.c
@@ -25,6 +25,10 @@
 ******************************************************************************
 */
 
+#if defined(__DragonFly__)
+#include <sys/param.h>
+#endif
+
 #include <sys/ioccom.h>
 
 #include <stdio.h>
@@ -129,8 +133,10 @@ int GGI_vgl_setmode(ggi_visual *vis, ggi
 	/* XXX should be in VGL */
 	if ((modeinfo.vi_mode >= M_B40x25) && (modeinfo.vi_mode <= M_VGA_M90x60))
 		modenum = _IO('S', modeinfo.vi_mode);
+#if !(defined(__DragonFly__) && __DragonFly_version >= 180000)
 	if ((modeinfo.vi_mode >= M_TEXT_80x25) && (modeinfo.vi_mode <= M_TEXT_132x60))
 		modenum = _IO('S', modeinfo.vi_mode);
+#endif
 	if ((modeinfo.vi_mode >= M_VESA_CG640x400) &&
 		(modeinfo.vi_mode <= M_VESA_FULL_1280))
 		modenum = _IO('V', modeinfo.vi_mode - M_VESA_BASE);
