$NetBSD: patch-installer_macosx_release-build-azure.sh,v 1.1 2020/10/10 14:02:37 mef Exp $

ERROR: [check-portability.awk]

--- installer/macosx/release-build-azure.sh.orig	2020-08-13 23:03:03.000000000 +0000
+++ installer/macosx/release-build-azure.sh
@@ -35,7 +35,7 @@ ls /usr/local/lib
 
 # sudo cp -a /Library/Frameworks/CsoundLib64.framework/libs/. $SYSTEM_DEFAULTWORKINGDIRECTORY/csoundLibs
 
-if [ $# == 0 ]; then
+if [ $# = 0 ]; then
   echo "Must give branch name to build from"
   exit
 else
