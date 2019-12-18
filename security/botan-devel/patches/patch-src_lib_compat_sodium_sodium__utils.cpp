$NetBSD: patch-src_lib_compat_sodium_sodium__utils.cpp,v 1.1 2019/12/18 12:40:22 joerg Exp $

Header for getenv.

--- src/lib/compat/sodium/sodium_utils.cpp.orig	2019-12-13 15:03:08.136939461 +0000
+++ src/lib/compat/sodium/sodium_utils.cpp
@@ -12,6 +12,8 @@
 #include <botan/internal/ct_utils.h>
 #include <botan/loadstor.h>
 
+#include <cstdlib>
+
 namespace Botan {
 
 void Sodium::randombytes_buf(void* buf, size_t len)
