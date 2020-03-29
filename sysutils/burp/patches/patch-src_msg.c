$NetBSD: patch-src_msg.c,v 1.1 2020/03/29 01:02:12 joerg Exp $

--- src/msg.c.orig	2020-03-29 00:42:58.268427372 +0000
+++ src/msg.c
@@ -235,8 +235,7 @@ int transfer_gzfile_in(struct sbuf *sb, 
 		{
 			if(enc_ctx)
 			{
-				EVP_CIPHER_CTX_cleanup(enc_ctx);
-				free(enc_ctx);
+				EVP_CIPHER_CTX_free(enc_ctx);
 			}
 			inflateEnd(&zstrm);
 			return -1;
@@ -369,8 +368,7 @@ int transfer_gzfile_in(struct sbuf *sb, 
 	inflateEnd(&zstrm);
 	if(enc_ctx)
 	{
-		EVP_CIPHER_CTX_cleanup(enc_ctx);
-		free(enc_ctx);
+		EVP_CIPHER_CTX_free(enc_ctx);
 	}
 
 	if(ret) logp("transfer file returning: %d\n", ret);
