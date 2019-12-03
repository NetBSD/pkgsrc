$NetBSD: patch-src_netbase.cpp,v 1.3 2019/12/03 16:30:35 adam Exp $

It is unclear why this patch exists.  NetBSD 6 and 7 have AI_ADDRCONFIG,
although NetBSD 5 does not.  Arguably upstream should have an autoconf
test instead.  This is not known to be reported upstream.

--- src/netbase.cpp.orig	2019-11-18 09:44:44.000000000 +0000
+++ src/netbase.cpp
@@ -91,7 +91,11 @@ bool static LookupIntern(const char *psz
     // If we don't allow lookups, then use the AI_NUMERICHOST flag for
     // getaddrinfo to only decode numerical network addresses and suppress
     // hostname lookups.
+#ifdef AI_ADDRCONFIG
     aiHint.ai_flags = fAllowLookup ? AI_ADDRCONFIG : AI_NUMERICHOST;
+#else
+    aiHint.ai_flags = fAllowLookup ? 0 : AI_NUMERICHOST;
+#endif
     struct addrinfo *aiRes = nullptr;
     int nErr = getaddrinfo(pszName, nullptr, &aiHint, &aiRes);
     if (nErr)
