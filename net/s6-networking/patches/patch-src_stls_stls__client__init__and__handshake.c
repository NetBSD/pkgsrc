$NetBSD: patch-src_stls_stls__client__init__and__handshake.c,v 1.1 2021/01/13 09:21:22 schmonz Exp $

LibreSSL has this problem; OpenSSL + LibreTLS do not.

--- src/stls/stls_client_init_and_handshake.c.orig	2020-11-23 15:28:30.000000000 +0000
+++ src/stls/stls_client_init_and_handshake.c
@@ -50,7 +50,6 @@ struct tls *stls_client_init_and_handsha
     {
       if (tls_config_set_ca_path(cfg, x) < 0)
         diecfg(cfg, "tls_config_set_ca_path") ;
-      strerr_warnw1x("some versions of libtls do not work with CADIR, try using CAFILE instead") ;
     }
     else strerr_diefu1x(100, "get trust anchor list: neither CADIR nor CAFILE is set") ;
   }
