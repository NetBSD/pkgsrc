$NetBSD: patch-src_emu_emucore.h,v 1.2 2021/06/19 07:23:31 nia Exp $

Avoid colliding with libc symbols on NetBSD.

--- src/emu/emucore.h.orig	2018-04-17 17:16:44.000000000 +0000
+++ src/emu/emucore.h
@@ -502,6 +502,7 @@ inline void fatalerror_exitcode(running_
 //**************************************************************************
 
 // population count
+#ifndef __NetBSD__
 inline int popcount(UINT32 val)
 {
 	int count;
@@ -510,6 +511,7 @@ inline int popcount(UINT32 val)
 		val &= val - 1;
 	return count;
 }
+#endif
 
 
 // convert a series of 32 bits into a float
