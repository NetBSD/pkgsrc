$NetBSD: patch-aclocal.m4,v 1.1 2014/04/23 20:31:45 asau Exp $

--- aclocal.m4.orig	2014-04-23 08:57:37.216137000 +0000
+++ aclocal.m4
@@ -2301,7 +2301,7 @@ dgux*)
   shlibpath_var=LD_LIBRARY_PATH
   ;;
 
-freebsd1*)
+freebsd1|freebsd1.*)
   dynamic_linker=no
   ;;
 
@@ -2312,7 +2312,7 @@ freebsd* | dragonfly*)
     objformat=`/usr/bin/objformat`
   else
     case $host_os in
-    freebsd[[123]]*) objformat=aout ;;
+    freebsd[[123]]|freebsd[[123]].*) objformat=aout ;;
     *) objformat=elf ;;
     esac
   fi
@@ -4735,7 +4735,7 @@ _LT_EOF
       _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
       ;;
 
-    freebsd1*)
+    freebsd1|freebsd1.*)
       _LT_TAGVAR(ld_shlibs, $1)=no
       ;;
 
@@ -5693,7 +5693,7 @@ if test "$_lt_caught_CXX_error" != yes; 
         esac
         ;;
 
-      freebsd[[12]]*)
+      freebsd[[12]]|freebsd[[12]].*)
         # C++ shared libraries reported to be fairly broken before
 	# switch to ELF
         _LT_TAGVAR(ld_shlibs, $1)=no
