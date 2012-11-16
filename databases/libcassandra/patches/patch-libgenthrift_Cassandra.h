$NetBSD: patch-libgenthrift_Cassandra.h,v 1.2 2012/11/16 00:40:18 joerg Exp $

--- libgenthrift/Cassandra.h.orig	2010-10-10 00:59:23.000000000 +0000
+++ libgenthrift/Cassandra.h
@@ -2609,7 +2609,7 @@ class CassandraProcessor : virtual publi
     processMap_["describe_splits"] = &CassandraProcessor::process_describe_splits;
   }
 
-  virtual bool process(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot);
+  virtual bool process(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot, void* connectionContext);
   virtual ~CassandraProcessor() {}
 };
 
@@ -2689,6 +2689,7 @@ class CassandraMultiface : virtual publi
         ifaces_[i]->get_count(keyspace, key, column_parent, consistency_level);
       }
     }
+    return 0;
   }
 
   void get_range_slice(std::vector<KeySlice> & _return, const std::string& keyspace, const ColumnParent& column_parent, const SlicePredicate& predicate, const std::string& start_key, const std::string& finish_key, const int32_t row_count, const ConsistencyLevel consistency_level) {
