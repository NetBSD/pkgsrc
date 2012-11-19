$NetBSD: patch-src_display.h,v 1.1 2012/11/19 03:06:04 joerg Exp $

--- src/display.h.orig	2012-11-19 00:55:37.000000000 +0000
+++ src/display.h
@@ -67,19 +67,19 @@ typedef enum headerline
  * Function prototypes
  */
 
-inline void display_header_line (headerline_t);
-inline void display_header_banner (char *);
-inline void display_header_banner_ts(char *, char *);
-inline void display (char *, u_int8_t *, u_int32_t, display_t);
-inline void display_string (u_int8_t *, u_int8_t *);
-inline void display_strmap(char *, int, strmap_t *map);
-inline void display_strmap_hex(char *, int, strmap_t *map);
-inline void display_ipv4 (u_int8_t *, u_int8_t *);
-inline void display_ipv6 (u_int8_t *, u_int8_t *);
-inline void display_minimal (u_int8_t *, u_int32_t, display_t);
-inline void display_minimal_string (u_int8_t *);
-inline void display_minimal_ipv4 (u_int8_t *);
-inline void display_minimal_ipv6 (u_int8_t *);
-inline void display_minimal_cr(void);
+void display_header_line (headerline_t);
+void display_header_banner (char *);
+void display_header_banner_ts(char *, char *);
+void display (char *, u_int8_t *, u_int32_t, display_t);
+void display_string (u_int8_t *, u_int8_t *);
+void display_strmap(char *, int, strmap_t *map);
+void display_strmap_hex(char *, int, strmap_t *map);
+void display_ipv4 (u_int8_t *, u_int8_t *);
+void display_ipv6 (u_int8_t *, u_int8_t *);
+void display_minimal (u_int8_t *, u_int32_t, display_t);
+void display_minimal_string (u_int8_t *);
+void display_minimal_ipv4 (u_int8_t *);
+void display_minimal_ipv6 (u_int8_t *);
+void display_minimal_cr(void);
 
 #endif
