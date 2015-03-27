$NetBSD: patch-pdns_pdns_recursor.cc,v 1.4 2015/03/27 23:37:52 rodent Exp $

Resolve boost symbol ambiguity.
--- pdns/pdns_recursor.cc.orig	2015-03-02 13:17:12.000000000 +0000
+++ pdns/pdns_recursor.cc
@@ -80,9 +80,9 @@ uint64_t g_latencyStatSize;
 bool g_logCommonErrors;
 bool g_anyToTcp;
 uint16_t g_udpTruncationThreshold;
-__thread shared_ptr<RecursorLua>* t_pdl;
+__thread boost::shared_ptr<RecursorLua>* t_pdl;
 __thread RemoteKeeper* t_remotes;
-__thread shared_ptr<Regex>* t_traceRegex;
+__thread boost::shared_ptr<Regex>* t_traceRegex;
 
 RecursorControlChannel s_rcc; // only active in thread 0
 
@@ -152,7 +152,7 @@ struct DNSComboWriter {
   ComboAddress d_remote;
   bool d_tcp;
   int d_socket;
-  shared_ptr<TCPConnection> d_tcpConnection;
+  boost::shared_ptr<TCPConnection> d_tcpConnection;
 };
 
 
@@ -606,7 +606,7 @@ void startDoResolve(void *p)
             IpToU32(i->content, &ip);
             pw.xfr32BitInt(htonl(ip));
           } else {
-            shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(i->qtype.getCode(), i->qclass, i->content)); 
+            boost::shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(i->qtype.getCode(), i->qclass, i->content)); 
             drc->toPacket(pw);
           }
           if(pw.size() > maxanswersize) {
@@ -748,7 +748,7 @@ void makeControlChannelSocket(int proces
 
 void handleRunningTCPQuestion(int fd, FDMultiplexer::funcparam_t& var)
 {
-  shared_ptr<TCPConnection> conn=any_cast<shared_ptr<TCPConnection> >(var);
+  boost::shared_ptr<TCPConnection> conn=any_cast<boost::shared_ptr<TCPConnection> >(var);
 
   if(conn->state==TCPConnection::BYTE0) {
     int bytes=recv(conn->getFD(), conn->data, 2, 0);
@@ -852,7 +852,7 @@ void handleNewTCPQuestion(int fd, FDMult
     }
     
     Utility::setNonBlocking(newsock);
-    shared_ptr<TCPConnection> tc(new TCPConnection(newsock, addr));
+    boost::shared_ptr<TCPConnection> tc(new TCPConnection(newsock, addr));
     tc->state=TCPConnection::BYTE0;
     
     t_fdm->addReadFD(tc->getFD(), handleRunningTCPQuestion, tc);
@@ -1582,7 +1582,7 @@ string* doReloadLuaScript()
       return new string("unloaded\n");
     }
     else {
-      *t_pdl = shared_ptr<RecursorLua>(new RecursorLua(fname));
+      *t_pdl = boost::shared_ptr<RecursorLua>(new RecursorLua(fname));
     }
   }
   catch(std::exception& e) {
@@ -1610,7 +1610,7 @@ try
     return new string("unset\n");
   }
   else {
-    (*t_traceRegex) = shared_ptr<Regex>(new Regex(newRegex));
+    (*t_traceRegex) = boost::shared_ptr<Regex>(new Regex(newRegex));
     return new string("ok\n");
   }
 }
@@ -1939,11 +1939,11 @@ try
   
   L<<Logger::Warning<<"Done priming cache with root hints"<<endl;
     
-  t_pdl = new shared_ptr<RecursorLua>();
+  t_pdl = new boost::shared_ptr<RecursorLua>();
   
   try {
     if(!::arg()["lua-dns-script"].empty()) {
-      *t_pdl = shared_ptr<RecursorLua>(new RecursorLua(::arg()["lua-dns-script"]));
+      *t_pdl = boost::shared_ptr<RecursorLua>(new RecursorLua(::arg()["lua-dns-script"]));
       L<<Logger::Warning<<"Loaded 'lua' script from '"<<::arg()["lua-dns-script"]<<"'"<<endl;
     }
     
@@ -1953,7 +1953,7 @@ try
     exit(99);
   }
   
-  t_traceRegex = new shared_ptr<Regex>();
+  t_traceRegex = new boost::shared_ptr<Regex>();
   
   
   t_remotes = new RemoteKeeper();
@@ -2011,7 +2011,7 @@ try
       expired_t expired=t_fdm->getTimeouts(g_now);
         
       for(expired_t::iterator i=expired.begin() ; i != expired.end(); ++i) {
-        shared_ptr<TCPConnection> conn=any_cast<shared_ptr<TCPConnection> >(i->second);
+        boost::shared_ptr<TCPConnection> conn=any_cast<boost::shared_ptr<TCPConnection> >(i->second);
         if(g_logCommonErrors)
           L<<Logger::Warning<<"Timeout from remote TCP client "<< conn->d_remote.toString() <<endl;
         t_fdm->removeReadFD(i->first);
