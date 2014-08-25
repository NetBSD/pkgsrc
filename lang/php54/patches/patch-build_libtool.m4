$NetBSD: patch-build_libtool.m4,v 1.1.4.1 2014/08/25 15:59:27 tron Exp $

--- build/libtool.m4.orig	2014-07-23 00:59:30.000000000 +0000
+++ build/libtool.m4
@@ -1539,7 +1539,7 @@ freebsd* | dragonfly*)
     objformat=`/usr/bin/objformat`
   else
     case $host_os in
-    freebsd[[123]]*) objformat=aout ;;
+    freebsd[[123]]|freebsd[[123]].*) objformat=aout ;;
     *) objformat=elf ;;
     esac
   fi
@@ -3155,7 +3155,7 @@ case $host_os in
 	;;
     esac
     ;;
-  freebsd[[12]]*)
+  freebsd[[12]]|freebsd[[12]].*)
     # C++ shared libraries reported to be fairly broken before switch to ELF
     _LT_AC_TAGVAR(ld_shlibs, $1)=no
     ;;
