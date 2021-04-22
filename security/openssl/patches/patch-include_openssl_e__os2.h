$NetBSD: patch-include_openssl_e__os2.h,v 1.1 2021/04/22 09:32:40 nros Exp $

* gcc on Solaris/lllumos defines __STDC_VERSION__ in c++ mode where _Noreturn
  does not exist, this breaks c++17 builds that use openssl.

  filed upstream: https://github.com/openssl/openssl/pull/14944

--- include/openssl/e_os2.h.orig	2021-04-22 08:37:49.922502161 +0000
+++ include/openssl/e_os2.h
@@ -279,7 +279,8 @@ typedef unsigned __int64 uint64_t;
 #  define ossl_inline inline
 # endif
 
-# if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
+# if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L && \
+     !defined(__cplusplus)
 #  define ossl_noreturn _Noreturn
 # elif defined(__GNUC__) && __GNUC__ >= 2
 #  define ossl_noreturn __attribute__((noreturn))
