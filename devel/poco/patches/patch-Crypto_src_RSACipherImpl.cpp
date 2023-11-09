$NetBSD: patch-Crypto_src_RSACipherImpl.cpp,v 1.1 2023/11/09 19:16:20 nia Exp $

OpenSSL 3.x fix. This definition was removed.

--- Crypto/src/RSACipherImpl.cpp.orig	2015-08-04 05:21:01.000000000 +0000
+++ Crypto/src/RSACipherImpl.cpp
@@ -52,8 +52,6 @@ namespace
 			return RSA_PKCS1_PADDING;
 		case RSA_PADDING_PKCS1_OAEP:
 			return RSA_PKCS1_OAEP_PADDING;
-		case RSA_PADDING_SSLV23:
-			return RSA_SSLV23_PADDING;
 		case RSA_PADDING_NONE:
 			return RSA_NO_PADDING;
 		default:
