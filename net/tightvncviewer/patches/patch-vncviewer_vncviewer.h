$NetBSD: patch-vncviewer_vncviewer.h,v 1.1 2025/10/12 22:35:32 mrg Exp $

Add missing prototypes.


--- vncviewer/vncviewer.h.orig	2006-12-05 03:12:42.000000000 -0800
+++ vncviewer/vncviewer.h	2025-10-12 15:29:12.058216143 -0700
@@ -140,6 +140,8 @@ extern void SetVisualAndCmap();
 
 extern Bool HandleCursorShape(int xhot, int yhot, int width, int height,
                               CARD32 enc);
+extern Bool HandleXCursor(int xhot, int yhot, int width, int height);
+extern Bool HandleCursorPos(int x, int y);
 extern void SoftCursorLockArea(int x, int y, int w, int h);
 extern void SoftCursorUnlockScreen(void);
 extern void SoftCursorMove(int x, int y);
