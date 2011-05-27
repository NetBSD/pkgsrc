$NetBSD: patch-src_libopensc_card-setcos.c,v 1.1 2011/05/27 10:05:52 kivinen Exp $

--- src/libopensc/card-setcos.c.orig	2010-02-16 09:03:28.000000000 +0000
+++ src/libopensc/card-setcos.c
@@ -46,6 +46,8 @@ static struct sc_atr_table setcos_atrs[]
 	/* FINEID 2264 (EIDApplet/7816-15, OPK/EMV/AVANT) */
 	{ "3b:6e:00:00:00:62:00:00:57:41:56:41:4e:54:10:81:90:00", NULL, NULL, SC_CARD_TYPE_SETCOS_FINEID_V2, 0, NULL },
 	{ "3b:7b:94:00:00:80:62:11:51:56:46:69:6e:45:49:44", NULL, NULL, SC_CARD_TYPE_SETCOS_FINEID_V2, 0, NULL },
+	/* New FINEID cards which support 2048 bit keys. */
+	{ "3b:7b:94:00:00:80:62:12:51:56:46:69:6e:45:49:44", NULL, NULL, SC_CARD_TYPE_SETCOS_FINEID_V2_2048, 0, NULL },
 	/* Swedish NIDEL card */
 	{ "3b:9f:94:80:1f:c3:00:68:10:44:05:01:46:49:53:45:31:c8:07:90:00:18", NULL, NULL, SC_CARD_TYPE_SETCOS_NIDEL, 0, NULL },
 	/* Setcos 4.4.1 */
@@ -168,6 +170,7 @@ static int setcos_init(sc_card_t *card)
 	switch (card->type) {
 	case SC_CARD_TYPE_SETCOS_FINEID:
 	case SC_CARD_TYPE_SETCOS_FINEID_V2:
+	case SC_CARD_TYPE_SETCOS_FINEID_V2_2048:
 	case SC_CARD_TYPE_SETCOS_NIDEL:
 		card->cla = 0x00;
 		select_pkcs15_app(card);
@@ -203,6 +206,17 @@ static int setcos_init(sc_card_t *card)
 			_sc_card_add_rsa_alg(card, 1024, flags, 0);
 		}
 		break;
+	case SC_CARD_TYPE_SETCOS_FINEID_V2_2048:
+		{
+			unsigned long flags;
+
+			flags = SC_ALGORITHM_RSA_RAW | SC_ALGORITHM_RSA_PAD_PKCS1;
+			flags |= SC_ALGORITHM_RSA_HASH_NONE | SC_ALGORITHM_RSA_HASH_SHA1;
+
+			_sc_card_add_rsa_alg(card, 1024, flags, 0);
+			_sc_card_add_rsa_alg(card, 2048, flags, 0);
+		}
+		break;
 	case SC_CARD_TYPE_SETCOS_44:
 	case SC_CARD_TYPE_SETCOS_NIDEL:
 	case SC_CARD_TYPE_SETCOS_EID_V2_0:
@@ -596,6 +610,7 @@ static int setcos_set_security_env2(sc_c
 	case SC_SEC_OPERATION_SIGN:
 		/* Should be 0x41 */
 		apdu.p1 = ((card->type == SC_CARD_TYPE_SETCOS_FINEID_V2) ||
+			   (card->type == SC_CARD_TYPE_SETCOS_FINEID_V2_2048) ||
 		           (card->type == SC_CARD_TYPE_SETCOS_44) ||
 			   (card->type == SC_CARD_TYPE_SETCOS_NIDEL) || 
 			   SETCOS_IS_EID_APPLET(card)) ? 0x41 : 0x81;
@@ -678,6 +693,7 @@ static int setcos_set_security_env(sc_ca
 		case SC_CARD_TYPE_SETCOS_PKI:
 		case SC_CARD_TYPE_SETCOS_FINEID:
 		case SC_CARD_TYPE_SETCOS_FINEID_V2:
+		case SC_CARD_TYPE_SETCOS_FINEID_V2_2048:
 		case SC_CARD_TYPE_SETCOS_NIDEL:
 		case SC_CARD_TYPE_SETCOS_44:
 		case SC_CARD_TYPE_SETCOS_EID_V2_0:
