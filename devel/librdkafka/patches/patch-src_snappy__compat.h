$NetBSD: patch-src_snappy__compat.h,v 1.1 2017/04/24 12:20:37 fhajny Exp $

Add NetBSD support.

--- src/snappy_compat.h.orig	2017-04-12 08:36:34.000000000 +0000
+++ src/snappy_compat.h
@@ -3,7 +3,7 @@
 
 
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #  include <sys/endian.h>
 #elif defined(__APPLE_CC_) || defined(__MACH__)  /* MacOS/X support */
 #  include <machine/endian.h>
