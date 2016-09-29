$NetBSD: patch-epan_dissectors_packet-kerberos.h,v 1.1 2016/09/29 20:11:09 markd Exp $

#if 0 out some defines that clash with heimdal but wireshark doesn't
actually use.  Allows build with heimdal

--- epan/dissectors/packet-kerberos.h.orig	2016-09-07 16:59:03.000000000 +0000
+++ epan/dissectors/packet-kerberos.h
@@ -108,6 +108,7 @@ void read_keytab_file_from_preferences(v
 
 #endif /* HAVE_KERBEROS */
 
+#if 0
 /* encryption type constants */
 #define KRB5_ENCTYPE_NULL		0
 #define KRB5_ENCTYPE_DES_CBC_CRC	1
@@ -128,8 +129,10 @@ void read_keytab_file_from_preferences(v
 #define KRB5_ENCTYPE_AES128_CTS_HMAC_SHA1_96 17
 #define KRB5_ENCTYPE_AES256_CTS_HMAC_SHA1_96 18
 #define KRB5_ENCTYPE_DES_CBC_MD5_NT	20
+#endif
 #define KERB_ENCTYPE_RC4_HMAC		23
 #define KERB_ENCTYPE_RC4_HMAC_EXP	24
+#if 0
 #define KRB5_ENCTYPE_UNKNOWN		0x1ff
 #define KRB5_ENCTYPE_LOCAL_DES3_HMAC_SHA1	0x7007
 #define KRB5_ENCTYPE_RC4_PLAIN_EXP	0xffffff73
@@ -143,7 +146,7 @@ void read_keytab_file_from_preferences(v
 #define KRB5_ENCTYPE_RC4_LM		0xffffff7e
 #define KRB5_ENCTYPE_RC4_PLAIN2		0xffffff7f
 #define KRB5_ENCTYPE_RC4_MD4		0xffffff80
-
+#endif
 
 /*--- Included file: packet-kerberos-exp.h ---*/
 #line 1 "./asn1/kerberos/packet-kerberos-exp.h"
