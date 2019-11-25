$NetBSD: patch-image_sys_strcodec.h,v 1.1 2019/11/25 21:07:19 nros Exp $
* fix warning
* define and declaration of byteswap in .h file
* from FreeBSD ports
--- image/sys/strcodec.h.orig	2013-03-21 18:22:34.000000000 +0000
+++ image/sys/strcodec.h
@@ -64,7 +64,7 @@
 
 #ifndef UNREFERENCED_PARAMETER
 #define UNREFERENCED_PARAMETER(P) { (P) = (P); }
-#endif UNREFERENCED_PARAMETER
+#endif
 
 #ifdef UNDER_CE
 #define PLATFORM_WCE
@@ -676,3 +676,14 @@ void flushToByte(BitIOInfo* pIO);
 //    pIO->uiAccumulator = LOAD16(pIO->pbCurrent) & ((U32)(-1) >> pIO->cBitsUsed);\
 
 void OutputPerfTimerReport(CWMImageStrCodec *pState);
+
+#if (defined(WIN32) && !defined(UNDER_CE)) || (defined(UNDER_CE) && defined(_ARM_))
+// WinCE ARM and Desktop x86
+#else
+// other platform
+#ifdef _BIG__ENDIAN_
+#define _byteswap_ulong(x)  (x)
+#else // _BIG__ENDIAN_
+U32 _byteswap_ulong(U32 bits);
+#endif // _BIG__ENDIAN_
+#endif
