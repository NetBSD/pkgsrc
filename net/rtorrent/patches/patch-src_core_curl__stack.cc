$NetBSD: patch-src_core_curl__stack.cc,v 1.3 2013/09/18 16:33:08 joerg Exp $

--- src/core/curl_stack.cc.orig	2012-02-14 03:32:01.000000000 +0000
+++ src/core/curl_stack.cc
@@ -46,6 +46,14 @@
 #include "curl_socket.h"
 #include "curl_stack.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#endif
+
 namespace core {
 
 CurlStack::CurlStack() :
@@ -55,7 +63,7 @@ CurlStack::CurlStack() :
   m_ssl_verify_peer(true),
   m_dns_timeout(60) {
 
-  m_taskTimeout.slot() = std::tr1::bind(&CurlStack::receive_timeout, this);
+  m_taskTimeout.slot() = bind(&CurlStack::receive_timeout, this);
 
 #if (LIBCURL_VERSION_NUM >= 0x071000)
   curl_multi_setopt((CURLM*)m_handle, CURLMOPT_TIMERDATA, this);
