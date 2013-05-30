$NetBSD: patch-libxorp_asyncio.cc,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- libxorp/asyncio.cc.orig	2013-04-29 19:22:48.000000000 +0000
+++ libxorp/asyncio.cc
@@ -484,7 +484,7 @@ template <typename T, typename U>
 static void
 iov_place(T*& iov_base, U& iov_len, uint8_t* data, size_t data_len)
 {
-    static_assert(sizeof(T*) == sizeof(uint8_t*));
+    my_static_assert(sizeof(T*) == sizeof(uint8_t*));
     iov_base = reinterpret_cast<T*>(data);
     iov_len  = data_len;
 }
