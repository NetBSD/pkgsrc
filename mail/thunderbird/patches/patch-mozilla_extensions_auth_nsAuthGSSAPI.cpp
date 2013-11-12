$NetBSD: patch-mozilla_extensions_auth_nsAuthGSSAPI.cpp,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/extensions/auth/nsAuthGSSAPI.cpp.orig	2013-10-23 22:08:56.000000000 +0000
+++ mozilla/extensions/auth/nsAuthGSSAPI.cpp
@@ -40,6 +40,9 @@ typedef KLStatus (*KLCacheHasValidTicket
 #endif
 
 #if defined(HAVE_RES_NINIT)
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <arpa/nameser.h>
 #include <resolv.h>
 #endif
 
