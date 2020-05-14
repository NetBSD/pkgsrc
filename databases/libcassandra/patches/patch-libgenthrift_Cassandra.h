$NetBSD: patch-libgenthrift_Cassandra.h,v 1.3 2020/05/14 19:09:10 joerg Exp $

--- libgenthrift/Cassandra.h.orig	2010-10-10 00:59:23.000000000 +0000
+++ libgenthrift/Cassandra.h
@@ -2468,22 +2468,22 @@ class Cassandra_describe_splits_presult 
 
 class CassandraClient : virtual public CassandraIf {
  public:
-  CassandraClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
+  CassandraClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
     piprot_(prot),
     poprot_(prot) {
     iprot_ = prot.get();
     oprot_ = prot.get();
   }
-  CassandraClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
+  CassandraClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
     piprot_(iprot),
     poprot_(oprot) {
     iprot_ = iprot.get();
     oprot_ = oprot.get();
   }
-  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
+  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
     return piprot_;
   }
-  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
+  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
     return poprot_;
   }
   void login(const std::string& keyspace, const AuthenticationRequest& auth_request);
@@ -2550,15 +2550,15 @@ class CassandraClient : virtual public C
   void send_describe_splits(const std::string& start_token, const std::string& end_token, const int32_t keys_per_split);
   void recv_describe_splits(std::vector<std::string> & _return);
  protected:
-  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
-  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
+  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
+  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
   ::apache::thrift::protocol::TProtocol* iprot_;
   ::apache::thrift::protocol::TProtocol* oprot_;
 };
 
 class CassandraProcessor : virtual public ::apache::thrift::TProcessor {
  protected:
-  boost::shared_ptr<CassandraIf> iface_;
+  std::shared_ptr<CassandraIf> iface_;
   virtual bool process_fn(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid);
  private:
   std::map<std::string, void (CassandraProcessor::*)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*)> processMap_;
@@ -2584,7 +2584,7 @@ class CassandraProcessor : virtual publi
   void process_describe_keyspace(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot);
   void process_describe_splits(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot);
  public:
-  CassandraProcessor(boost::shared_ptr<CassandraIf> iface) :
+  CassandraProcessor(std::shared_ptr<CassandraIf> iface) :
     iface_(iface) {
     processMap_["login"] = &CassandraProcessor::process_login;
     processMap_["get"] = &CassandraProcessor::process_get;
@@ -2609,19 +2609,19 @@ class CassandraProcessor : virtual publi
     processMap_["describe_splits"] = &CassandraProcessor::process_describe_splits;
   }
 
-  virtual bool process(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot);
+  virtual bool process(std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot, void* connectionContext);
   virtual ~CassandraProcessor() {}
 };
 
 class CassandraMultiface : virtual public CassandraIf {
  public:
-  CassandraMultiface(std::vector<boost::shared_ptr<CassandraIf> >& ifaces) : ifaces_(ifaces) {
+  CassandraMultiface(std::vector<std::shared_ptr<CassandraIf> >& ifaces) : ifaces_(ifaces) {
   }
   virtual ~CassandraMultiface() {}
  protected:
-  std::vector<boost::shared_ptr<CassandraIf> > ifaces_;
+  std::vector<std::shared_ptr<CassandraIf> > ifaces_;
   CassandraMultiface() {}
-  void add(boost::shared_ptr<CassandraIf> iface) {
+  void add(std::shared_ptr<CassandraIf> iface) {
     ifaces_.push_back(iface);
   }
  public:
@@ -2689,6 +2689,7 @@ class CassandraMultiface : virtual publi
         ifaces_[i]->get_count(keyspace, key, column_parent, consistency_level);
       }
     }
+    return 0;
   }
 
   void get_range_slice(std::vector<KeySlice> & _return, const std::string& keyspace, const ColumnParent& column_parent, const SlicePredicate& predicate, const std::string& start_key, const std::string& finish_key, const int32_t row_count, const ConsistencyLevel consistency_level) {
