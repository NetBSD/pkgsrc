$NetBSD: patch-src-crypto-hcrypto-kernel-config.h,v 1.1 2012/08/30 17:37:55 jakllsch Exp $

--- src/crypto/hcrypto/kernel/config.h.orig	2012-04-22 23:40:23.000000000 -0400
+++ src/crypto/hcrypto/kernel/config.h	2012-05-02 14:38:14.000000000 -0400
@@ -46,15 +46,19 @@
 #define calloc _afscrypto_calloc
 void * _afscrypto_calloc(int, size_t);
 
+#undef malloc
 #define malloc _afscrypto_malloc
 void * _afscrypto_malloc(size_t);
 
+#undef free
 #define free _afscrypto_free
 void _afscrypto_free(void *);
 
+#undef strdup
 #define strdup _afscrypto_strdup
 char * _afscrypto_strdup(const char *);
 
+#undef realloc
 #define realloc _afscrypto_realloc
 void * _afscrypto_realloc(void *, size_t);
 
