$NetBSD: patch-pdns__recursor.cc,v 1.3 2013/06/26 15:52:22 joerg Exp $

Cast to int so we use the correct overload.
Fix C++ semantic whitespace.

Caution: this file is also SUBST'd at pre-configure time to insert
more C++ semantic whitespace around the VERSION macro. Don't roll
those changes back into the pkgsrc patch as one of them contains
an rcsid string. (sigh)

--- pdns_recursor.cc.orig	2010-09-21 16:22:09.000000000 +0000
+++ pdns_recursor.cc
@@ -76,7 +76,7 @@ __thread unsigned int t_id;
 unsigned int g_maxTCPPerClient;
 unsigned int g_networkTimeoutMsec;
 bool g_logCommonErrors;
-__thread shared_ptr<PowerDNSLua>* t_pdl;
+__thread boost::shared_ptr<PowerDNSLua>* t_pdl;
 __thread RemoteKeeper* t_remotes;
 
 RecursorControlChannel s_rcc; // only active in thread 0
@@ -147,7 +147,7 @@ struct DNSComboWriter {
   ComboAddress d_remote;
   bool d_tcp;
   int d_socket;
-  shared_ptr<TCPConnection> d_tcpConnection;
+  boost::shared_ptr<TCPConnection> d_tcpConnection;
 };
 
 
@@ -551,7 +551,7 @@ void startDoResolve(void *p)
             IpToU32(i->content, &ip);
             pw.xfr32BitInt(htonl(ip));
           } else {
-            shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(i->qtype.getCode(), i->qclass, i->content)); 
+            boost::shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(i->qtype.getCode(), i->qclass, i->content)); 
             drc->toPacket(pw);
           }
           if(!dc->d_tcp && pw.size() > maxudpsize) {
@@ -685,7 +685,7 @@ void makeControlChannelSocket()
 
 void handleRunningTCPQuestion(int fd, FDMultiplexer::funcparam_t& var)
 {
-  shared_ptr<TCPConnection> conn=any_cast<shared_ptr<TCPConnection> >(var);
+  boost::shared_ptr<TCPConnection> conn=any_cast<boost::shared_ptr<TCPConnection> >(var);
 
   if(conn->state==TCPConnection::BYTE0) {
     int bytes=recv(conn->getFD(), conn->data, 2, 0);
@@ -784,7 +784,7 @@ void handleNewTCPQuestion(int fd, FDMult
     }
     
     Utility::setNonBlocking(newsock);
-    shared_ptr<TCPConnection> tc(new TCPConnection(newsock, addr));
+    boost::shared_ptr<TCPConnection> tc(new TCPConnection(newsock, addr));
     tc->state=TCPConnection::BYTE0;
     
     t_fdm->addReadFD(tc->getFD(), handleRunningTCPQuestion, tc);
@@ -882,7 +882,7 @@ void handleNewUDPQuestion(int fd, FDMult
 }
 
 
-typedef vector<pair<int, function< void(int, any&) > > > deferredAdd_t;
+typedef vector<pair<int, boost::function< void(int, any&) > > > deferredAdd_t;
 deferredAdd_t deferredAdd;
 
 void makeTCPServerSockets()
@@ -1065,7 +1065,7 @@ void doStats(void)
     
     time_t now = time(0);
     if(lastOutputTime && lastQueryCount && now != lastOutputTime) {
-      L<<Logger::Warning<<"stats: "<< (SyncRes::s_queries - lastQueryCount) / (now - lastOutputTime) <<" qps (average over "<< (now - lastOutputTime) << " seconds)"<<endl;
+      L<<Logger::Warning<<"stats: "<< (SyncRes::s_queries - lastQueryCount) / (now - lastOutputTime) <<" qps (average over "<< (int)(now - lastOutputTime) << " seconds)"<<endl;
     }
     lastOutputTime = now;
     lastQueryCount = SyncRes::s_queries;
@@ -1485,7 +1485,7 @@ void* doReloadLuaScript()
       L<<Logger::Error<<t_id<<" Unloaded current lua script"<<endl;
     }
     else {
-      *t_pdl = shared_ptr<PowerDNSLua>(new PowerDNSLua(fname));
+      *t_pdl = boost::shared_ptr<PowerDNSLua>(new PowerDNSLua(fname));
     }
   }
   catch(std::exception& e) {
@@ -1592,9 +1592,9 @@ int serviceMain(int argc, char*argv[])
       L<<Logger::Error<<"Unknown logging facility "<<::arg().asNum("logging-facility") <<endl;
   }
 
-  L<<Logger::Warning<<"PowerDNS recursor "<<VERSION<<" (C) 2001-2010 PowerDNS.COM BV ("<<__DATE__", "__TIME__;
+  L<<Logger::Warning<<"PowerDNS recursor "<<VERSION<<" (C) 2001-2010 PowerDNS.COM BV ("<<__DATE__ << ", " << __TIME__;
 #ifdef __GNUC__
-  L<<", gcc "__VERSION__;
+  L<<", gcc " << __VERSION__;
 #endif // add other compilers here
 #ifdef _MSC_VER
   L<<", MSVC "<<_MSC_VER;
@@ -1776,11 +1776,11 @@ try
   L<<Logger::Warning<<"Done priming cache with root hints"<<endl;
     
   t_RC->d_followRFC2181=::arg().mustDo("auth-can-lower-ttl");
-  t_pdl = new shared_ptr<PowerDNSLua>();
+  t_pdl = new boost::shared_ptr<PowerDNSLua>();
   
   try {
     if(!::arg()["lua-dns-script"].empty()) {
-      *t_pdl = shared_ptr<PowerDNSLua>(new PowerDNSLua(::arg()["lua-dns-script"]));
+      *t_pdl = boost::shared_ptr<PowerDNSLua>(new PowerDNSLua(::arg()["lua-dns-script"]));
       L<<Logger::Warning<<"Loaded 'lua' script from '"<<::arg()["lua-dns-script"]<<"'"<<endl;
     }
     
@@ -1832,7 +1832,7 @@ try
       expired_t expired=t_fdm->getTimeouts(g_now);
         
       for(expired_t::iterator i=expired.begin() ; i != expired.end(); ++i) {
-        shared_ptr<TCPConnection> conn=any_cast<shared_ptr<TCPConnection> >(i->second);
+        boost::shared_ptr<TCPConnection> conn=any_cast<boost::shared_ptr<TCPConnection> >(i->second);
         if(g_logCommonErrors)
           L<<Logger::Warning<<"Timeout from remote TCP client "<< conn->d_remote.toString() <<endl;
         t_fdm->removeReadFD(i->first);
@@ -1990,7 +1990,7 @@ int main(int argc, char **argv) 
     
 
     ::arg().setCmd("help","Provide a helpful message");
-    ::arg().setCmd("version","Print version string ("VERSION")");
+    ::arg().setCmd("version","Print version string (" VERSION ")");
     ::arg().setCmd("config","Output blank configuration");
     L.toConsole(Logger::Info);
     ::arg().laxParse(argc,argv); // do a lax parse
@@ -2017,7 +2017,7 @@ int main(int argc, char **argv) 
       exit(99);
     }
     if(::arg().mustDo("version")) {
-      cerr<<"version: "VERSION<<endl;
+      cerr<<"version: " VERSION <<endl;
       exit(99);
     }
 
