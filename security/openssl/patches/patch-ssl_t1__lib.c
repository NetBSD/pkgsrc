$NetBSD: patch-ssl_t1__lib.c,v 1.1 2011/02/09 00:15:30 taca Exp $

Fix for security issue CVE-2011-0014.

--- ssl/t1_lib.c.orig	2010-11-16 14:26:18.000000000 +0000
+++ ssl/t1_lib.c
@@ -521,6 +521,7 @@ int ssl_parse_clienthello_tlsext(SSL *s,
 						}
 					n2s(data, idsize);
 					dsize -= 2 + idsize;
+					size -= 2 + idsize;
 					if (dsize < 0)
 						{
 						*al = SSL_AD_DECODE_ERROR;
@@ -559,9 +560,14 @@ int ssl_parse_clienthello_tlsext(SSL *s,
 					}
 
 				/* Read in request_extensions */
+				if (size < 2)
+					{
+					*al = SSL_AD_DECODE_ERROR;
+					return 0;
+					}
 				n2s(data,dsize);
 				size -= 2;
-				if (dsize > size) 
+				if (dsize != size) 
 					{
 					*al = SSL_AD_DECODE_ERROR;
 					return 0;
