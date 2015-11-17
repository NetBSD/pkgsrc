$NetBSD: patch-m4_xbmc__arch.m4,v 1.2 2015/11/17 16:43:10 christos Exp $

--- m4/xbmc_arch.m4.orig	2015-10-19 06:31:15.000000000 +0000
+++ m4/xbmc_arch.m4
@@ -14,6 +14,15 @@ case $build in
   amd64-*-freebsd*)
      AC_SUBST(NATIVE_ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_FREEBSD -D_LINUX")
      ;;
+  i386-*-netbsd*)
+     AC_SUBST(NATIVE_ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_NETBSD -D_LINUX")
+     ;;
+  x86_64-*-netbsd*)
+     AC_SUBST(NATIVE_ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_NETBSD -D_LINUX")
+     ;;
+  armv6-*-netbsd*|armv7-*-netbsd*)
+     AC_SUBST(NATIVE_ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_NETBSD -D_LINUX")
+     ;;
   *86*-apple-darwin*)
      AC_SUBST(NATIVE_ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_DARWIN -DTARGET_DARWIN_OSX -D_LINUX")
      ;;
@@ -45,6 +54,15 @@ case $host in
   amd64-*-freebsd*)
      AC_SUBST(ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_FREEBSD -D_LINUX")
      ;;
+  i386-*-netbsd*)
+     AC_SUBST(ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_NETBSD -D_LINUX")
+     ;;
+  x86_64-*-netbsd*)
+     AC_SUBST(ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_NETBSD -D_LINUX")
+     ;;
+  armv6-*-netbsd*|armv7-*-netbsd*)
+     AC_SUBST(ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_NETBSD -D_LINUX")
+     ;;
   arm-apple-darwin*)
      AC_SUBST(ARCH_DEFINES, "-DTARGET_POSIX -DTARGET_DARWIN -DTARGET_DARWIN_IOS -D_LINUX")
      ;;
