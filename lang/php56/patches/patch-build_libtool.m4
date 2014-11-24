$NetBSD: patch-build_libtool.m4,v 1.1 2014/11/24 15:37:08 taca Exp $

--- build/libtool.m4.orig	2014-11-12 13:52:21.000000000 +0000
+++ build/libtool.m4
@@ -1545,7 +1545,7 @@ freebsd* | dragonfly*)
     objformat=`/usr/bin/objformat`
   else
     case $host_os in
-    freebsd[[123]]*) objformat=aout ;;
+    freebsd[[123]]|freebsd[[123]].*) objformat=aout ;;
     *) objformat=elf ;;
     esac
   fi
@@ -3162,7 +3162,7 @@ case $host_os in
 	;;
     esac
     ;;
-  freebsd[[12]]*)
+  freebsd[[12]]|freebsd[[12]].*)
     # C++ shared libraries reported to be fairly broken before switch to ELF
     _LT_AC_TAGVAR(ld_shlibs, $1)=no
     ;;
