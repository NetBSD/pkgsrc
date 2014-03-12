$NetBSD: patch-aclocal.m4,v 1.1 2014/03/12 19:52:04 asau Exp $

--- aclocal.m4.orig	2013-12-10 20:13:10.000000000 +0000
+++ aclocal.m4
@@ -4424,7 +4424,7 @@ dgux*)
   shlibpath_var=LD_LIBRARY_PATH
   ;;
 
-freebsd1*)
+freebsd1|freebsd1.*)
   dynamic_linker=no
   ;;
 
@@ -4435,7 +4435,7 @@ freebsd* | dragonfly*)
     objformat=`/usr/bin/objformat`
   else
     case $host_os in
-    freebsd[[123]]*) objformat=aout ;;
+    freebsd[[123]]|freebsd[[123]].*) objformat=aout ;;
     *) objformat=elf ;;
     esac
   fi
@@ -6051,7 +6051,7 @@ case $host_os in
 	;;
     esac
     ;;
-  freebsd[[12]]*)
+  freebsd[[12]]|freebsd[[12]].*)
     # C++ shared libraries reported to be fairly broken before switch to ELF
     _LT_AC_TAGVAR(ld_shlibs, $1)=no
     ;;
@@ -8734,7 +8734,7 @@ _LT_EOF
       _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
       ;;
 
-    freebsd1*)
+    freebsd1|freebsd1.*)
       _LT_AC_TAGVAR(ld_shlibs, $1)=no
       ;;
 
