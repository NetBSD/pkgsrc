$NetBSD: patch-aclocal.m4,v 1.1 2014/03/19 21:56:31 asau Exp $

--- aclocal.m4.orig	2014-03-05 10:52:28.000000000 +0000
+++ aclocal.m4
@@ -4546,7 +4546,7 @@ dgux*)
   shlibpath_var=LD_LIBRARY_PATH
   ;;
 
-freebsd1*)
+freebsd1|freebsd1.*)
   dynamic_linker=no
   ;;
 
@@ -4557,7 +4557,7 @@ freebsd* | dragonfly*)
     objformat=`/usr/bin/objformat`
   else
     case $host_os in
-    freebsd[[123]]*) objformat=aout ;;
+    freebsd[[123]]|freebsd[[123]].*) objformat=aout ;;
     *) objformat=elf ;;
     esac
   fi
@@ -6174,7 +6174,7 @@ case $host_os in
 	;;
     esac
     ;;
-  freebsd[[12]]*)
+  freebsd[[12]]|freebsd[[12]].*)
     # C++ shared libraries reported to be fairly broken before switch to ELF
     _LT_AC_TAGVAR(ld_shlibs, $1)=no
     ;;
@@ -8857,7 +8857,7 @@ _LT_EOF
       _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
       ;;
 
-    freebsd1*)
+    freebsd1|freebsd1.*)
       _LT_AC_TAGVAR(ld_shlibs, $1)=no
       ;;
 
