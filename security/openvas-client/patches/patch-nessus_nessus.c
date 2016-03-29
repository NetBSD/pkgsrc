$NetBSD: patch-nessus_nessus.c,v 1.1 2016/03/29 22:00:14 joerg Exp $

--- nessus/nessus.c.orig	2016-03-29 18:19:57.396124258 +0000
+++ nessus/nessus.c
@@ -410,9 +410,7 @@ Please launch openvasclient-mkrand(1) fi
 	}
       if (ssl_mt == NULL)
 	{
-	  if (strcasecmp(ssl_ver, "SSLv2") == 0)
-	    ssl_mt = SSLv2_client_method();
-	  else if (strcasecmp(ssl_ver, "SSLv3") == 0)
+	  if (strcasecmp(ssl_ver, "SSLv3") == 0)
 	    ssl_mt = SSLv3_client_method();
 	  else if (strcasecmp(ssl_ver, "SSLv23") == 0)
 	    ssl_mt = SSLv23_client_method();
@@ -443,6 +441,7 @@ Please launch openvasclient-mkrand(1) fi
 	    return "SSL error";
 	  }
 
+      SSL_CTX_set_options(ssl_ctx, SSL_OP_NO_SSLv2);
       if (SSL_CTX_set_options(ssl_ctx, SSL_OP_ALL) < 0)
 	sslerror("SSL_CTX_set_options(SSL_OP_ALL)");
 
