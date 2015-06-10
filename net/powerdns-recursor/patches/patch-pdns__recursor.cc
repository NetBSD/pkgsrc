$NetBSD: patch-pdns__recursor.cc,v 1.4 2015/06/10 14:22:29 fhajny Exp $

Straighten Boost namespace.
Cast to int so we use the correct overload.

--- pdns_recursor.cc.orig	2015-04-21 13:02:57.000000000 +0000
+++ pdns_recursor.cc
@@ -80,12 +80,12 @@ uint64_t g_latencyStatSize;
 bool g_logCommonErrors;
 bool g_anyToTcp;
 uint16_t g_udpTruncationThreshold;
-__thread shared_ptr<RecursorLua>* t_pdl;
+__thread boost::shared_ptr<RecursorLua>* t_pdl;
 
 __thread addrringbuf_t* t_remotes, *t_servfailremotes, *t_largeanswerremotes;
 
 __thread boost::circular_buffer<pair<std::string, uint16_t> >* t_queryring, *t_servfailqueryring;
-__thread shared_ptr<Regex>* t_traceRegex;
+__thread boost::shared_ptr<Regex>* t_traceRegex;
 
 RecursorControlChannel s_rcc; // only active in thread 0
 
@@ -169,7 +169,7 @@ struct DNSComboWriter {
   ComboAddress d_remote, d_local;
   bool d_tcp;
   int d_socket;
-  shared_ptr<TCPConnection> d_tcpConnection;
+  boost::shared_ptr<TCPConnection> d_tcpConnection;
 };
 
 
@@ -661,7 +661,7 @@ void startDoResolve(void *p)
             IpToU32(i->content, &ip);
             pw.xfr32BitInt(htonl(ip));
           } else {
-            shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(i->qtype.getCode(), i->qclass, i->content)); 
+            boost::shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(i->qtype.getCode(), i->qclass, i->content)); 
             drc->toPacket(pw);
           }
           if(pw.size() > maxanswersize) {
@@ -814,7 +814,7 @@ void makeControlChannelSocket(int proces
 
 void handleRunningTCPQuestion(int fd, FDMultiplexer::funcparam_t& var)
 {
-  shared_ptr<TCPConnection> conn=any_cast<shared_ptr<TCPConnection> >(var);
+  boost::shared_ptr<TCPConnection> conn=any_cast<boost::shared_ptr<TCPConnection> >(var);
 
   if(conn->state==TCPConnection::BYTE0) {
     int bytes=recv(conn->getFD(), conn->data, 2, 0);
@@ -919,7 +919,7 @@ void handleNewTCPQuestion(int fd, FDMult
     }
     
     Utility::setNonBlocking(newsock);
-    shared_ptr<TCPConnection> tc(new TCPConnection(newsock, addr));
+    boost::shared_ptr<TCPConnection> tc(new TCPConnection(newsock, addr));
     tc->state=TCPConnection::BYTE0;
     
     t_fdm->addReadFD(tc->getFD(), handleRunningTCPQuestion, tc);
@@ -1081,7 +1081,7 @@ void handleNewUDPQuestion(int fd, FDMult
 }
 
 
-typedef vector<pair<int, function< void(int, any&) > > > deferredAdd_t;
+typedef vector<pair<int, boost::function< void(int, any&) > > > deferredAdd_t;
 deferredAdd_t deferredAdd;
 
 void makeTCPServerSockets()
@@ -1273,7 +1273,7 @@ void doStats(void)
     
     time_t now = time(0);
     if(lastOutputTime && lastQueryCount && now != lastOutputTime) {
-      L<<Logger::Warning<<"stats: "<< (SyncRes::s_queries - lastQueryCount) / (now - lastOutputTime) <<" qps (average over "<< (now - lastOutputTime) << " seconds)"<<endl;
+      L<<Logger::Warning<<"stats: "<< (SyncRes::s_queries - lastQueryCount) / (now - lastOutputTime) <<" qps (average over "<< (int)(now - lastOutputTime) << " seconds)"<<endl;
     }
     lastOutputTime = now;
     lastQueryCount = SyncRes::s_queries;
@@ -1734,7 +1734,7 @@ string* doReloadLuaScript()
       return new string("unloaded\n");
     }
     else {
-      *t_pdl = shared_ptr<RecursorLua>(new RecursorLua(fname));
+      *t_pdl = boost::shared_ptr<RecursorLua>(new RecursorLua(fname));
     }
   }
   catch(std::exception& e) {
@@ -1762,7 +1762,7 @@ try
     return new string("unset\n");
   }
   else {
-    (*t_traceRegex) = shared_ptr<Regex>(new Regex(newRegex));
+    (*t_traceRegex) = boost::shared_ptr<Regex>(new Regex(newRegex));
     return new string("ok\n");
   }
 }
@@ -2096,11 +2096,11 @@ try
   
   L<<Logger::Warning<<"Done priming cache with root hints"<<endl;
     
-  t_pdl = new shared_ptr<RecursorLua>();
+  t_pdl = new boost::shared_ptr<RecursorLua>();
   
   try {
     if(!::arg()["lua-dns-script"].empty()) {
-      *t_pdl = shared_ptr<RecursorLua>(new RecursorLua(::arg()["lua-dns-script"]));
+      *t_pdl = boost::shared_ptr<RecursorLua>(new RecursorLua(::arg()["lua-dns-script"]));
       L<<Logger::Warning<<"Loaded 'lua' script from '"<<::arg()["lua-dns-script"]<<"'"<<endl;
     }
   }
@@ -2109,7 +2109,7 @@ try
     _exit(99);
   }
   
-  t_traceRegex = new shared_ptr<Regex>();
+  t_traceRegex = new boost::shared_ptr<Regex>();
   unsigned int ringsize=::arg().asNum("stats-ringbuffer-entries") / g_numWorkerThreads;
   if(ringsize) {
     t_remotes = new addrringbuf_t();
@@ -2176,7 +2176,7 @@ try
       expired_t expired=t_fdm->getTimeouts(g_now);
         
       for(expired_t::iterator i=expired.begin() ; i != expired.end(); ++i) {
-        shared_ptr<TCPConnection> conn=any_cast<shared_ptr<TCPConnection> >(i->second);
+        boost::shared_ptr<TCPConnection> conn=any_cast<boost::shared_ptr<TCPConnection> >(i->second);
         if(g_logCommonErrors)
           L<<Logger::Warning<<"Timeout from remote TCP client "<< conn->d_remote.toString() <<endl;
         t_fdm->removeReadFD(i->first);
