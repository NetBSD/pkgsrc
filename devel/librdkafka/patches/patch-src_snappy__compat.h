$NetBSD: patch-src_snappy__compat.h,v 1.2 2019/07/10 01:31:21 minskim Exp $

Add NetBSD support.

--- src/snappy_compat.h.orig	2019-05-28 15:56:28.000000000 +0000
+++ src/snappy_compat.h
@@ -3,7 +3,7 @@
 
 
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #  include <sys/endian.h>
 #elif defined(__APPLE_CC_) || (defined(__MACH__) && defined(__APPLE__))  /* MacOS/X support */
 #  include <machine/endian.h>
