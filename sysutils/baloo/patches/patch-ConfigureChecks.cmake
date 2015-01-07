$NetBSD: patch-ConfigureChecks.cmake,v 1.1 2015/01/07 13:09:30 jperkin Exp $

Ignore xattr header check on SunOS.

--- ConfigureChecks.cmake.orig	2014-11-06 12:03:28.000000000 +0000
+++ ConfigureChecks.cmake
@@ -13,7 +13,7 @@ check_include_files("sys/types.h;sys/xat
 # DragonFly BSD, FreeBSD and NetBSD.
 check_include_files("sys/types.h;sys/extattr.h" HAVE_SYS_EXTATTR_H)
 
-if (NOT (HAVE_SYS_XATTR_H OR HAVE_SYS_EXTATTR_H))
+if (NOT (HAVE_SYS_XATTR_H OR HAVE_SYS_EXTATTR_H) AND NOT CMAKE_SYSTEM MATCHES "SunOS.*")
     message(FATAL_ERROR "Baloo requires extended attributes support in the operating system, but no headers have been found.")
 endif ()
 
