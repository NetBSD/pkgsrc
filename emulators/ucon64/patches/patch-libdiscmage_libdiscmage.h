$NetBSD: patch-libdiscmage_libdiscmage.h,v 1.2 2018/03/07 12:34:55 wiz Exp $

Patch from upstream to improve build on NetBSD.

--- libdiscmage/libdiscmage.h.orig	2015-11-16 01:33:49.000000000 +0000
+++ libdiscmage/libdiscmage.h
@@ -1,8 +1,8 @@
 /*
 libdiscmage.h - libdiscmage
 
-Copyright (c) 2002 - 2004 NoisyB
-Copyright (c) 2002 - 2004 dbjh
+Copyright (c) 2002 - 2004       NoisyB
+Copyright (c) 2002 - 2004, 2018 dbjh
 
 
 This library is free software; you can redistribute it and/or
@@ -28,9 +28,7 @@ extern "C" {
 
 #include <stdio.h>                              // FILENAME_MAX
 
-#if     defined __linux__ || defined __FreeBSD__ || defined __OpenBSD__ || \
-        defined __solaris__ || defined __MINGW32__ || defined __CYGWIN__ || \
-        defined __BEOS__ || defined AMIGA || defined __APPLE__ // Mac OS X actually
+#if     !(defined __MSDOS__ || defined _MSC_VER)
 // We cannot use config.h (for HAVE_INTTYPES_H), because this header file may be
 //  installed in a system include directory
 #include <inttypes.h>
