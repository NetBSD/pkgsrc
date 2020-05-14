$NetBSD: patch-gensrclist.sh,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- gensrclist.sh.orig	2018-07-28 17:52:50.000000000 +0000
+++ gensrclist.sh
@@ -1,6 +1,6 @@
 #!/bin/sh
 
-DIRLIST=". Source Source/Metadata Source/FreeImageToolkit Source/LibJPEG Source/LibPNG Source/LibTIFF4 Source/ZLib Source/LibOpenJPEG Source/OpenEXR Source/OpenEXR/Half Source/OpenEXR/Iex Source/OpenEXR/IlmImf Source/OpenEXR/IlmThread Source/OpenEXR/Imath Source/OpenEXR/IexMath Source/LibRawLite Source/LibRawLite/dcraw Source/LibRawLite/internal Source/LibRawLite/libraw Source/LibRawLite/src Source/LibWebP Source/LibJXR Source/LibJXR/common/include Source/LibJXR/image/sys Source/LibJXR/jxrgluelib"
+DIRLIST=". Source Source/Metadata Source/FreeImageToolkit"
 
 echo "VER_MAJOR = 3" > Makefile.srcs
 echo "VER_MINOR = 18.0" >> Makefile.srcs
