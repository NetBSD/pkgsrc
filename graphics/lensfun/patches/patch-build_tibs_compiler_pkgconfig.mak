$NetBSD: patch-build_tibs_compiler_pkgconfig.mak,v 1.1 2013/08/04 19:12:00 adam Exp $

Install pkgconfig file also on Darwin.

--- build/tibs//compiler/pkgconfig.mak.orig	2013-08-04 19:08:20.000000000 +0000
+++ build/tibs//compiler/pkgconfig.mak
@@ -4,7 +4,7 @@ ifdef CONF_LIBDIR
 # Try to guess here if target supports pkgconfig
 # - Any POSIX platform
 # - Cross-compiling on a POSIX target for WINDOWS (mingw32)
-ifneq ($(findstring /posix/,/$(TARGET)/)$(findstring /posix-windows/,/$(HOST)-$(TARGET)/),)
+ifneq ($(findstring /posix/,/$(TARGET)/)$(findstring /mac/,/$(TARGET)/),)
 
 XFNAME.PKGCONFIG = $(addprefix $$(OUT),$1)
 MKDEPS.PKGCONFIG = $1
