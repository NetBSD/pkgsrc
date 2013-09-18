$NetBSD: patch-src_core_http__queue.cc,v 1.3 2013/09/18 16:33:08 joerg Exp $

--- src/core/http_queue.cc.orig	2012-02-14 03:32:01.000000000 +0000
+++ src/core/http_queue.cc
@@ -46,6 +46,14 @@
 #include "http_queue.h"
 #include "curl_get.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#endif
+
 namespace core {
 
 HttpQueue::iterator
@@ -58,8 +66,8 @@ HttpQueue::insert(const std::string& url
 
   iterator itr = Base::insert(end(), h.get());
 
-  h->signal_done().push_back(std::tr1::bind(&HttpQueue::erase, this, itr));
-  h->signal_failed().push_back(std::tr1::bind(&HttpQueue::erase, this, itr));
+  h->signal_done().push_back(bind(&HttpQueue::erase, this, itr));
+  h->signal_failed().push_back(bind(&HttpQueue::erase, this, itr));
 
   (*itr)->start();
 
