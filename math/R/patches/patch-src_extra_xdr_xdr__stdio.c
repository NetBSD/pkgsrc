$NetBSD: patch-src_extra_xdr_xdr__stdio.c,v 1.1 2025/01/20 21:26:02 he Exp $

Don't do the ntohl() / htonl() dance on NetBSD.

--- src/extra/xdr/xdr_stdio.c.orig	2025-01-20 17:42:42.369938152 +0000
+++ src/extra/xdr/xdr_stdio.c
@@ -20,6 +20,8 @@ static uint32_t ntohl(uint32_t x)
 #endif
 }
 #else /* net is big-endian: little-endian hosts need byte-swap code */
+#if !defined(__NetBSD__)
+/* Not needed on NetBSD, ntohl() and htonl() already declared */
 #ifndef WORDS_BIGENDIAN
 /* #ifdef LITTLE_ENDIAN */
 static uint32_t ntohl (uint32_t x)
@@ -30,7 +32,11 @@ static uint32_t ntohl (uint32_t x)
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
