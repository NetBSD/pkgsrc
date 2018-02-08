$NetBSD: patch-src_runtime_kwalletd_backend_blowfish.h,v 1.1 2018/02/08 13:49:04 jperkin Exp $

Avoid macro conflicts.

--- src/runtime/kwalletd/backend/blowfish.h.orig	2017-12-02 20:09:03.000000000 +0000
+++ src/runtime/kwalletd/backend/blowfish.h
@@ -54,6 +54,8 @@ public:
     virtual int decrypt(void *block, int len);
 
 private:
+#undef _S
+#undef _P
     uint32_t _S[4][256];
     uint32_t _P[18];
 
