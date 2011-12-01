$NetBSD: patch-src_video_wscons_SDL__wsconsevents.c,v 1.1 2011/12/01 10:48:08 wiz Exp $

"Port" to NetBSD.

--- src/video/wscons/SDL_wsconsevents.c.orig	2009-10-12 23:07:14.000000000 +0000
+++ src/video/wscons/SDL_wsconsevents.c
@@ -146,8 +146,12 @@ void WSCONS_InitOSKeymap(_THIS)
   }
 
   switch (private->kbdType) {
-#ifdef WSKBD_TYPE_ZAURUS
+#if defined(WSKBD_TYPE_ZAURUS) || defined(__NetBSD__)
+#if defined(__NetBSD)
+  case default:
+#else
   case WSKBD_TYPE_ZAURUS:
+#endif
     /* top row */
     keymap[2] = SDLK_1;
     keymap[3] = SDLK_2;
@@ -222,10 +226,12 @@ void WSCONS_InitOSKeymap(_THIS)
     break;
 #endif /* WSKBD_TYPE_ZAURUS */
 
+#ifndef __NetBSD__
   default:
     WSCONS_ReportError("Unable to map keys for keyboard type %u", 
 		       private->kbdType);
     break;
+#endif
   }
 }
 
