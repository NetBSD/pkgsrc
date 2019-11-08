$NetBSD: patch-builtin_receive-pack.c,v 1.1 2019/11/08 12:52:30 ryoon Exp $

* Do not conflict hmac(3) of NetBSD

--- builtin/receive-pack.c.orig	2019-11-04 05:07:07.000000000 +0000
+++ builtin/receive-pack.c
@@ -417,7 +417,7 @@ static int copy_to_sideband(int in, int 
 	return 0;
 }
 
-static void hmac(unsigned char *out,
+static void git_hmac(unsigned char *out,
 		      const char *key_in, size_t key_len,
 		      const char *text, size_t text_len)
 {
@@ -462,7 +462,7 @@ static char *prepare_push_cert_nonce(con
 	unsigned char hash[GIT_MAX_RAWSZ];
 
 	strbuf_addf(&buf, "%s:%"PRItime, path, stamp);
-	hmac(hash, buf.buf, buf.len, cert_nonce_seed, strlen(cert_nonce_seed));
+	git_hmac(hash, buf.buf, buf.len, cert_nonce_seed, strlen(cert_nonce_seed));
 	strbuf_release(&buf);
 
 	/* RFC 2104 5. HMAC-SHA1-80 */
