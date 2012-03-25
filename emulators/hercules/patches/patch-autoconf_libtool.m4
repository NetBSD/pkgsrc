$NetBSD: patch-autoconf_libtool.m4,v 1.1 2012/03/25 05:27:43 ryoon Exp $

--- autoconf/libtool.m4.orig	2009-02-09 07:55:03.000000000 +0000
+++ autoconf/libtool.m4
@@ -1323,7 +1323,7 @@ kfreebsd*-gnu)
   dynamic_linker='GNU ld.so'
   ;;
 
-freebsd*)
+freebsd* | dragonfly*)
   objformat=`test -x /usr/bin/objformat && /usr/bin/objformat || echo aout`
   version_type=freebsd-$objformat
   case $version_type in
@@ -2989,7 +2989,7 @@ case $host_os in
   freebsd-elf*)
     _LT_AC_TAGVAR(archive_cmds_need_lc, $1)=no
     ;;
-  freebsd* | kfreebsd*-gnu)
+  freebsd* | kfreebsd*-gnu | dragonfly*)
     # FreeBSD 3 and later use GNU C++ and GNU ld with standard ELF
     # conventions
     _LT_AC_TAGVAR(ld_shlibs, $1)=yes
@@ -4635,7 +4635,7 @@ AC_MSG_CHECKING([for $compiler option to
 	    ;;
 	esac
 	;;
-      freebsd* | kfreebsd*-gnu)
+      freebsd* | kfreebsd*-gnu | dragonfly*)
 	# FreeBSD uses GNU C++
 	;;
       hpux9* | hpux10* | hpux11*)
@@ -5456,7 +5456,7 @@ EOF
       ;;
 
     # FreeBSD 3 and greater uses gcc -shared to do shared libraries.
-    freebsd* | kfreebsd*-gnu)
+    freebsd* | kfreebsd*-gnu | dragonfly*)
       _LT_AC_TAGVAR(archive_cmds, $1)='$CC -shared -o $lib $libobjs $deplibs $compiler_flags'
       _LT_AC_TAGVAR(hardcode_libdir_flag_spec, $1)='-R$libdir'
       _LT_AC_TAGVAR(hardcode_direct, $1)=yes
