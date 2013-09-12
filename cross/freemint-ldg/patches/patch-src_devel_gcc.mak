$NetBSD: patch-src_devel_gcc.mak,v 1.1 2013/09/12 14:06:21 ryoon Exp $

--- src/devel/gcc.mak.orig	2012-10-05 21:09:38.000000000 +0000
+++ src/devel/gcc.mak
@@ -23,6 +23,6 @@
 
 ifeq ($(CROSS),yes)
-CC     = m68k-atari-mint-gcc
-AR     = m68k-atari-mint-ar
+CC     = ${FREEMINT_PREFIX}/bin/m68k-atari-mint-gcc
+AR     = ${FREEMINT_PREFIX}/bin/m68k-atari-mint-ar
 else
 CC     = gcc
