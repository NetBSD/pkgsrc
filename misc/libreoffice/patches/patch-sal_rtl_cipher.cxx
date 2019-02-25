$NetBSD: patch-sal_rtl_cipher.cxx,v 1.1 2019/02/25 14:12:53 tnn Exp $

include <cstdlib> for std::free()

--- sal/rtl/cipher.cxx.orig	2019-02-25 12:32:13.115198757 +0000
+++ sal/rtl/cipher.cxx
@@ -26,6 +26,7 @@
 #include <cassert>
 #include <cstring>
 #include <limits>
+#include <cstdlib>
 
 #if defined LIBO_CIPHER_OPENSSL_BACKEND
 #include <openssl/evp.h>
