$NetBSD: patch-genfipsrclist.sh,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- genfipsrclist.sh.orig	2018-07-28 17:53:18.000000000 +0000
+++ genfipsrclist.sh
@@ -1,6 +1,6 @@
 #!/bin/sh
 
-DIRLIST=". Source Source/Metadata Source/FreeImageToolkit Source/LibJPEG Source/LibPNG Source/LibTIFF4 Source/ZLib Source/LibOpenJPEG Source/OpenEXR Source/OpenEXR/Half Source/OpenEXR/Iex Source/OpenEXR/IlmImf Source/OpenEXR/IlmThread Source/OpenEXR/Imath Source/OpenEXR/IexMath Source/LibRawLite Source/LibRawLite/dcraw Source/LibRawLite/internal Source/LibRawLite/libraw Source/LibRawLite/src Source/LibWebP Source/LibJXR Source/LibJXR/common/include Source/LibJXR/image/sys Source/LibJXR/jxrgluelib Wrapper/FreeImagePlus"
+DIRLIST="Wrapper/FreeImagePlus"
 
 
 echo "VER_MAJOR = 3" > fipMakefile.srcs
@@ -19,5 +19,6 @@ echo -n "INCLUDE =" >> fipMakefile.srcs
 for DIR in $DIRLIST; do
 	echo -n " -I$DIR" >> fipMakefile.srcs
 done
+echo -n " -IDist" >> fipMakefile.srcs
 echo >> fipMakefile.srcs
 
