$NetBSD: patch-basictcp.cpp,v 1.1 2016/03/29 22:05:47 joerg Exp $

--- basictcp.cpp.orig	2016-03-28 18:41:34.420033652 +0000
+++ basictcp.cpp
@@ -103,10 +103,10 @@ int base_tcp::ConnectTLS()
   m_sslMeth = NULL;
   m_sslCtx = NULL;
   m_ssl = NULL;
-  m_sslMeth = SSLv2_client_method();
+  m_sslMeth = SSLv23_client_method();
   if(m_sslMeth == NULL)
   {
-    fprintf(stderr, "Can't get SSLv2_client_method.\n");
+    fprintf(stderr, "Can't get SSLv23_client_method.\n");
     return 2;
   }
   m_sslCtx = SSL_CTX_new(m_sslMeth);
