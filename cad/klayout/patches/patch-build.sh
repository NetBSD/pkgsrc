$NetBSD: patch-build.sh,v 1.1 2016/03/15 15:15:59 mef Exp $

Add NetBSD and FreeBSD

--- build.sh.orig	2016-02-27 07:20:29.000000000 +0900
+++ build.sh	2016-03-08 23:14:50.000000000 +0900
@@ -39,6 +39,12 @@ Darwin*)
   PLATFORM="mac-yosemite-gcc-release"
   EXEC_HOLDER="klayout.app/Contents/MacOS"
   ;;
+FreeBSD)
+  PLATFORM="freebsd-32-gcc-release"
+  ;;
+NetBSD)
+  PLATFORM="netbsd-32-gcc-release"
+  ;;
 *)
   # Assume Linux for the remaining variants
   case `arch` in
