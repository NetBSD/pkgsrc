$NetBSD: patch-popper_pop__config.c,v 1.1 2016/03/26 23:52:37 joerg Exp $

Remove SSLv2 support.

--- popper/pop_config.c.orig	2016-03-26 21:49:03.159886179 +0000
+++ popper/pop_config.c
@@ -433,7 +433,9 @@ static mnemonic_map mnem_map_tls_sup [] 
 static mnemonic_map mnem_map_tls_vers [] =
 {
     { "default"         , QPOP_TLSvDEFAULT      }, 
+#if 0
     { "SSLv2"           , QPOP_SSLv2            },
+#endif
     { "SSLv3"           , QPOP_SSLv3            }, 
     { "TLSv1"           , QPOP_TLSv1            },
     { "SSLv23"          , QPOP_SSLv23           },
