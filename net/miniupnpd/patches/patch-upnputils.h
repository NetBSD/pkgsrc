$NetBSD: patch-upnputils.h,v 1.1 2013/10/21 10:06:57 fhajny Exp $

define SA_LEN wrapper and MAX macro if missing
--- upnputils.h.orig	2013-02-06 10:51:05.000000000 +0000
+++ upnputils.h
@@ -29,5 +29,28 @@ set_non_blocking(int fd);
 struct lan_addr_s *
 get_lan_for_peer(const struct sockaddr * peer);
 
+
+/**
+ * define portability macros
+ */
+#if defined(__sun)
+static size_t _sa_len(const struct sockaddr *addr)
+{
+        if (addr->sa_family == AF_INET)
+                return (sizeof(struct sockaddr_in));
+        else if (addr->sa_family == AF_INET6)
+                return (sizeof(struct sockaddr_in6));
+        else
+                return (sizeof(struct sockaddr));
+}
+# define SA_LEN(sa) (_sa_len(sa))
+#else
+# define SA_LEN(sa) ((sa)->sa_len)
+#endif
+
+#ifndef MAX
+# define MAX(a,b) (((a)>(b))?(a):(b))
+#endif
+
 #endif
 
