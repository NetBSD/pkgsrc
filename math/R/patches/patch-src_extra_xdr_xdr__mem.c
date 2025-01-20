$NetBSD: patch-src_extra_xdr_xdr__mem.c,v 1.1 2025/01/20 21:26:02 he Exp $

Don't do the ntohl() / htonl() dance on NetBSD.

--- ./src/extra/xdr/xdr_mem.c.orig	2025-01-20 17:36:36.874607200 +0000
+++ ./src/extra/xdr/xdr_mem.c
@@ -24,6 +24,8 @@ static uint32_t ntohl(uint32_t x)
 #endif 
 }
 #else /* net is big-endian: little-endian hosts need byte-swap code */
+#if !defined(__NetBSD__)
+/* Not needed on NetBSD, ntohl() and htonl() already declared */
 #ifndef WORDS_BIGENDIAN
 static uint32_t ntohl (uint32_t x)
 {
@@ -33,7 +35,11 @@ static uint32_t ntohl (uint32_t x)
 #define ntohl(x) (x)
 #endif
 #endif
-#define htonl ntohl
+#endif
+#if !defined(__NetBSD__)
+/* Not needed on NetBSD, ntohl() and htonl() already declared */
+#define htonl(x) ntohl(x)
+#endif
 
 /*********************************************************************
  * RPC for the Windows NT Operating System
