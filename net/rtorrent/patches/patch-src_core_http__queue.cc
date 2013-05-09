$NetBSD: patch-src_core_http__queue.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/core/http_queue.cc.orig	2013-05-03 22:47:12.000000000 +0000
+++ src/core/http_queue.cc
@@ -58,8 +58,8 @@ HttpQueue::insert(const std::string& url
 
   iterator itr = Base::insert(end(), h.get());
 
-  h->signal_done().push_back(std::tr1::bind(&HttpQueue::erase, this, itr));
-  h->signal_failed().push_back(std::tr1::bind(&HttpQueue::erase, this, itr));
+  h->signal_done().push_back(bind(&HttpQueue::erase, this, itr));
+  h->signal_failed().push_back(bind(&HttpQueue::erase, this, itr));
 
   (*itr)->start();
 
