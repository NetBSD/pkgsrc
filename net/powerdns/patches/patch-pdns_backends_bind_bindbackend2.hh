$NetBSD: patch-pdns_backends_bind_bindbackend2.hh,v 1.1 2013/05/09 20:06:53 joerg Exp $

--- pdns/backends/bind/bindbackend2.hh.orig	2013-05-09 15:23:01.000000000 +0000
+++ pdns/backends/bind/bindbackend2.hh
@@ -90,7 +90,7 @@ public:
   //! configure how often this domain should be checked for changes (on disk)
   void setCheckInterval(time_t seconds);
 
-  shared_ptr<vector<Bind2DNSRecord> > d_records;  //!< the actual records belonging to this domain
+  boost::shared_ptr<vector<Bind2DNSRecord> > d_records;  //!< the actual records belonging to this domain
 private:
   time_t getCtime();
   time_t d_checkinterval;
@@ -130,7 +130,7 @@ public:
     id_zone_map_t id_zone_map;
   };
 
-  static void insert(shared_ptr<State> stage, int id, const string &qname, const QType &qtype, const string &content, int ttl, int prio);  
+  static void insert(boost::shared_ptr<State> stage, int id, const string &qname, const QType &qtype, const string &content, int ttl, int prio);  
   void rediscover(string *status=0);
 
   bool isMaster(const string &name, const string &ip);
@@ -153,7 +153,7 @@ private:
 
     handle();
 
-    shared_ptr<vector<Bind2DNSRecord> > d_records;
+    boost::shared_ptr<vector<Bind2DNSRecord> > d_records;
     vector<Bind2DNSRecord>::const_iterator d_iter, d_end_iter;
 
     vector<Bind2DNSRecord>::const_iterator d_qname_iter;
@@ -176,10 +176,10 @@ private:
   };
 
 
-  static shared_ptr<State> s_state;
+  static boost::shared_ptr<State> s_state;
   static pthread_mutex_t s_state_lock;               //!< lock protecting ???
   static pthread_mutex_t s_state_swap_lock;               //!< lock protecting ???
-  static shared_ptr<State> getState();
+  static boost::shared_ptr<State> getState();
 
   static int s_first;                                  //!< this is raised on construction to prevent multiple instances of us being generated
 
