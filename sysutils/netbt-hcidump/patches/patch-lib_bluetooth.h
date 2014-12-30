$NetBSD: patch-lib_bluetooth.h,v 1.1 2014/12/30 08:39:13 plunky Exp $

Not much of the original library is needed.

--- lib/bluetooth.h.orig	2014-12-12 13:38:33.000000000 +0000
+++ lib/bluetooth.h
@@ -30,6 +30,7 @@
 extern "C" {
 #endif
 
+#if 0
 #include <stdio.h>
 #include <stdint.h>
 #include <string.h>
@@ -153,6 +154,20 @@ enum {
 #else
 #error "Unknown byte order"
 #endif
+#else
+#include <bluetooth.h>
+#include <string.h>
+
+#define SOL_HCI		BTPROTO_HCI
+
+#define htobs(d)	htole16(d)
+#define htobl(d)	htole32(d)
+#define btohs(d)	le16toh(d)
+#define btohl(d)	le32toh(d)
+#define bswap_64(v)	bswap64(v)
+#define bswap_32(v)	bswap32(v)
+#define bswap_16(v)	bswap16(v)
+#endif
 
 /* Bluetooth unaligned access */
 #define bt_get_unaligned(ptr)			\
@@ -296,6 +311,7 @@ static inline void bt_put_be16(uint16_t 
 #error "Unknown byte order"
 #endif
 
+#if 0
 /* BD Address */
 typedef struct {
 	uint8_t b[6];
@@ -309,6 +325,7 @@ typedef struct {
 #define BDADDR_ANY   (&(bdaddr_t) {{0, 0, 0, 0, 0, 0}})
 #define BDADDR_ALL   (&(bdaddr_t) {{0xff, 0xff, 0xff, 0xff, 0xff, 0xff}})
 #define BDADDR_LOCAL (&(bdaddr_t) {{0, 0, 0, 0xff, 0xff, 0xff}})
+#endif
 
 /* Copy, swap, convert BD Address */
 static inline int bacmp(const bdaddr_t *ba1, const bdaddr_t *ba2)
@@ -321,9 +338,12 @@ static inline void bacpy(bdaddr_t *dst, 
 }
 
 void baswap(bdaddr_t *dst, const bdaddr_t *src);
+#if 0
 bdaddr_t *strtoba(const char *str);
 char *batostr(const bdaddr_t *ba);
+#endif
 int ba2str(const bdaddr_t *ba, char *str);
+#if 0
 int str2ba(const char *str, bdaddr_t *ba);
 int ba2oui(const bdaddr_t *ba, char *oui);
 int bachk(const char *str);
@@ -337,6 +357,7 @@ void *bt_malloc(size_t size);
 void bt_free(void *ptr);
 
 int bt_error(uint16_t code);
+#endif
 const char *bt_compidtostr(int id);
 
 typedef struct {
