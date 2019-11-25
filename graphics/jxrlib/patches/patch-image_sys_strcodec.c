$NetBSD: patch-image_sys_strcodec.c,v 1.1 2019/11/25 21:07:19 nros Exp $
* defines in .h file, fromm FreeBSD ports  
--- image/sys/strcodec.c.orig	2013-03-20 18:16:21.000000000 +0000
+++ image/sys/strcodec.c
@@ -668,9 +668,7 @@ ERR detach_SB(SimpleBitIO* pSB)
 // WinCE ARM and Desktop x86
 #else
 // other platform
-#ifdef _BIG__ENDIAN_
-#define _byteswap_ulong(x)  (x)
-#else // _BIG__ENDIAN_
+#ifndef _BIG__ENDIAN_
 U32 _byteswap_ulong(U32 bits)
 {
     U32 r = (bits & 0xffu) << 24;
