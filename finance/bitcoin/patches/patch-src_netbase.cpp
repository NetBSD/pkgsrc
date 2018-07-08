$NetBSD: patch-src_netbase.cpp,v 1.1 2018/07/08 11:13:46 khorben Exp $

It is unclear why this patch exists.  NetBSD 6 and 7 have AI_ADDRCONFIG,
although NetBSD 5 does not.  Arguably upstream should have an autoconf
test instead.  This is not known to be reported upstream.

--- src/netbase.cpp.orig	2017-04-20 09:28:25.000000000 +0000
+++ src/netbase.cpp
@@ -95,7 +95,7 @@ bool static LookupIntern(const char *psz
     aiHint.ai_socktype = SOCK_STREAM;
     aiHint.ai_protocol = IPPROTO_TCP;
     aiHint.ai_family = AF_UNSPEC;
-#ifdef WIN32
+#ifndef AI_ADDRCONFIG
     aiHint.ai_flags = fAllowLookup ? 0 : AI_NUMERICHOST;
 #else
     aiHint.ai_flags = fAllowLookup ? AI_ADDRCONFIG : AI_NUMERICHOST;
