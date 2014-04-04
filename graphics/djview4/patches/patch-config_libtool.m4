$NetBSD: patch-config_libtool.m4,v 1.1 2014/04/04 18:25:51 asau Exp $

--- config/libtool.m4.orig	2011-08-17 14:24:20.000000000 +0000
+++ config/libtool.m4
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
@@ -4723,7 +4723,7 @@ _LT_EOF
       _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
       ;;
 
-    freebsd1*)
+    freebsd1|freebsd1.*)
       _LT_TAGVAR(ld_shlibs, $1)=no
       ;;
 
@@ -5685,7 +5685,7 @@ if test "$_lt_caught_CXX_error" != yes; 
         esac
         ;;
 
-      freebsd[[12]]*)
+      freebsd[[12]]|freebsd[[12]].*)
         # C++ shared libraries reported to be fairly broken before
 	# switch to ELF
         _LT_TAGVAR(ld_shlibs, $1)=no
