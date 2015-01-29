$NetBSD: patch-src_video_wscons_SDL__wsconsvideo.h,v 1.2 2015/01/29 11:28:50 jmcneill Exp $

--- src/video/wscons/SDL_wsconsvideo.h.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/video/wscons/SDL_wsconsvideo.h
@@ -50,6 +50,7 @@ typedef void WSCONS_bitBlit(Uint8 *src_p
 
 struct SDL_PrivateVideoData {
   int fd;                       /* file descriptor of open device */
+  int mouseFd;			/* file descriptor of open mouse device */
   struct wsdisplay_fbinfo info; /* frame buffer characteristics */
   int physlinebytes;            /* number of bytes per row */
   int redMask, greenMask, blueMask;
@@ -70,6 +71,7 @@ struct SDL_PrivateVideoData {
   unsigned int kbdType;
   int did_save_tty;
   struct termios saved_tty;
+  struct wskbd_keyrepeat_data saved_repeat;
 };
 
 
