$NetBSD: patch-src_pycrypto__common.h,v 1.1 2016/12/30 22:32:54 maya Exp $

alloca.h appears to be a linux only header.
for NetBSD, alloca is in stdlib.h

--- src/pycrypto_common.h.orig	2016-10-16 20:19:30.000000000 +0000
+++ src/pycrypto_common.h
@@ -45,7 +45,9 @@ typedef unsigned __int64 uint64_t;
 
 #else
 #include <stdint.h>
+#ifdef __linux__
 #include <alloca.h>
+#endif /* !linux */
 #endif
 
 #include <stdlib.h>
