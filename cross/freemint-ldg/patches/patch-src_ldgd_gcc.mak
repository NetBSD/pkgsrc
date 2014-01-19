$NetBSD: patch-src_ldgd_gcc.mak,v 1.1 2014/01/19 07:36:18 ryoon Exp $

--- src/ldgd/gcc.mak.orig	2014-01-19 07:15:22.000000000 +0000
+++ src/ldgd/gcc.mak
@@ -8,8 +8,8 @@
 #
 
 ifeq ($(CROSS),yes)
-CC     = m68k-atari-mint-gcc
-LD     = m68k-atari-mint-gcc
+CC     = ${FREEMINT_PREFIX}/bin/m68k-atari-mint-gcc
+LD     = ${FREEMINT_PREFIX}/bin/m68k-atari-mint-gcc
 else
 CC     = gcc
 LD     = gcc
