$NetBSD: patch-rec__channel__rec.cc,v 1.2 2015/06/10 14:22:29 fhajny Exp $

Straighten Boost namespace.

--- rec_channel_rec.cc.orig	2015-04-21 13:02:57.000000000 +0000
+++ rec_channel_rec.cc
@@ -31,7 +31,7 @@ pthread_mutex_t g_carbon_config_lock=PTH
 
 map<string, const uint32_t*> d_get32bitpointers;
 map<string, const uint64_t*> d_get64bitpointers;
-map<string, function< uint32_t() > >  d_get32bitmembers;
+map<string, boost::function< uint32_t() > >  d_get32bitmembers;
 
 void addGetStat(const string& name, const uint32_t* place)
 {
@@ -41,7 +41,7 @@ void addGetStat(const string& name, cons
 {
   d_get64bitpointers[name]=place;
 }
-void addGetStat(const string& name, function<uint32_t ()> f ) 
+void addGetStat(const string& name, boost::function<uint32_t ()> f ) 
 {
   d_get32bitmembers[name]=f;
 }
@@ -66,7 +66,7 @@ map<string,string> getAllStatsMap()
   
   pair<string, const uint32_t*> the32bits;
   pair<string, const uint64_t*> the64bits;
-  pair<string, function< uint32_t() > >  the32bitmembers;
+  pair<string, boost::function< uint32_t() > >  the32bitmembers;
   
   BOOST_FOREACH(the32bits, d_get32bitpointers) {
     ret.insert(make_pair(the32bits.first, lexical_cast<string>(*the32bits.second)));
