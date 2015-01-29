$NetBSD: patch-src_video_wscons_SDL__wsconsvideo.h,v 1.1 2015/01/29 01:56:23 jmcneill Exp $

--- src/video/wscons/SDL_wsconsvideo.h.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/video/wscons/SDL_wsconsvideo.h
@@ -50,6 +50,7 @@ typedef void WSCONS_bitBlit(Uint8 *src_p
 
 struct SDL_PrivateVideoData {
   int fd;                       /* file descriptor of open device */
+  int mouseFd;			/* file descriptor of open mouse device */
   struct wsdisplay_fbinfo info; /* frame buffer characteristics */
   int physlinebytes;            /* number of bytes per row */
   int redMask, greenMask, blueMask;
