$NetBSD: patch-src_netbase.cpp,v 1.5 2021/11/22 21:32:05 khorben Exp $

It is unclear why this patch exists.  NetBSD 6 and 7 have AI_ADDRCONFIG,
although NetBSD 5 does not.  Arguably upstream should have an autoconf
test instead.  This is not known to be reported upstream.

--- src/netbase.cpp.orig	2021-09-08 18:16:07.000000000 +0000
+++ src/netbase.cpp
@@ -56,7 +56,11 @@ std::vector<CNetAddr> WrappedGetAddrInfo
     // If we don't allow lookups, then use the AI_NUMERICHOST flag for
     // getaddrinfo to only decode numerical network addresses and suppress
     // hostname lookups.
+#ifdef AI_ADDRCONFIG
     ai_hint.ai_flags = allow_lookup ? AI_ADDRCONFIG : AI_NUMERICHOST;
+#else
+    ai_hint.ai_flags = allow_lookup ? 0 : AI_NUMERICHOST;
+#endif
 
     addrinfo* ai_res{nullptr};
     const int n_err{getaddrinfo(name.c_str(), nullptr, &ai_hint, &ai_res)};
