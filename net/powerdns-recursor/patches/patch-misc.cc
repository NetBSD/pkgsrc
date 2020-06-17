$NetBSD: patch-misc.cc,v 1.1 2020/06/17 22:55:11 otis Exp $

backport changes based on PR #9127 from
https://github.com/PowerDNS/pdns/pull/9127

--- misc.cc.orig	2020-05-08 09:31:59.000000000 +0000
+++ misc.cc
@@ -57,6 +57,7 @@
 #include <sys/types.h>
 #include <pwd.h>
 #include <grp.h>
+#include <limits.h>
 #ifdef __FreeBSD__
 #  include <pthread_np.h>
 #endif
@@ -1563,3 +1564,39 @@ bool setPipeBufferSize(int fd, size_t si
   return false;
 #endif /* F_SETPIPE_SZ */
 }
+
+static size_t getMaxHostNameSize()
+{
+#if defined(HOST_NAME_MAX)
+  return HOST_NAME_MAX;
+#endif
+
+#if defined(_SC_HOST_NAME_MAX)
+  auto tmp = sysconf(_SC_HOST_NAME_MAX);
+  if (tmp != -1) {
+    return tmp;
+  }
+#endif
+
+  /* _POSIX_HOST_NAME_MAX */
+  return 255;
+}
+
+std::string getCarbonHostName()
+{
+  std::string hostname;
+  hostname.resize(getMaxHostNameSize() + 1, 0);
+
+  if (gethostname(const_cast<char*>(hostname.c_str()), hostname.size()) != 0) {
+    throw std::runtime_error(stringerror());
+  }
+
+  auto pos = hostname.find(".");
+  if (pos != std::string::npos) {
+    hostname.resize(pos);
+  }
+
+  boost::replace_all(hostname, ".", "_");
+
+  return hostname;
+}
