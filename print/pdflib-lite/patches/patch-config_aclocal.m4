$NetBSD: patch-config_aclocal.m4,v 1.1 2014/04/17 21:40:04 asau Exp $

--- config/aclocal.m4.orig	2010-04-29 13:50:03.000000000 +0000
+++ config/aclocal.m4
@@ -1445,7 +1445,7 @@ dgux*)
   shlibpath_var=LD_LIBRARY_PATH
   ;;
 
-freebsd1*)
+freebsd1|freebsd1.*)
   dynamic_linker=no
   ;;
 
@@ -1456,7 +1456,7 @@ freebsd* | dragonfly*)
     objformat=`/usr/bin/objformat`
   else
     case $host_os in
-    freebsd[[123]]*) objformat=aout ;;
+    freebsd[[123]]|freebsd[[123]].*) objformat=aout ;;
     *) objformat=elf ;;
     esac
   fi
@@ -1474,7 +1474,7 @@ freebsd* | dragonfly*)
   esac
   shlibpath_var=LD_LIBRARY_PATH
   case $host_os in
-  freebsd2*)
+  freebsd2|freebsd2.*)
     shlibpath_overrides_runpath=yes
     ;;
   freebsd3.[[01]]* | freebsdelf3.[[01]]*)
@@ -3156,7 +3156,7 @@ case $host_os in
 	;;
     esac
     ;;
-  freebsd[[12]]*)
+  freebsd[[12]]|freebsd[[12]].*)
     # C++ shared libraries reported to be fairly broken before switch to ELF
     _LT_AC_TAGVAR(ld_shlibs, $1)=no
     ;;
@@ -6025,7 +6025,7 @@ _LT_EOF
       _LT_AC_TAGVAR(hardcode_shlibpath_var, $1)=no
       ;;
 
-    freebsd1*)
+    freebsd1|freebsd1.*)
       _LT_AC_TAGVAR(ld_shlibs, $1)=no
       ;;
 
@@ -6041,7 +6041,7 @@ _LT_EOF
       ;;
 
     # Unfortunately, older versions of FreeBSD 2 do not have this feature.
-    freebsd2*)
+    freebsd2|freebsd2.*)
       _LT_AC_TAGVAR(archive_cmds, $1)='$LD -Bshareable -o $lib $libobjs $deplibs $linker_flags'
       _LT_AC_TAGVAR(hardcode_direct, $1)=yes
       _LT_AC_TAGVAR(hardcode_minus_L, $1)=yes
