$NetBSD: patch-dist_aclocal_libtool.m4,v 1.1 2015/01/01 18:52:52 ryoon Exp $

--- dist/aclocal/libtool.m4.orig	2014-06-10 15:32:54.000000000 +0000
+++ dist/aclocal/libtool.m4
@@ -2406,7 +2406,7 @@ dgux*)
   shlibpath_var=LD_LIBRARY_PATH
   ;;
 
-freebsd1*)
+freebsd1|freebsd1.*)
   dynamic_linker=no
   ;;
 
@@ -2417,7 +2417,7 @@ freebsd* | dragonfly*)
     objformat=`/usr/bin/objformat`
   else
     case $host_os in
-    freebsd[[123]]*) objformat=aout ;;
+    freebsd[[123]]|freebsd[[123]].*) objformat=aout ;;
     *) objformat=elf ;;
     esac
   fi
@@ -5110,7 +5110,7 @@ _LT_EOF
       _LT_TAGVAR(hardcode_shlibpath_var, $1)=no
       ;;
 
-    freebsd1*)
+    freebsd1|freebsd1.*)
       _LT_TAGVAR(ld_shlibs, $1)=no
       ;;
 
@@ -6137,7 +6137,7 @@ if test "$_lt_caught_CXX_error" != yes; 
         esac
         ;;
 
-      freebsd[[12]]*)
+      freebsd[[12]]|freebsd[[12]].*)
         # C++ shared libraries reported to be fairly broken before
 	# switch to ELF
         _LT_TAGVAR(ld_shlibs, $1)=no
