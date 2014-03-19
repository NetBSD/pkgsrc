$NetBSD: patch-build_libtool.m4,v 1.1 2014/03/19 21:50:23 asau Exp $

--- build/libtool.m4.orig	2014-03-05 08:07:14.000000000 +0000
+++ build/libtool.m4
@@ -1532,7 +1532,7 @@ dgux*)
   shlibpath_var=LD_LIBRARY_PATH
   ;;
 
-freebsd1*)
+freebsd1|freebsd1.*)
   dynamic_linker=no
   ;;
 
@@ -1543,7 +1543,7 @@ freebsd* | dragonfly*)
     objformat=`/usr/bin/objformat`
   else
     case $host_os in
-    freebsd[[123]]*) objformat=aout ;;
+    freebsd[[123]]|freebsd[[123]].*) objformat=aout ;;
     *) objformat=elf ;;
     esac
   fi
@@ -3159,7 +3159,7 @@ case $host_os in
 	;;
     esac
     ;;
-  freebsd[[12]]*)
+  freebsd[[12]]|freebsd[[12]].*)
     # C++ shared libraries reported to be fairly broken before switch to ELF
     _LT_AC_TAGVAR(ld_shlibs, $1)=no
     ;;
@@ -5842,7 +5842,7 @@ _LT_EOF
       _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
       ;;
 
-    freebsd1*)
+    freebsd1|freebsd1.*)
       _LT_AC_TAGVAR(ld_shlibs, $1)=no
       ;;
 
