$NetBSD: patch-OMXVideo.h,v 1.1 2015/01/18 23:09:25 jmcneill Exp $

Workaround for old misc/raspberrypi-userland package.

--- OMXVideo.h.orig	2015-01-12 15:10:50.000000000 +0000
+++ OMXVideo.h
@@ -35,6 +35,13 @@
 
 #define VIDEO_BUFFERS 60
 
+#ifdef OLD_RASPBERRYPI_USERLAND
+typedef int OMX_IMAGEFILTERANAGLYPHTYPE;
+#define OMX_ImageFilterAnaglyphNone 0
+#define OMX_ImageFilterDeInterlaceFast OMX_ImageFilterDeInterlaceLineDouble
+#define OMX_ImageFilterAnaglyph OMX_ImageFilterNone
+#endif
+
 enum EDEINTERLACEMODE
 {
   VS_DEINTERLACEMODE_OFF=0,
