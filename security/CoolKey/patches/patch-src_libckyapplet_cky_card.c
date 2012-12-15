$NetBSD: patch-src_libckyapplet_cky_card.c,v 1.1 2012/12/15 01:07:17 pettai Exp $

Build fix for a more modern pcsc-lite.

--- src/libckyapplet/cky_card.c.orig	2012-12-11 21:28:26.000000000 +0000
+++ src/libckyapplet/cky_card.c
@@ -27,7 +27,6 @@
 
 #ifndef WINAPI
 #define WINAPI
-typedef SCARD_READERSTATE *LPSCARD_READERSTATE;
 #endif
 
 #ifndef SCARD_E_NO_READERS_AVAILABLE
@@ -108,7 +107,7 @@ typedef long (WINAPI * SCardGetAttribFn)
 typedef long (WINAPI * SCardGetStatusChangeFn) (
     SCARDCONTEXT hContext,
     unsigned long dwTimeout,
-    LPSCARD_READERSTATE rgReaderStates,
+    SCARD_READERSTATE *rgReaderStates,
     unsigned long cReaders);
 
 typedef long (WINAPI * SCardCancelFn) (
