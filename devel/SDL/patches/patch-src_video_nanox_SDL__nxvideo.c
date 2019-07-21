$NetBSD: patch-src_video_nanox_SDL__nxvideo.c,v 1.1 2019/07/21 11:14:38 nia Exp $

CVE-2019-7637: Fix in integer overflow in SDL_CalculatePitch
From https://hg.libsdl.org/SDL/rev/9b0e5c555c0f

--- src/video/nanox/SDL_nxvideo.c.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/video/nanox/SDL_nxvideo.c
@@ -378,6 +378,10 @@ SDL_Surface * NX_SetVideoMode (_THIS, SD
         current -> w = width ;
         current -> h = height ;
         current -> pitch = SDL_CalculatePitch (current) ;
+        if (!current->pitch) {
+            current = NULL;
+            goto done;
+        }
         NX_ResizeImage (this, current, flags) ;
     }
 
