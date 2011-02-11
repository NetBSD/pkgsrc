$NetBSD: patch-src_emu_emucore.h,v 1.2 2011/02/11 12:49:33 abs Exp $

--- src/emu/emucore.h.orig	2010-12-31 14:59:46.000000000 +0000
+++ src/emu/emucore.h
@@ -686,6 +686,7 @@ inline void fatalerror_exitcode(running_
 //**************************************************************************
 
 // population count
+#ifndef SDLMAME_NETBSD
 inline int popcount(UINT32 val)
 {
 	int count;
@@ -694,6 +695,7 @@ inline int popcount(UINT32 val)
 		val &= val - 1;
 	return count;
 }
+#endif
 
 
 // convert a series of 32 bits into a float
