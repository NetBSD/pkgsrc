$NetBSD: patch-libcassandra_cassandra.cc,v 1.2 2020/05/14 19:09:10 joerg Exp $

--- libcassandra/cassandra.cc.orig	2010-10-10 00:59:23.000000000 +0000
+++ libcassandra/cassandra.cc
@@ -17,6 +17,8 @@
 #include "libcassandra/keyspace.h"
 #include "libcassandra/exception.h"
 
+#include <memory>
+
 using namespace std;
 using namespace org::apache::cassandra;
 using namespace libcassandra;
@@ -85,17 +87,17 @@ set<string> Cassandra::getKeyspaces()
 }
 
 
-tr1::shared_ptr<Keyspace> Cassandra::getKeyspace(const string &name)
+shared_ptr<Keyspace> Cassandra::getKeyspace(const string &name)
 {
   return getKeyspace(name, DCQUORUM);
 }
 
 
-tr1::shared_ptr<Keyspace> Cassandra::getKeyspace(const string &name,
+shared_ptr<Keyspace> Cassandra::getKeyspace(const string &name,
                                                  ConsistencyLevel level)
 {
   string keymap_name= buildKeyspaceMapName(name, level);
-  map<string, tr1::shared_ptr<Keyspace> >::iterator key_it= keyspace_map.find(keymap_name);
+  map<string, shared_ptr<Keyspace> >::iterator key_it= keyspace_map.find(keymap_name);
   if (key_it == keyspace_map.end())
   {
     getKeyspaces();
@@ -104,7 +106,7 @@ tr1::shared_ptr<Keyspace> Cassandra::get
     {
       map< string, map<string, string> > keyspace_desc;
       thrift_client->describe_keyspace(keyspace_desc, name);
-      tr1::shared_ptr<Keyspace> ret(new Keyspace(this, name, keyspace_desc, level));
+      shared_ptr<Keyspace> ret(new Keyspace(this, name, keyspace_desc, level));
       keyspace_map[keymap_name]= ret;
     }
     else
@@ -117,7 +119,7 @@ tr1::shared_ptr<Keyspace> Cassandra::get
 }
 
 
-void Cassandra::removeKeyspace(tr1::shared_ptr<Keyspace> k)
+void Cassandra::removeKeyspace(shared_ptr<Keyspace> k)
 {
   string keymap_name= buildKeyspaceMapName(k->getName(), k->getConsistencyLevel());
   keyspace_map.erase(keymap_name);
