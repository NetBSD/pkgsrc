$NetBSD: patch-examples_loadables_finfo.c,v 1.2 2025/10/10 20:48:02 js Exp $

MAJOR_IN_MKDEV is not in config.h so will never be defined, for now just go
with the simple workaround for illumos which will definitely need mkdev.h.

--- examples/loadables/finfo.c.orig	2025-07-10 14:29:10.112908803 +0000
+++ examples/loadables/finfo.c
@@ -28,7 +28,7 @@
 #endif
 
 #include <sys/types.h>
-#ifdef MAJOR_IN_MKDEV
+#if defined(MAJOR_IN_MKDEV) || defined(__illumos__)
 #  include <sys/mkdev.h>
 #endif
 #ifdef MAJOR_IN_SYSMACROS
@@ -273,7 +273,7 @@ printst(struct stat *st)
 
 	ma = major (st->st_rdev);
 	mi = minor (st->st_rdev);
-#if defined (makedev)
+#if defined (makedev) && !defined(__QNX__)
 	d = makedev (ma, mi);
 #else
 	d = st->st_rdev & 0xFF;
