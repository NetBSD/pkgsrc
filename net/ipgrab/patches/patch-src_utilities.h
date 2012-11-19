$NetBSD: patch-src_utilities.h,v 1.1 2012/11/19 03:06:04 joerg Exp $

--- src/utilities.h.orig	2012-11-19 00:56:45.000000000 +0000
+++ src/utilities.h
@@ -28,14 +28,14 @@
 
 #include "global.h"
 
-inline void   reverse_byte_order(u_int8_t *, int);
-inline int    isprint_str(char *, int);
-inline int    isspace_str(char *, int);
-inline char * argv2str(char **);
-inline void * my_malloc(size_t);
-inline void   my_free(void *);
-inline void   dump_hex_and_text(char *, int);
-inline int    ipaddr_space(u_int32_t);
-inline char * make_space_str(int);
+void   reverse_byte_order(u_int8_t *, int);
+int    isprint_str(char *, int);
+int    isspace_str(char *, int);
+char * argv2str(char **);
+void * my_malloc(size_t);
+void   my_free(void *);
+void   dump_hex_and_text(char *, int);
+int    ipaddr_space(u_int32_t);
+char * make_space_str(int);
 
 #endif
