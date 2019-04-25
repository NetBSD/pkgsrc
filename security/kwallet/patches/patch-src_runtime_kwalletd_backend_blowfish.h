$NetBSD: patch-src_runtime_kwalletd_backend_blowfish.h,v 1.2 2019/04/25 21:00:43 markd Exp $

Avoid macro conflicts.

--- src/runtime/kwalletd/backend/blowfish.h.orig	2019-04-07 07:33:14.000000000 +0000
+++ src/runtime/kwalletd/backend/blowfish.h
@@ -54,6 +54,8 @@ public:
     int decrypt(void *block, int len) override;
 
 private:
+#undef _S
+#undef _P
     uint32_t _S[4][256];
     uint32_t _P[18];
 
