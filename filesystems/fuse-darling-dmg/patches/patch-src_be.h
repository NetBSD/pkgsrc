--- src/be.h.orig	2016-03-10 17:31:29.000000000 +0100
+++ src/be.h	2016-03-10 17:31:58.000000000 +0100
@@ -1,7 +1,7 @@
 #ifndef BENDIAN_H
 #define BENDIAN_H
 #include <stdint.h>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/endian.h>
 #elif defined(_WIN32)
 	static uint16_t htobe16(uint16_t x) {
