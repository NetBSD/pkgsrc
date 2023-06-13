$NetBSD: patch-lib_dpkg_buffer.c,v 1.1 2023/06/13 15:44:29 adam Exp $

Use md5 from OpenSSL.

--- lib/dpkg/buffer.c.orig	2023-03-27 00:41:09.000000000 +0000
+++ lib/dpkg/buffer.c
@@ -26,7 +26,7 @@
 #include <sys/types.h>
 
 #include <errno.h>
-#include <md5.h>
+#include <openssl/md5.h>
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
@@ -50,7 +50,7 @@ buffer_md5_init(struct buffer_data *data
 	ctx = m_malloc(sizeof(*ctx));
 	ctx->hash = data->arg.ptr;
 	data->arg.ptr = ctx;
-	MD5Init(&ctx->ctx);
+	MD5_Init(&ctx->ctx);
 }
 
 static off_t
@@ -75,7 +75,7 @@ buffer_digest_update(struct buffer_data 
 	case BUFFER_DIGEST_NULL:
 		break;
 	case BUFFER_DIGEST_MD5:
-		MD5Update(&(((struct buffer_md5_ctx *)digest->arg.ptr)->ctx),
+		MD5_Update(&(((struct buffer_md5_ctx *)digest->arg.ptr)->ctx),
 		          buf, length);
 		break;
 	default:
@@ -95,7 +95,7 @@ buffer_md5_done(struct buffer_data *data
 
 	ctx = (struct buffer_md5_ctx *)data->arg.ptr;
 	hash = ctx->hash;
-	MD5Final(digest, &ctx->ctx);
+	MD5_Final(digest, &ctx->ctx);
 	for (i = 0; i < 16; ++i) {
 		sprintf(hash, "%02x", *p++);
 		hash += 2;
