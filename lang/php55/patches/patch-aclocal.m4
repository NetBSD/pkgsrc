$NetBSD: patch-aclocal.m4,v 1.2 2014/07/26 00:11:55 taca Exp $

--- aclocal.m4.orig	2014-07-23 09:08:13.000000000 +0000
+++ aclocal.m4
@@ -4553,7 +4553,7 @@ freebsd* | dragonfly*)
     objformat=`/usr/bin/objformat`
   else
     case $host_os in
-    freebsd[[123]]*) objformat=aout ;;
+    freebsd[[123]]|freebsd[[123]].*) objformat=aout ;;
     *) objformat=elf ;;
     esac
   fi
@@ -6170,7 +6170,7 @@ case $host_os in
 	;;
     esac
     ;;
-  freebsd[[12]]*)
+  freebsd[[12]]|freebsd[[12]].*)
     # C++ shared libraries reported to be fairly broken before switch to ELF
     _LT_AC_TAGVAR(ld_shlibs, $1)=no
     ;;
