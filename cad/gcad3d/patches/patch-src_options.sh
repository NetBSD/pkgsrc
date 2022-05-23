$NetBSD: patch-src_options.sh,v 1.1 2022/05/23 19:10:03 plunky Exp $

1. active directory won't be that, since we got the source for github
2. ease installation by not using an osname subdirectory

--- src/options.sh.orig	2022-03-04 12:26:39.000000000 +0000
+++ src/options.sh
@@ -23,12 +23,6 @@
 
 
 
-# test if active directory is xx/gcad3d/src/APP
-S2=`expr length ${PWD} - 14`
-if [ `echo ${PWD} | cut -c$S2-` != "/gcad3d/src/APP" ] ; then
-  echo "****** ERROR - not in directory .../gcad3d/src/APP *****"
-  exit 1;
-fi
 
 
 
@@ -55,7 +49,7 @@
 export gcad_dir_dev=${DIR_DEV}gcad3d/
 
 # gcad_dir_bin      home of objects, executables, libraries
-export gcad_dir_bin=${DIR_BIN}gcad3d/${hTyp}/
+export gcad_dir_bin=${DIR_BIN}gcad3d/
 
 
 
