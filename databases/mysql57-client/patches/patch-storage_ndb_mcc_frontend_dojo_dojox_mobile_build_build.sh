$NetBSD: patch-storage_ndb_mcc_frontend_dojo_dojox_mobile_build_build.sh,v 1.1 2016/09/16 06:49:11 adam Exp $

Portability.

--- storage/ndb/mcc/frontend/dojo/dojox/mobile/build/build.sh.orig	2016-03-28 18:06:12.000000000 +0000
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
