$NetBSD: patch-src_ssl_tls__record.h,v 1.1 2016/05/31 21:36:17 joerg Exp $

--- src/ssl/tls_record.h.orig	2016-05-25 20:40:33.153653548 +0000
+++ src/ssl/tls_record.h
@@ -17,7 +17,7 @@
 
 #if defined(BOTAN_USE_STD_TR1)
 
-#if defined(BOTAN_BUILD_COMPILER_IS_MSVC)
+#if defined(BOTAN_BUILD_COMPILER_IS_MSVC) || defined(_LIBCPP_VERSION)
     #include <functional>
 #else
     #include <tr1/functional>
@@ -31,7 +31,13 @@
 
 namespace Botan {
 
+#if defined(_LIBCPP_VERSION)
+using namespace std::placeholders;
+using std::function;
+#else
 using namespace std::tr1::placeholders;
+using std::tr1::function;
+#endif
 
 /**
 * TLS Record Writer
@@ -52,7 +58,7 @@ class BOTAN_DLL Record_Writer
 
       void reset();
 
-      Record_Writer(std::tr1::function<void (const byte[], size_t)> output_fn);
+      Record_Writer(function<void (const byte[], size_t)> output_fn);
 
       ~Record_Writer() { delete mac; }
    private:
@@ -60,7 +66,7 @@ class BOTAN_DLL Record_Writer
       void send_record(byte type, byte major, byte minor,
                        const byte input[], size_t length);
 
-      std::tr1::function<void (const byte[], size_t)> output_fn;
+      function<void (const byte[], size_t)> output_fn;
       Pipe cipher;
       MessageAuthenticationCode* mac;
 
