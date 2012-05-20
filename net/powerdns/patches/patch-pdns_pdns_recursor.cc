$NetBSD: patch-pdns_pdns_recursor.cc,v 1.1 2012/05/20 19:37:49 marino Exp $

--- pdns/pdns_recursor.cc.orig	2012-01-05 13:54:51.000000000 +0000
+++ pdns/pdns_recursor.cc
@@ -70,7 +70,8 @@ bool g_logCommonErrors;
 shared_ptr<PowerDNSLua> g_pdl;
 using namespace boost;
 
-#ifdef __FreeBSD__           // see cvstrac ticket #26
+// see cvstrac ticket #26
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <pthread.h>
 #include <semaphore.h>
 #endif
