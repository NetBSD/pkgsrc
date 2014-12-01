$NetBSD: patch-storage_ndb_mcc_frontend_dojo_dojox_mobile_build_build.sh,v 1.1.1.1 2014/12/01 05:58:03 jnemeth Exp $

--- storage/ndb/mcc/frontend/dojo/dojox/mobile/build/build.sh.orig	2014-04-01 16:04:34.000000000 +0000
+++ storage/ndb/mcc/frontend/dojo/dojox/mobile/build/build.sh
@@ -16,14 +16,14 @@ profile=mobile
 dir=release-mobile-separate
 webkit=
 #standalone=standaloneScrollable=true
-if [ "$1" == "single" ]; then
+if [ "$1" = "single" ]; then
   profile=mobile-all
 fi
-if [ "$1" == "single" ]; then
+if [ "$1" = "single" ]; then
   dir=release-mobile-single
 fi
 shift 1
-if [ "$1" == "webkit" ]; then
+if [ "$1" = "webkit" ]; then
   webkit=webkitMobile=true
   shift 1
 fi
