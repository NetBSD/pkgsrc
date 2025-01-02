$NetBSD: patch-src_smartcard_scard_winscarddll.h,v 1.1 2025/01/02 09:58:45 adam Exp $

Fix building on Darwin.

--- src/smartcard/scard/winscarddll.h.orig	2022-01-10 12:12:48.000000000 +0000
+++ src/smartcard/scard/winscarddll.h
@@ -30,6 +30,7 @@ Foundation, Inc., 51 Franklin St, Fifth 
     #include <PCSC/wintypes.h>
     #include <PCSC/winscard.h>
     #define LPCTSTR char*
+    #define LPTSTR char*
 #else // !__APPLE__
     #include <winscard.h>
 #endif
