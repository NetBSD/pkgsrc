$NetBSD: patch-syncres.hh,v 1.1 2013/06/10 18:59:09 joerg Exp $

--- syncres.hh.orig	2013-05-10 14:51:02.000000000 +0000
+++ syncres.hh
@@ -321,7 +321,7 @@ public:
   typedef map<string, AuthDomain, CIStringCompare> domainmap_t;
   
 
-  typedef Throttle<tuple<ComboAddress,string,uint16_t> > throttle_t;
+  typedef Throttle<boost::tuple<ComboAddress,string,uint16_t> > throttle_t;
   
   struct timeval d_now;
   static unsigned int s_maxnegttl;
