$NetBSD: patch-m4_os.m4,v 1.1 2013/05/09 05:42:53 mef Exp $

Add DragonFly support. Run autoconf if changed.

--- m4/os.m4.orig	2013-05-09 12:19:37.356190000 +0900
+++ m4/os.m4	2013-05-09 12:20:17.026800000 +0900
@@ -21,6 +21,7 @@ AC_DEFUN([lldp_CHECK_OS], [
   lldp_DEFINE_OS(freebsd*|kfreebsd*, FreeBSD, FREEBSD)
   lldp_DEFINE_OS(openbsd*, OpenBSD, OPENBSD)
   lldp_DEFINE_OS(netbsd*, NetBSD, NETBSD)
+  lldp_DEFINE_OS(dragonfly*, DragonFly, DRAGONFLY)
   lldp_DEFINE_OS(darwin*, [Mac OS X], OSX)
 
   if test x"$os" = x; then
