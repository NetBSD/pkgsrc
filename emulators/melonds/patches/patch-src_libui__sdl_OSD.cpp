$NetBSD: patch-src_libui__sdl_OSD.cpp,v 1.1 2019/12/22 22:25:21 joerg Exp $

--- src/libui_sdl/OSD.cpp.orig	2019-12-22 21:44:07.741122541 +0000
+++ src/libui_sdl/OSD.cpp
@@ -419,8 +419,8 @@ void Update(bool opengl, uiAreaDrawParam
                 item.DrawBitmapLoaded = true;
             }
 
-            uiRect rc_src = {0, 0, item.Width, item.Height};
-            uiRect rc_dst = {kOSDMargin, y, item.Width, item.Height};
+            uiRect rc_src = {0, 0, (int)item.Width, (int)item.Height};
+            uiRect rc_dst = {kOSDMargin, (int)y, (int)item.Width, (int)item.Height};
 
             uiDrawBitmapDraw(params->Context, item.DrawBitmap, &rc_src, &rc_dst, 0);
         }
