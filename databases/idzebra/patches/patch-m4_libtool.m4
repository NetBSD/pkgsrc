$NetBSD: patch-m4_libtool.m4,v 1.1 2014/04/22 14:45:32 asau Exp $

--- m4/libtool.m4.orig	2009-12-09 21:05:27.000000000 +0000
+++ m4/libtool.m4
@@ -2286,7 +2286,7 @@ dgux*)
   shlibpath_var=LD_LIBRARY_PATH
   ;;
 
-freebsd1*)
+freebsd1|freebsd1.*)
   dynamic_linker=no
   ;;
 
@@ -2297,7 +2297,7 @@ freebsd* | dragonfly*)
     objformat=`/usr/bin/objformat`
   else
     case $host_os in
-    freebsd[[123]]*) objformat=aout ;;
+    freebsd[[123]]|freebsd[[123]].*) objformat=aout ;;
     *) objformat=elf ;;
     esac
   fi
@@ -4724,7 +4724,7 @@ _LT_EOF
       _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
       ;;
 
-    freebsd1*)
+    freebsd1|freebsd1.*)
       _LT_TAGVAR(ld_shlibs, $1)=no
       ;;
 
@@ -5686,7 +5686,7 @@ if test "$_lt_caught_CXX_error" != yes; 
         esac
         ;;
 
-      freebsd[[12]]*)
+      freebsd[[12]]|freebsd[[12]].*)
         # C++ shared libraries reported to be fairly broken before
 	# switch to ELF
         _LT_TAGVAR(ld_shlibs, $1)=no
