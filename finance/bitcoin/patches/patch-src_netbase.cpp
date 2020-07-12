$NetBSD: patch-src_netbase.cpp,v 1.4 2020/07/12 21:02:12 adam Exp $

It is unclear why this patch exists.  NetBSD 6 and 7 have AI_ADDRCONFIG,
although NetBSD 5 does not.  Arguably upstream should have an autoconf
test instead.  This is not known to be reported upstream.

--- src/netbase.cpp.orig	2020-06-02 07:43:04.000000000 +0000
+++ src/netbase.cpp
@@ -96,7 +96,11 @@ bool static LookupIntern(const std::stri
     // If we don't allow lookups, then use the AI_NUMERICHOST flag for
     // getaddrinfo to only decode numerical network addresses and suppress
     // hostname lookups.
+#ifdef AI_ADDRCONFIG
     aiHint.ai_flags = fAllowLookup ? AI_ADDRCONFIG : AI_NUMERICHOST;
+#else
+    aiHint.ai_flags = fAllowLookup ? 0 : AI_NUMERICHOST;
+#endif
     struct addrinfo *aiRes = nullptr;
     int nErr = getaddrinfo(name.c_str(), nullptr, &aiHint, &aiRes);
     if (nErr)
