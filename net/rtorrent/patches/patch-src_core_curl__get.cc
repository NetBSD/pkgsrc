$NetBSD: patch-src_core_curl__get.cc,v 1.3 2013/09/18 16:33:08 joerg Exp $

--- src/core/curl_get.cc.orig	2012-02-14 03:32:01.000000000 +0000
+++ src/core/curl_get.cc
@@ -45,6 +45,14 @@
 #include "curl_get.h"
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
 
 size_t
@@ -82,7 +90,7 @@ CurlGet::start() {
 
     // Normally libcurl should handle the timeout. But sometimes that doesn't
     // work right so we do a fallback timeout that just aborts the transfer.
-    m_taskTimeout.slot() = std::tr1::bind(&CurlGet::receive_timeout, this);
+    m_taskTimeout.slot() = bind(&CurlGet::receive_timeout, this);
     priority_queue_erase(&taskScheduler, &m_taskTimeout);
     priority_queue_insert(&taskScheduler, &m_taskTimeout, cachedTime + rak::timer::from_seconds(m_timeout + 5));
   }
