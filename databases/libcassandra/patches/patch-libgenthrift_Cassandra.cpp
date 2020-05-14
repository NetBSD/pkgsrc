$NetBSD: patch-libgenthrift_Cassandra.cpp,v 1.2 2020/05/14 19:09:10 joerg Exp $

--- libgenthrift/Cassandra.cpp.orig	2010-10-10 00:59:23.000000000 +0000
+++ libgenthrift/Cassandra.cpp
@@ -6761,7 +6761,8 @@ void CassandraClient::recv_describe_spli
   throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "describe_splits failed: unknown result");
 }
 
-bool CassandraProcessor::process(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot) {
+bool CassandraProcessor::process(std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot, void* connectionContext) {
+  (void)&connectionContext;
 
   ::apache::thrift::protocol::TProtocol* iprot = piprot.get();
   ::apache::thrift::protocol::TProtocol* oprot = poprot.get();
