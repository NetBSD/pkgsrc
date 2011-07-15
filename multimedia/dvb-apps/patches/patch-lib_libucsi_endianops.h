$NetBSD: patch-lib_libucsi_endianops.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/endianops.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/endianops.h
@@ -27,8 +27,14 @@ extern "C"
 #endif
 
 #include <stdint.h>
+#ifdef __NetBSD__
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#define bswap_64 bswap64
+#else
 #include <byteswap.h>
 #include <endian.h>
+#endif
 
 #define __ucsi_packed __attribute__((packed))
 
@@ -44,27 +50,27 @@ extern "C"
 #define EBIT7(x1,x2,x3,x4,x5,x6,x7) x1 x2 x3 x4 x5 x6 x7
 #define EBIT8(x1,x2,x3,x4,x5,x6,x7,x8) x1 x2 x3 x4 x5 x6 x7 x8
 
-static inline void bswap16(uint8_t *buf) {
+static inline void ubswap16(uint8_t *buf) {
 	(void) buf;
 }
 
-static inline void bswap32(uint8_t *buf) {
+static inline void ubswap32(uint8_t *buf) {
 	(void) buf;
 }
 
-static inline void bswap64(uint8_t *buf) {
+static inline void ubswap64(uint8_t *buf) {
 	(void) buf;
 }
 
-static inline void bswap24(uint8_t *buf) {
+static inline void ubswap24(uint8_t *buf) {
 	(void) buf;
 }
 
-static inline void bswap40(uint8_t *buf) {
+static inline void ubswap40(uint8_t *buf) {
 	(void) buf;
 }
 
-static inline void bswap48(uint8_t *buf) {
+static inline void ubswap48(uint8_t *buf) {
 	(void) buf;
 }
 
@@ -77,26 +83,26 @@ static inline void bswap48(uint8_t *buf)
 #define EBIT7(x1,x2,x3,x4,x5,x6,x7) x7 x6 x5 x4 x3 x2 x1
 #define EBIT8(x1,x2,x3,x4,x5,x6,x7,x8) x8 x7 x6 x5 x4 x3 x2 x1
 
-static inline void bswap16(uint8_t * buf) {
+static inline void ubswap16(uint8_t * buf) {
 	*((uint16_t*)buf) = bswap_16((*(uint16_t*)buf));
 }
 
-static inline void bswap32(uint8_t * buf) {
+static inline void ubswap32(uint8_t * buf) {
 	*((uint32_t*)buf) = bswap_32((*(uint32_t*)buf));
 }
 
-static inline void bswap64(uint8_t * buf) {
+static inline void ubswap64(uint8_t * buf) {
 	*((uint64_t*)buf) = bswap_64((*(uint64_t*)buf));
 }
 
-static inline void bswap24(uint8_t * buf) {
+static inline void ubswap24(uint8_t * buf) {
 	uint8_t tmp0 = buf[0];
 
 	buf[0] = buf[2];
 	buf[2] = tmp0;
 }
 
-static inline void bswap40(uint8_t * buf) {
+static inline void ubswap40(uint8_t * buf) {
 	uint8_t tmp0 = buf[0];
 	uint8_t tmp1 = buf[1];
 
@@ -106,7 +112,7 @@ static inline void bswap40(uint8_t * buf
 	buf[4] = tmp0;
 }
 
-static inline void bswap48(uint8_t * buf) {
+static inline void ubswap48(uint8_t * buf) {
 	uint8_t tmp0 = buf[0];
 	uint8_t tmp1 = buf[1];
 	uint8_t tmp2 = buf[2];
