$NetBSD: patch-sal_rtl_cipher.cxx,v 1.2 2024/02/11 15:31:58 ryoon Exp $

include <cstdlib> for std::free()

--- sal/rtl/cipher.cxx.orig	2024-01-31 14:40:22.154404120 +0000
+++ sal/rtl/cipher.cxx
@@ -23,6 +23,7 @@
 #include <rtl/alloc.h>
 #include <rtl/cipher.h>
 #include <algorithm>
+#include <cstdlib>
 
 #if defined LIBO_CIPHER_OPENSSL_BACKEND
 #include <openssl/evp.h>
