$NetBSD: patch-src_extra_xdr_xdr__stdio.c,v 1.2 2026/02/16 23:44:02 mef Exp $

Don't do the ntohl() / htonl() dance on NetBSD.

--- src/extra/xdr/xdr_stdio.c.orig	2025-03-14 08:02:03.000000000 +0900
+++ src/extra/xdr/xdr_stdio.c	2026-01-03 18:55:12.260979571 +0900
@@ -44,6 +44,9 @@ static uint32_t ntohl(uint32_t x)
 # endif
 }
 #else /* net is big-endian: little-endian hosts need byte-swap code */
+#if !defined(__NetBSD__)
+/* Not needed on NetBSD, ntohl() and htonl() already declared */
+ 
 #ifndef WORDS_BIGENDIAN
 /* #ifdef LITTLE_ENDIAN */
 static uint32_t ntohl (uint32_t x)
@@ -54,7 +57,11 @@ static uint32_t ntohl (uint32_t x)
 #define ntohl(x) (x)
 #endif
 #endif
+#endif
+#if !defined(__NetBSD__)
+/* Not needed on NetBSD, ntohl() and htonl() already declared */
 #define htonl ntohl
+#endif
 
 /*********************************************************************
  * RPC for the Windows NT Operating System
