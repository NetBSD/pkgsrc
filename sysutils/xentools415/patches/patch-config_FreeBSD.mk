$NetBSD: patch-config_FreeBSD.mk,v 1.1 2025/03/31 11:32:05 sborrill Exp $

Align paths on FreeBSD with pkgsrc

--- config/FreeBSD.mk.orig	2025-03-28 08:57:55.905441000 +0000
+++ config/FreeBSD.mk	2025-03-28 08:58:37.291735000 +0000
@@ -2,8 +2,8 @@
 
 # No wget on FreeBSD base system
 WGET = ftp
-PKG_INSTALLDIR = ${prefix}/libdata/pkgconfig
+PKG_INSTALLDIR = ${prefix}/lib/pkgconfig
 
 # Add the default pkg install path
-APPEND_LIB += /usr/local/lib
-APPEND_INCLUDES += /usr/local/include
+#APPEND_LIB += /usr/local/lib
+#APPEND_INCLUDES += /usr/local/include
