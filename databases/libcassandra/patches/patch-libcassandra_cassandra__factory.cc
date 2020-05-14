$NetBSD: patch-libcassandra_cassandra__factory.cc,v 1.3 2020/05/14 19:09:10 joerg Exp $

--- libcassandra/cassandra_factory.cc.orig	2010-10-10 00:59:23.000000000 +0000
+++ libcassandra/cassandra_factory.cc
@@ -63,17 +63,17 @@ CassandraFactory::CassandraFactory(const
 CassandraFactory::~CassandraFactory() {}
 
 
-tr1::shared_ptr<Cassandra> CassandraFactory::create()
+std::shared_ptr<Cassandra> CassandraFactory::create()
 {
   /* Default is Buffered Transport */
   return create(false);
 }
 
 
-tr1::shared_ptr<Cassandra> CassandraFactory::create(bool framed_transport)
+std::shared_ptr<Cassandra> CassandraFactory::create(bool framed_transport)
 {
   CassandraClient *thrift_client= createThriftClient(host, port, framed_transport);
-  tr1::shared_ptr<Cassandra> ret(new Cassandra(thrift_client, host, port));
+  std::shared_ptr<Cassandra> ret(new Cassandra(thrift_client, host, port));
   return ret;
 }
 
@@ -82,17 +82,17 @@ CassandraClient *CassandraFactory::creat
                                                       int in_port, 
                                                       bool framed_transport)
 {
-  boost::shared_ptr<TTransport> socket(new TSocket(in_host, in_port));
-  boost::shared_ptr<TTransport> transport;
+  std::shared_ptr<TTransport> socket(new TSocket(in_host, in_port));
+  std::shared_ptr<TTransport> transport;
   if (framed_transport) 
   {
-    transport= boost::shared_ptr<TTransport>(new TFramedTransport(socket));
+    transport= std::shared_ptr<TTransport>(new TFramedTransport(socket));
   }
   else
   {
-    transport= boost::shared_ptr<TTransport>(new TBufferedTransport(socket));
+    transport= std::shared_ptr<TTransport>(new TBufferedTransport(socket));
   }
-  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
+  std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
   CassandraClient *client= new(std::nothrow) CassandraClient(protocol);
 
   transport->open(); /* throws an exception */
