$NetBSD: patch-portsmplexer.cc,v 1.2 2020/04/16 13:09:28 jperkin Exp $

Pull in upstream patch from https://github.com/PowerDNS/pdns/pull/9031

--- portsmplexer.cc.orig	2020-04-16 12:54:40.155420464 +0000
+++ portsmplexer.cc
@@ -23,11 +23,12 @@ public:
     close(d_portfd);
   }
 
-  virtual int run(struct timeval* tv, int timeout=500);
+  virtual int run(struct timeval* tv, int timeout=500) override;
+  virtual void getAvailableFDs(std::vector<int>& fds, int timeout) override;
 
-  virtual void addFD(callbackmap_t& cbmap, int fd, callbackfunc_t toDo, const boost::any& parameter, const struct timeval* ttd=nullptr);
-  virtual void removeFD(callbackmap_t& cbmap, int fd);
-  string getName()
+  virtual void addFD(callbackmap_t& cbmap, int fd, callbackfunc_t toDo, const boost::any& parameter, const struct timeval* ttd=nullptr) override;
+  virtual void removeFD(callbackmap_t& cbmap, int fd) override;
+  string getName() const override
   {
     return "solaris completion ports";
   }
@@ -78,6 +79,58 @@ void PortsFDMultiplexer::removeFD(callba
     throw FDMultiplexerException("Removing fd from port set: "+stringerror());
 }
 
+void PortsFDMultiplexer::getAvailableFDs(std::vector<int>& fds, int timeout)
+{
+  struct timespec timeoutspec;
+  timeoutspec.tv_sec = timeout / 1000;
+  timeoutspec.tv_nsec = (timeout % 1000) * 1000000;
+  unsigned int numevents = 1;
+  int ret = port_getn(d_portfd, d_pevents.get(), min(PORT_MAX_LIST, s_maxevents), &numevents, &timeoutspec);
+
+  /* port_getn has an unusual API - (ret == -1, errno == ETIME) can
+     mean partial success; you must check (*numevents) in this case
+     and process anything in there, otherwise you'll never see any
+     events from that object again. We don't care about pure timeouts
+     (ret == -1, errno == ETIME, *numevents == 0) so we don't bother
+     with that case. */
+  if (ret == -1 && errno != ETIME) {
+    if (errno != EINTR) {
+      throw FDMultiplexerException("completion port_getn returned error: " + stringerror());
+    }
+
+    // EINTR is not really an error
+    return;
+  }
+
+  if (numevents == 0) {
+    // nothing
+    return;
+  }
+
+  fds.reserve(numevents);
+
+  for (unsigned int n = 0; n < numevents; ++n) {
+    const auto fd = d_pevents[n].portev_object;
+
+    /* we need to re-associate the FD */
+    if (d_readCallbacks.count(fd)) {
+      if (port_associate(d_portfd, PORT_SOURCE_FD, fd, POLLIN, 0) < 0) {
+        throw FDMultiplexerException("Unable to add fd back to ports (read): " + stringerror());
+      }
+    }
+    else if (d_writeCallbacks.count(fd)) {
+      if (port_associate(d_portfd, PORT_SOURCE_FD, fd, POLLOUT, 0) < 0) {
+        throw FDMultiplexerException("Unable to add fd back to ports (write): " + stringerror());
+      }
+    } else {
+      /* not registered, this is unexpected */
+      continue;
+    }
+
+    fds.push_back(fd);
+  }
+}
+
 int PortsFDMultiplexer::run(struct timeval* now, int timeout)
 {
   if(d_inrun) {
@@ -85,8 +138,8 @@ int PortsFDMultiplexer::run(struct timev
   }
   
   struct timespec timeoutspec;
-  timeoutspec.tv_sec = time / 1000;
-  timeoutspec.tv_nsec = (time % 1000) * 1000000;
+  timeoutspec.tv_sec = timeout / 1000;
+  timeoutspec.tv_nsec = (timeout % 1000) * 1000000;
   unsigned int numevents=1;
   int ret= port_getn(d_portfd, d_pevents.get(), min(PORT_MAX_LIST, s_maxevents), &numevents, &timeoutspec);
   
