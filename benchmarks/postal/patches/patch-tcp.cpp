$NetBSD: patch-tcp.cpp,v 1.1 2016/03/29 22:05:47 joerg Exp $

--- tcp.cpp.orig	2016-03-28 18:41:37.150020392 +0000
+++ tcp.cpp
@@ -178,10 +178,10 @@ int tcp::ConnectTLS()
 #ifdef USE_OPENSSL
   m_sslCtx = NULL;
   m_ssl = NULL;
-  m_sslMeth = SSLv2_client_method();
+  m_sslMeth = SSLv23_client_method();
   if(m_sslMeth == NULL)
   {
-    fprintf(stderr, "Can't get SSLv2_client_method.\n");
+    fprintf(stderr, "Can't get SSLv23_client_method.\n");
     error();
     return 2;
   }
