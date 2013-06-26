$NetBSD: patch-rec__channel__rec.cc,v 1.1 2013/06/26 15:52:22 joerg Exp $

--- rec_channel_rec.cc.orig	2010-09-21 16:22:09.000000000 +0000
+++ rec_channel_rec.cc
@@ -27,7 +27,7 @@ using namespace std;
 #include "namespaces.hh"
 map<string, const uint32_t*> d_get32bitpointers;
 map<string, const uint64_t*> d_get64bitpointers;
-map<string, function< uint32_t() > >  d_get32bitmembers;
+map<string, boost::function< uint32_t() > >  d_get32bitmembers;
 
 void addGetStat(const string& name, const uint32_t* place)
 {
@@ -37,7 +37,7 @@ void addGetStat(const string& name, cons
 {
   d_get64bitpointers[name]=place;
 }
-void addGetStat(const string& name, function<uint32_t ()> f ) 
+void addGetStat(const string& name, boost::function<uint32_t ()> f ) 
 {
   d_get32bitmembers[name]=f;
 }
@@ -61,7 +61,7 @@ string getAllStats()
   string ret;
   pair<string, const uint32_t*> the32bits;
   pair<string, const uint64_t*> the64bits;
-  pair<string, function< uint32_t() > >  the32bitmembers;
+  pair<string, boost::function< uint32_t() > >  the32bitmembers;
   BOOST_FOREACH(the32bits, d_get32bitpointers) {
     ret += the32bits.first + "\t" + lexical_cast<string>(*the32bits.second) + "\n";
   }
