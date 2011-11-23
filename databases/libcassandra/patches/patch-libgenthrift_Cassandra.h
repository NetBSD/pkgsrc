$NetBSD: patch-libgenthrift_Cassandra.h,v 1.1 2011/11/23 15:39:21 joerg Exp $

--- libgenthrift/Cassandra.h.orig	2011-11-23 14:36:26.000000000 +0000
+++ libgenthrift/Cassandra.h
@@ -2609,7 +2609,7 @@ class CassandraProcessor : virtual publi
     processMap_["describe_splits"] = &CassandraProcessor::process_describe_splits;
   }
 
-  virtual bool process(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot);
+  virtual bool process(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot, void* connectionContext);
   virtual ~CassandraProcessor() {}
 };
 
