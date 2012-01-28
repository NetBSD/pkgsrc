$NetBSD: patch-src_video_wscons_SDL__wsconsevents.c,v 1.4 2012/01/28 10:33:31 wiz Exp $

"Port" to NetBSD.

--- src/video/wscons/SDL_wsconsevents.c.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/video/wscons/SDL_wsconsevents.c
@@ -146,8 +146,11 @@ void WSCONS_InitOSKeymap(_THIS)
   }
 
   switch (private->kbdType) {
-#ifdef WSKBD_TYPE_ZAURUS
+#if defined(__NetBSD__) || !defined(WSKBD_TYPE_ZAURUS)
+  default:
+#else
   case WSKBD_TYPE_ZAURUS:
+#endif
     /* top row */
     keymap[2] = SDLK_1;
     keymap[3] = SDLK_2;
@@ -220,12 +223,13 @@ void WSCONS_InitOSKeymap(_THIS)
     keymap[77] = SDLK_RIGHT;
     keymap[80] = SDLK_DOWN;
     break;
-#endif /* WSKBD_TYPE_ZAURUS */
 
+#if !defined(__NetBSD__) && defined(WSKBD_TYPE_ZAURUS)
   default:
     WSCONS_ReportError("Unable to map keys for keyboard type %u", 
 		       private->kbdType);
     break;
+#endif
   }
 }
 
