$NetBSD: patch-pdns_htimer.cc,v 1.3 2015/03/27 23:37:52 rodent Exp $

Resolve boost symbol ambiguity.
--- pdns/htimer.cc.orig	2015-03-02 13:17:11.000000000 +0000
+++ pdns/htimer.cc
@@ -128,7 +128,7 @@ int main()
     HTimerSentinel hts=htloop.getSentinel();
     for(int i=0; i < 1000; ++i)
     {
-      shared_ptr<char> p(shared_ptr<char>(new char));
+      boost::shared_ptr<char> p(boost::shared_ptr<char>(new char));
     }
   }
 
