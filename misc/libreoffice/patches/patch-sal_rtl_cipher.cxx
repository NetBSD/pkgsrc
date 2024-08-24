$NetBSD: patch-sal_rtl_cipher.cxx,v 1.3 2024/08/24 02:57:35 ryoon Exp $

include <cstdlib> for std::free()

--- sal/rtl/cipher.cxx.orig	2024-08-22 12:14:58.615013249 +0000
+++ sal/rtl/cipher.cxx
@@ -24,6 +24,7 @@
 #include <rtl/alloc.h>
 #include <rtl/cipher.h>
 #include <algorithm>
+#include <cstdlib>
 
 #if defined LIBO_CIPHER_OPENSSL_BACKEND
 #include <o3tl/safeint.hxx>
