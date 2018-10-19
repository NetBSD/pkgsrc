$NetBSD: patch-ext_mri_blf.h,v 1.1 2018/10/19 17:03:10 jperkin Exp $

u_int*_t compat.

--- ext/mri/blf.h.orig	2018-10-19 17:00:01.930246543 +0000
+++ ext/mri/blf.h
@@ -49,6 +49,16 @@
 #define BLF_MAXKEYLEN ((BLF_N-2)*4)	/* 448 bits */
 #define BLF_MAXUTILIZED ((BLF_N+2)*4)	/* 576 bits */
 
+#ifndef u_int8_t
+#define u_int8_t	uint8_t
+#endif
+#ifndef u_int16_t
+#define u_int16_t	uint16_t
+#endif
+#ifndef u_int32_t
+#define u_int32_t	uint32_t
+#endif
+
 /* Blowfish context */
 typedef struct BlowfishContext {
 	u_int32_t S[4][256];	/* S-Boxes */
