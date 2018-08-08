$NetBSD: patch-portsmplexer.cc,v 1.1 2018/08/08 15:39:55 fhajny Exp $

Fix stale code and add missing getAvailableFDs() implementation.

--- portsmplexer.cc.orig	2018-07-10 12:43:20.000000000 +0000
+++ portsmplexer.cc
@@ -24,10 +24,11 @@ public:
   }
 
   virtual int run(struct timeval* tv, int timeout=500);
+  virtual void getAvailableFDs(std::vector<int>& fds, int timeout) override;
 
   virtual void addFD(callbackmap_t& cbmap, int fd, callbackfunc_t toDo, const boost::any& parameter);
   virtual void removeFD(callbackmap_t& cbmap, int fd);
-  string getName()
+  string getName() const override
   {
     return "solaris completion ports";
   }
@@ -78,6 +79,22 @@ void PortsFDMultiplexer::removeFD(callba
     throw FDMultiplexerException("Removing fd from port set: "+stringerror());
 }
 
+void PortsFDMultiplexer::getAvailableFDs(std::vector<int>& fds, int timeout)
+{
+  struct timespec timeoutspec;
+  timeoutspec.tv_sec = timeout / 1000;
+  timeoutspec.tv_nsec = (timeout % 1000) * 1000000;
+  unsigned int numevents=1;
+  int ret= port_getn(d_portfd, d_pevents.get(), min(PORT_MAX_LIST, s_maxevents), &numevents, &timeoutspec);
+
+  if(ret < 0 && errno!=EINTR)
+    throw FDMultiplexerException("ports returned error: "+stringerror());
+
+  for(int n=0; n < ret; ++n) {
+    fds.push_back(d_pevents[n].portev_object);
+  }
+}
+
 int PortsFDMultiplexer::run(struct timeval* now, int timeout)
 {
   if(d_inrun) {
@@ -85,8 +102,8 @@ int PortsFDMultiplexer::run(struct timev
   }
   
   struct timespec timeoutspec;
-  timeoutspec.tv_sec = time / 1000;
-  timeoutspec.tv_nsec = (time % 1000) * 1000000;
+  timeoutspec.tv_sec = timeout / 1000;
+  timeoutspec.tv_nsec = (timeout % 1000) * 1000000;
   unsigned int numevents=1;
   int ret= port_getn(d_portfd, d_pevents.get(), min(PORT_MAX_LIST, s_maxevents), &numevents, &timeoutspec);
   
