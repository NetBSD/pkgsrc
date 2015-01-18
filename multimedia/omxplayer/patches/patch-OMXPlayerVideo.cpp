$NetBSD: patch-OMXPlayerVideo.cpp,v 1.1 2015/01/18 23:09:25 jmcneill Exp $

Workaround for old misc/raspberrypi-userland package.

--- OMXPlayerVideo.cpp.orig	2015-01-12 15:10:50.000000000 +0000
+++ OMXPlayerVideo.cpp
@@ -25,6 +25,13 @@
 #include "system.h"
 #endif
 
+#ifdef OLD_RASPBERRYPI_USERLAND
+typedef int OMX_IMAGEFILTERANAGLYPHTYPE;
+#define OMX_ImageFilterAnaglyphNone 0
+#define OMX_ImageFilterDeInterlaceFast OMX_ImageFilterDeInterlaceLineDouble
+#define OMX_ImageFilterAnaglyph OMX_ImageFilterNone
+#endif
+
 #include "OMXPlayerVideo.h"
 
 #include <stdio.h>
