$NetBSD: patch-libdiscmage_libdiscmage.h,v 1.1 2018/03/04 15:20:02 wiz Exp $

Fix build on NetBSD.

--- libdiscmage/libdiscmage.h.orig	2015-11-16 01:33:49.000000000 +0000
+++ libdiscmage/libdiscmage.h
@@ -28,7 +28,7 @@ extern "C" {
 
 #include <stdio.h>                              // FILENAME_MAX
 
-#if     defined __linux__ || defined __FreeBSD__ || defined __OpenBSD__ || \
+#if     defined __linux__ || defined __FreeBSD__ || defined __OpenBSD__ || defined(__NetBSD__) \
         defined __solaris__ || defined __MINGW32__ || defined __CYGWIN__ || \
         defined __BEOS__ || defined AMIGA || defined __APPLE__ // Mac OS X actually
 // We cannot use config.h (for HAVE_INTTYPES_H), because this header file may be
