$NetBSD: patch-tcpd_libcouriertls.c,v 1.1 2020/04/17 00:21:17 joerg Exp $

Update for OpenSSL 1.1 interface.

--- tcpd/libcouriertls.c.orig	2020-04-13 20:52:41.051633714 +0000
+++ tcpd/libcouriertls.c
@@ -138,9 +138,9 @@ static int verifypeer(const struct tls_i
 	{
 		STACK_OF(X509) *peer_cert_chain=SSL_get_peer_cert_chain(ssl);
 
-		if (peer_cert_chain && peer_cert_chain->stack.num > 0)
+		if (peer_cert_chain && sk_X509_num(peer_cert_chain) > 0)
 		{
-			X509 *xx=(X509 *)peer_cert_chain->stack.data[0];
+			X509 *xx=sk_X509_value(peer_cert_chain, 0);
 
 			if (xx)
 				subj=X509_get_subject_name(xx);
@@ -415,16 +415,15 @@ static int client_cert_cb(ssl_handle ssl
 			continue;
 		}
 
-		for (i=0; client_cas && i<client_cas->stack.num; i++)
+		for (i=0; client_cas && i<sk_X509_NAME_num(client_cas); i++)
 		{
-			X509_NAME *cert=(X509_NAME *)client_cas->stack.data[i];
+			X509_NAME *cert=sk_X509_NAME_value(client_cas, i);
 
-			if (X509_NAME_cmp(cert,
-					  x->cert_info->issuer) == 0)
+			if (X509_NAME_cmp(cert, X509_get_issuer_name(x)) == 0)
 				break;
 		}
 
-		if (!client_cas || i >= client_cas->stack.num)
+		if (!client_cas || i >= sk_X509_NAME_num(client_cas))
 		{
 			BIO_free(certbio);
 			continue;
@@ -552,7 +551,7 @@ SSL_CTX *tls_create(int isserver, const 
 		protocol="SSL23";
 
 	ctx=SSL_CTX_new(protocol && strcmp(protocol, "SSL3") == 0
-			? SSLv3_method():
+			? SSLv23_method():
 			protocol && strcmp(protocol, "SSL23") == 0
 			? SSLv23_method():
 			TLSv1_method());
@@ -740,8 +739,8 @@ static int cache_add(SSL *ssl, SSL_SESSI
 	unsigned char *ucp;
 	time_t timeout= (time_t)SSL_SESSION_get_time(sess)
 		+ SSL_SESSION_get_timeout(sess);
-	void *session_id=(void *)sess->session_id;
-	size_t session_id_len=sess->session_id_length;
+	unsigned int session_id_len;
+	void *session_id = SSL_SESSION_get_id(sess, &session_id_len);
 	size_t sess_len=i2d_SSL_SESSION(sess, NULL);
 
 	if (sizeof(timeout) + sizeof(session_id_len) + session_id_len +
@@ -851,9 +850,7 @@ static void cache_del(SSL_CTX *ctx, SSL_
 	struct walk_info wi;
 
 	wi.now=0;
-
-	wi.id=(unsigned char *)sess->session_id;
-	wi.id_len=sess->session_id_length;
+	wi.id = SSL_SESSION_get_id(sess, &wi.id_len);
 	if (tls_cache_walk(info->tlscache, del_func, &wi) < 0)
 		perror("ALERT: tls_cache_walk: ");
 }
@@ -1360,8 +1357,8 @@ void tls_dump_connection_info(ssl_handle
 			}
 		}
 
-		for (i=0; peer_cert_chain && i<peer_cert_chain->stack.num; i++)
-			dump_x509((X509 *)peer_cert_chain->stack.data[i],
+		for (i=0; peer_cert_chain && i<sk_X509_num(peer_cert_chain); i++)
+			dump_x509(sk_X509_value(peer_cert_chain, i),
 				  dump_func, dump_arg);
 	}
 
@@ -1539,7 +1536,7 @@ char *tls_cert_name(const char *buf, siz
 
 	if (x)
 	{
-		p=X509_NAME_oneline(x->cert_info->subject, NULL, 0);
+		p=X509_NAME_oneline(X509_get_subject_name(x), NULL, 0);
 		X509_free(x);
 	}
 	ERR_clear_error();
