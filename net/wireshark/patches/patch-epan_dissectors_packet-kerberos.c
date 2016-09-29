$NetBSD: patch-epan_dissectors_packet-kerberos.c,v 1.1 2016/09/29 20:11:09 markd Exp $

#if 0 out some defines that clash with heimdal but wireshark doesn't
actually use.  Allows build with heimdal

--- epan/dissectors/packet-kerberos.c.orig	2016-09-07 16:59:03.000000000 +0000
+++ epan/dissectors/packet-kerberos.c
@@ -1068,6 +1068,7 @@ decrypt_krb5_data(proto_tree *tree, pack
 #define KRB5_MSG_ENC_KRB_CRED_PART	29	/* EncKrbCredPart */
 #define KRB5_MSG_ERROR			30	/* KRB-ERROR type */
 
+#if 0
 /* encryption type constants */
 #define KRB5_ENCTYPE_NULL		0
 #define KRB5_ENCTYPE_DES_CBC_CRC	1
@@ -1103,6 +1104,7 @@ decrypt_krb5_data(proto_tree *tree, pack
 #define KRB5_ENCTYPE_RC4_LM		0xffffff7e
 #define KRB5_ENCTYPE_RC4_PLAIN2		0xffffff7f
 #define KRB5_ENCTYPE_RC4_MD4		0xffffff80
+#endif
 
 /* checksum types */
 #define KRB5_CHKSUM_NONE		0
