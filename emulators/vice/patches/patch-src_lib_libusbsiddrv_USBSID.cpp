$NetBSD: patch-src_lib_libusbsiddrv_USBSID.cpp,v 1.1 2026/01/11 14:15:04 rhialto Exp $

NetBSD's pthread_setname_np() has 3 arguments.

--- src/lib/libusbsiddrv/USBSID.cpp.orig	2025-12-25 21:07:32.102050718 +0000
+++ src/lib/libusbsiddrv/USBSID.cpp
@@ -619,7 +619,9 @@ unsigned char USBSID_Class::USBSID_Read(
 void* USBSID_Class::USBSID_Thread(void)
 { /* Only starts when threaded == true */
   USBDBG(stdout, "[USBSID] Thread starting\r\n");
-  #ifdef _GNU_SOURCE
+  #if defined(__NetBSD__)
+  pthread_setname_np(pthread_self(), "USBSID Thread", NULL);
+  #elif defined(_GNU_SOURCE)
   pthread_setname_np(pthread_self(), "USBSID Thread");
   #endif
   pthread_detach(pthread_self());
