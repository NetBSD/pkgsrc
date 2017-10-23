$NetBSD: patch-OvmfPkg_build.sh,v 1.1 2017/10/23 14:21:57 maya Exp $

treat other operating systems as linux
invoke gmake, not make
Avoid GCC5 target tool due to errors appearing in the build

--- OvmfPkg/build.sh.orig	2017-06-13 08:26:05.000000000 +0000
+++ OvmfPkg/build.sh
@@ -80,7 +80,7 @@ case `uname` in
         ;;
     esac
     ;;
-  Linux*)
+  *)
     gcc_version=$(gcc -v 2>&1 | tail -1 | awk '{print $3}')
     case $gcc_version in
       [1-3].*|4.[0-3].*)
@@ -102,11 +102,8 @@ case `uname` in
       4.8.*)
         TARGET_TOOLS=GCC48
         ;;
-      4.9.*|6.[0-2].*)
-        TARGET_TOOLS=GCC49
-        ;;
       *)
-        TARGET_TOOLS=GCC5
+        TARGET_TOOLS=GCC49
         ;;
     esac
 esac
@@ -264,12 +261,12 @@ if  [[ ! -f `which build` || ! -f `which
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
