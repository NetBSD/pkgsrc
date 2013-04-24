$NetBSD: patch-.._.._ipxe_src_net_tls.c,v 1.1.2.2 2013/04/24 21:11:06 tron Exp $

--- ../../ipxe/src/net/tls.c.orig	2013-03-25 18:53:57.000000000 +0000
+++ ../../ipxe/src/net/tls.c
@@ -650,18 +650,22 @@ static int tls_send_client_key_exchange 
 	RSA_CTX *rsa_ctx;
 	RSA_pub_key_new ( &rsa_ctx, tls->rsa.modulus, tls->rsa.modulus_len,
 			  tls->rsa.exponent, tls->rsa.exponent_len );
+	size_t elen = rsa_ctx->num_octets;
 	struct {
 		uint32_t type_length;
 		uint16_t encrypted_pre_master_secret_len;
-		uint8_t encrypted_pre_master_secret[rsa_ctx->num_octets];
-	} __attribute__ (( packed )) key_xchg;
-
-	memset ( &key_xchg, 0, sizeof ( key_xchg ) );
-	key_xchg.type_length = ( cpu_to_le32 ( TLS_CLIENT_KEY_EXCHANGE ) |
-				 htonl ( sizeof ( key_xchg ) -
-					 sizeof ( key_xchg.type_length ) ) );
-	key_xchg.encrypted_pre_master_secret_len
-		= htons ( sizeof ( key_xchg.encrypted_pre_master_secret ) );
+		uint8_t encrypted_pre_master_secret[];
+	} __attribute__ (( packed )) *key_xchg;
+	size_t klen = sizeof(*key_xchg) + elen;
+
+	key_xchg = alloca(klen);
+
+	memset ( key_xchg, 0, klen );
+	key_xchg->type_length = ( cpu_to_le32 ( TLS_CLIENT_KEY_EXCHANGE ) |
+				 htonl ( klen -
+					 sizeof ( key_xchg->type_length ) ) );
+	key_xchg->encrypted_pre_master_secret_len
+		= htons ( elen );
 
 	/* FIXME: Hack alert */
 	DBGC ( tls, "RSA encrypting plaintext, modulus, exponent:\n" );
@@ -671,14 +675,13 @@ static int tls_send_client_key_exchange 
 	DBGC_HD ( tls, tls->rsa.exponent, tls->rsa.exponent_len );
 	RSA_encrypt ( rsa_ctx, ( const uint8_t * ) &tls->pre_master_secret,
 		      sizeof ( tls->pre_master_secret ),
-		      key_xchg.encrypted_pre_master_secret, 0 );
+		      key_xchg->encrypted_pre_master_secret, 0 );
 	DBGC ( tls, "RSA encrypt done.  Ciphertext:\n" );
-	DBGC_HD ( tls, &key_xchg.encrypted_pre_master_secret,
-		  sizeof ( key_xchg.encrypted_pre_master_secret ) );
+	DBGC_HD ( tls, &key_xchg->encrypted_pre_master_secret, elen );
 	RSA_free ( rsa_ctx );
 
 
-	return tls_send_handshake ( tls, &key_xchg, sizeof ( key_xchg ) );
+	return tls_send_handshake ( tls, key_xchg, klen );
 }
 
 /**
@@ -802,12 +805,12 @@ static int tls_new_server_hello ( struct
 		uint8_t session_id_len;
 		char next[0];
 	} __attribute__ (( packed )) *hello_a = data;
+	size_t slen = hello_a->session_id_len;
 	struct {
-		uint8_t session_id[hello_a->session_id_len];
 		uint16_t cipher_suite;
 		uint8_t compression_method;
 		char next[0];
-	} __attribute__ (( packed )) *hello_b = ( void * ) &hello_a->next;
+	} __attribute__ (( packed )) *hello_b = ( void * ) ((uint8_t *)&hello_a->next + slen);
 	void *end = hello_b->next;
 	int rc;
 
