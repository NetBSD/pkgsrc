$NetBSD: patch-EmulatorPkg_build.sh,v 1.1 2017/10/23 14:21:57 maya Exp $

treat other operating systems as linux
invoke gmake, not make

--- EmulatorPkg/build.sh.orig	2017-06-13 08:26:05.000000000 +0000
+++ EmulatorPkg/build.sh
@@ -78,7 +78,7 @@ case `uname` in
       BUILD_NEW_SHELL="-D BUILD_NEW_SHELL"
       BUILD_FAT="-D BUILD_FAT"
       ;;
-  Linux*)
+  *)
     case `uname -m` in
       i386)
         HOST_PROCESSOR=IA32
@@ -206,12 +206,12 @@ if  [[ ! -f `which build` || ! -f `which
 then
   # build the tools if they don't yet exist. Bin scheme
   echo Building tools as they are not in the path
-  make -C $WORKSPACE/BaseTools
+  gmake -C $WORKSPACE/BaseTools
 elif [[ ( -f `which build` ||  -f `which GenFv` )  && ! -d  $EDK_TOOLS_PATH/Source/C/bin ]];
 then
   # build the tools if they don't yet exist. BinWrapper scheme
   echo Building tools no $EDK_TOOLS_PATH/Source/C/bin directory
-  make -C $WORKSPACE/BaseTools
+  gmake -C $WORKSPACE/BaseTools
 else
   echo using prebuilt tools
 fi
