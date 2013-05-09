$NetBSD: patch-src_core_curl__stack.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/core/curl_stack.cc.orig	2013-05-03 22:43:15.000000000 +0000
+++ src/core/curl_stack.cc
@@ -55,7 +55,7 @@ CurlStack::CurlStack() :
   m_ssl_verify_peer(true),
   m_dns_timeout(60) {
 
-  m_taskTimeout.slot() = std::tr1::bind(&CurlStack::receive_timeout, this);
+  m_taskTimeout.slot() = bind(&CurlStack::receive_timeout, this);
 
 #if (LIBCURL_VERSION_NUM >= 0x071000)
   curl_multi_setopt((CURLM*)m_handle, CURLMOPT_TIMERDATA, this);
