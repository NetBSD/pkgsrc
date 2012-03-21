$NetBSD: patch-config_hwloc.m4,v 1.1.1.1 2012/03/21 13:31:35 asau Exp $

--- config/hwloc.m4.orig	2012-01-26 09:49:56.000000000 +0000
+++ config/hwloc.m4
@@ -210,6 +210,11 @@ EOF])
         hwloc_freebsd=yes
         AC_MSG_RESULT([FreeBSD])
         ;;
+      *-*-*netbsd*)
+        AC_DEFINE(HWLOC_NETBSD_SYS, 1, [Define to 1 on *NETBSD])
+        hwloc_netbsd=yes
+        AC_MSG_RESULT([NetBSD])
+        ;;
       *)
         AC_MSG_RESULT([Unsupported! ($target)])
         AC_DEFINE(HWLOC_UNSUPPORTED_SYS, 1, [Define to 1 on unsupported systems])
@@ -760,6 +765,7 @@ AC_DEFUN([HWLOC_DO_AM_CONDITIONALS],[
         AM_CONDITIONAL([HWLOC_HAVE_LINUX], [test "x$hwloc_linux" = "xyes"])
         AM_CONDITIONAL([HWLOC_HAVE_IRIX], [test "x$hwloc_irix" = "xyes"])
         AM_CONDITIONAL([HWLOC_HAVE_DARWIN], [test "x$hwloc_darwin" = "xyes"])
+        AM_CONDITIONAL([HWLOC_HAVE_NETBSD], [test "x$hwloc_netbsd" = "xyes"])
         AM_CONDITIONAL([HWLOC_HAVE_FREEBSD], [test "x$hwloc_freebsd" = "xyes"])
         AM_CONDITIONAL([HWLOC_HAVE_SOLARIS], [test "x$hwloc_solaris" = "xyes"])
         AM_CONDITIONAL([HWLOC_HAVE_AIX], [test "x$hwloc_aix" = "xyes"])
