$NetBSD: patch-libraries_source_spidermonkey_build.sh,v 1.1 2023/05/04 15:20:52 nikita Exp $


--- libraries/source/spidermonkey/build.sh.orig	2023-05-03 20:04:57.672955809 +0200
+++ libraries/source/spidermonkey/build.sh	2023-05-03 20:06:29.174827445 +0200
@@ -51,12 +51,12 @@
 then
   ARCH=${ARCH:=""}
   if [ -z "${ARCH}" ]; then
-    if [ "`uname -m`" == "arm64" ]; then
+    if [ "`uname -m`" = "arm64" ]; then
       ARCH="aarch64"
     else
       ARCH="x86_64"
     fi
-  elif [ $ARCH == "arm64"  ]; then
+  elif [ $ARCH = "arm64"  ]; then
     # SM78 doesn't know about arm64 yet, and that's passed by build-osx-libs.sh, so fix it explicitly.
     ARCH="aarch64"
   fi
