$NetBSD: patch-src_pycrypto__common.h,v 1.2 2016/12/30 23:02:57 maya Exp $

BSDs generally don't have alloca.h, Sun needs it

--- src/pycrypto_common.h.orig	2016-10-16 20:19:30.000000000 +0000
+++ src/pycrypto_common.h
@@ -45,7 +45,9 @@ typedef unsigned __int64 uint64_t;
 
 #else
 #include <stdint.h>
+#if defined(__linux__) || defined(__sun)
 #include <alloca.h>
+#endif /* !linux */
 #endif
 
 #include <stdlib.h>
