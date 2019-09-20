$NetBSD: patch-src_netbase.cpp,v 1.2 2019/09/20 16:57:28 adam Exp $

It is unclear why this patch exists.  NetBSD 6 and 7 have AI_ADDRCONFIG,
although NetBSD 5 does not.  Arguably upstream should have an autoconf
test instead.  This is not known to be reported upstream.

--- src/netbase.cpp.orig	2019-09-20 11:57:52.000000000 +0000
+++ src/netbase.cpp
@@ -80,7 +80,11 @@ bool static LookupIntern(const char *psz
     aiHint.ai_socktype = SOCK_STREAM;
     aiHint.ai_protocol = IPPROTO_TCP;
     aiHint.ai_family = AF_UNSPEC;
+#ifdef AI_ADDRCONFIG
     aiHint.ai_flags = fAllowLookup ? AI_ADDRCONFIG : AI_NUMERICHOST;
+#else
+    aiHint.ai_flags = fAllowLookup ? 0 : AI_NUMERICHOST;
+#endif
     struct addrinfo *aiRes = nullptr;
     int nErr = getaddrinfo(pszName, nullptr, &aiHint, &aiRes);
     if (nErr)
