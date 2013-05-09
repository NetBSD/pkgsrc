$NetBSD: patch-pdns_pdns_recursor.cc,v 1.2 2013/05/09 20:06:53 joerg Exp $

--- pdns/pdns_recursor.cc.orig	2012-01-05 13:54:51.000000000 +0000
+++ pdns/pdns_recursor.cc
@@ -67,10 +67,11 @@ StatBag S;
 FDMultiplexer* g_fdm;
 unsigned int g_maxTCPPerClient;
 bool g_logCommonErrors;
-shared_ptr<PowerDNSLua> g_pdl;
+boost::shared_ptr<PowerDNSLua> g_pdl;
 using namespace boost;
 
-#ifdef __FreeBSD__           // see cvstrac ticket #26
+// see cvstrac ticket #26
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <pthread.h>
 #include <semaphore.h>
 #endif
@@ -578,7 +579,7 @@ void startDoResolve(void *p)
 	    IpToU32(i->content, &ip);
 	    pw.xfr32BitInt(htonl(ip));
 	  } else {
-	    shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(i->qtype.getCode(), i->qclass, i->content)); 
+	    boost::shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(i->qtype.getCode(), i->qclass, i->content)); 
 	    drc->toPacket(pw);
 	  }
 	  if(!dc->d_tcp && pw.size() > maxudpsize) {
@@ -1553,7 +1554,7 @@ void parseAuthAndForwards()
     if(!rfp)
       throw AhuException("Error opening forward-zones-file '"+::arg()["forward-zones-file"]+"': "+stringerror());
 
-    shared_ptr<FILE> fp=shared_ptr<FILE>(rfp, fclose);
+    boost::shared_ptr<FILE> fp=boost::shared_ptr<FILE>(rfp, fclose);
     
     char line[1024];
     int linenum=0;
@@ -1630,7 +1631,7 @@ string doReloadLuaScript(vector<string>:
   try {
     if(begin==end) {
       if(!fname.empty()) 
-	g_pdl = shared_ptr<PowerDNSLua>(new PowerDNSLua(fname));
+	g_pdl = boost::shared_ptr<PowerDNSLua>(new PowerDNSLua(fname));
       else
 	throw runtime_error("Asked to reload lua scripts, but no name passed and no default ('lua-dns-script') defined");
     }
@@ -1642,7 +1643,7 @@ string doReloadLuaScript(vector<string>:
 	return "unloaded current lua script\n";
       }
       else {
-	g_pdl = shared_ptr<PowerDNSLua>(new PowerDNSLua(fname));
+	g_pdl = boost::shared_ptr<PowerDNSLua>(new PowerDNSLua(fname));
 	::arg().set("lua-dns-script")=fname;
       }
     }
@@ -1766,7 +1767,7 @@ int serviceMain(int argc, char*argv[])
 
   try {
     if(!::arg()["lua-dns-script"].empty()) {
-      g_pdl = shared_ptr<PowerDNSLua>(new PowerDNSLua(::arg()["lua-dns-script"]));
+      g_pdl = boost::shared_ptr<PowerDNSLua>(new PowerDNSLua(::arg()["lua-dns-script"]));
       L<<Logger::Warning<<"Loaded 'lua' script from '"<<::arg()["lua-dns-script"]<<"'"<<endl;
     }
     
