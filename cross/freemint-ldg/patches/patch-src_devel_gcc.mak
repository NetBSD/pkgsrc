$NetBSD: patch-src_devel_gcc.mak,v 1.2 2014/01/19 07:36:18 ryoon Exp $

--- src/devel/gcc.mak.orig	2013-11-04 22:31:39.000000000 +0000
+++ src/devel/gcc.mak
@@ -23,6 +23,6 @@
 
 ifeq ($(CROSS),yes)
-CC     = m68k-atari-mint-gcc
-AR     = m68k-atari-mint-ar
+CC     = ${FREEMINT_PREFIX}/bin/m68k-atari-mint-gcc
+AR     = ${FREEMINT_PREFIX}/bin/m68k-atari-mint-ar
 else
 CC     = gcc
