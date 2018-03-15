$NetBSD: patch-src_lib_keyring.c,v 1.2 2018/03/15 19:37:30 khorben Exp $

Do not crash when listing keys without a keyring.
Do not ask for a passphrase when empty.

--- src/lib/keyring.c.orig	2018-03-15 19:31:30.000000000 +0000
+++ src/lib/keyring.c
@@ -226,7 +226,7 @@ typedef struct {
 	pgp_seckey_t		*seckey;
 } decrypt_t;
 
-static pgp_cb_ret_t 
+static pgp_cb_ret_t
 decrypt_cb(const pgp_packet_t *pkt, pgp_cbdata_t *cbinfo)
 {
 	const pgp_contents_t	*content = &pkt->u;
@@ -292,6 +292,20 @@ decrypt_cb(const pgp_packet_t *pkt, pgp_
 	return PGP_RELEASE_MEMORY;
 }
 
+static pgp_cb_ret_t
+decrypt_cb_empty(const pgp_packet_t *pkt, pgp_cbdata_t *cbinfo)
+{
+	const pgp_contents_t	*content = &pkt->u;
+
+	switch (pkt->tag) {
+	case PGP_GET_PASSPHRASE:
+		*content->skey_passphrase.passphrase = netpgp_strdup("");
+		return PGP_KEEP_MEMORY;
+	default:
+		return decrypt_cb(pkt, cbinfo);
+	}
+}
+
 /**
 \ingroup Core_Keys
 \brief Decrypts secret key from given keydata with given passphrase
@@ -306,8 +320,18 @@ pgp_decrypt_seckey(const pgp_key_t *key,
 	const int	 printerrors = 1;
 	decrypt_t	 decrypt;
 
+	/* first try with an empty passphrase */
 	(void) memset(&decrypt, 0x0, sizeof(decrypt));
 	decrypt.key = key;
+	stream = pgp_new(sizeof(*stream));
+	pgp_keydata_reader_set(stream, key);
+	pgp_set_callback(stream, decrypt_cb_empty, &decrypt);
+	stream->readinfo.accumulate = 1;
+	pgp_parse(stream, !printerrors);
+	if (decrypt.seckey != NULL) {
+		return decrypt.seckey;
+	}
+	/* ask for a passphrase */
 	decrypt.passfp = passfp;
 	stream = pgp_new(sizeof(*stream));
 	pgp_keydata_reader_set(stream, key);
