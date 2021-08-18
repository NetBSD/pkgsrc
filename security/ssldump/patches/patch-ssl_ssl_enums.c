$NetBSD: patch-ssl_ssl_enums.c,v 1.1 2021/08/18 23:19:26 manu Exp $

Content, certificate, compression types, alerts and TLSv1.3 ciphers  
from IANA registry
https://www.iana.org/assignments/tls-parameters/tls-parameters.txt

--- ssl/ssl.enums.c.orig	2021-08-18 10:03:32.285449709 +0200
+++ ssl/ssl.enums.c	2021-08-18 11:23:47.112269067 +0200
@@ -150,8 +150,23 @@
 		23,
 		"application_data",
 		decode_ContentType_application_data
 	},
+	{
+		24,
+		"heartbeat",
+		decode_ContentType_application_data
+	},
+	{
+		25,
+		"tls12_cid",
+		decode_ContentType_application_data
+	},
+	{
+		26,
+		"ACK",
+		decode_ContentType_application_data
+	},
 {0}
 };
 
 static int decode_HandshakeType_HelloRequest(ssl,dir,seg,data)
@@ -502,8 +517,12 @@
 };
 
 decoder cipher_suite_decoder[]={
 	{
+		0,
+		"TLS_NULL_WITH_NULL_NULL",
+		0	},
+	{
 		1,
 		"TLS_RSA_WITH_NULL_MD5",
 		0	},
 	{
@@ -610,312 +629,1464 @@
 		27,
 		"TLS_DH_anon_WITH_3DES_EDE_CBC_SHA",
 		0	},
 	{
-	        47,
-	        "TLS_RSA_WITH_AES_128_CBC_SHA",
-	        0       },
+		30,
+		"TLS_KRB5_WITH_DES_CBC_SHA",
+		0	},
+	{
+		31,
+		"TLS_KRB5_WITH_3DES_EDE_CBC_SHA",
+		0	},
+	{
+		32,
+		"TLS_KRB5_WITH_RC4_128_SHA",
+		0	},
+	{
+		33,
+		"TLS_KRB5_WITH_IDEA_CBC_SHA",
+		0	},
+	{
+		34,
+		"TLS_KRB5_WITH_DES_CBC_MD5",
+		0	},
+	{
+		35,
+		"TLS_KRB5_WITH_3DES_EDE_CBC_MD5",
+		0	},
+	{
+		36,
+		"TLS_KRB5_WITH_RC4_128_MD5",
+		0	},
+	{
+		37,
+		"TLS_KRB5_WITH_IDEA_CBC_MD5",
+		0	},
+	{
+		38,
+		"TLS_KRB5_EXPORT_WITH_DES_CBC_40_SHA",
+		0	},
+	{
+		39,
+		"TLS_KRB5_EXPORT_WITH_RC2_CBC_40_SHA",
+		0	},
+	{
+		40,
+		"TLS_KRB5_EXPORT_WITH_RC4_40_SHA",
+		0	},
+	{
+		41,
+		"TLS_KRB5_EXPORT_WITH_DES_CBC_40_MD5",
+		0	},
 	{
-	        48,
-	        "TLS_DH_DSS_WITH_AES_128_CBC_SHA",
-	        0       },
+		42,
+		"TLS_KRB5_EXPORT_WITH_RC2_CBC_40_MD5",
+		0	},
+	{
+		43,
+		"TLS_KRB5_EXPORT_WITH_RC4_40_MD5",
+		0	},
 	{
-	        49,
-	        "TLS_DH_RSA_WITH_AES_128_CBC_SHA",
-	        0       },
+		44,
+		"TLS_PSK_WITH_NULL_SHA",
+		0	},
 	{
-	        50,
-	        "TLS_DHE_DSS_WITH_AES_128_CBC_SHA",
-	        0       },
+		45,
+		"TLS_DHE_PSK_WITH_NULL_SHA",
+		0	},
 	{
-	        51,
-	        "TLS_DHE_RSA_WITH_AES_128_CBC_SHA",
-	        0       },
+		46,
+		"TLS_RSA_PSK_WITH_NULL_SHA",
+		0	},
 	{
-	        52,
-	        "TLS_DH_anon_WITH_AES_128_CBC_SHA",
-	        0       },
+		47,
+		"TLS_RSA_WITH_AES_128_CBC_SHA",
+		0	},
 	{
-	        53,
-	        "TLS_RSA_WITH_AES_256_CBC_SHA",
-	        0       },
+		48,
+		"TLS_DH_DSS_WITH_AES_128_CBC_SHA",
+		0	},
 	{
-	        54,
-	        "TLS_DH_DSS_WITH_AES_256_CBC_SHA",
-	        0       },
+		49,
+		"TLS_DH_RSA_WITH_AES_128_CBC_SHA",
+		0	},
 	{
-	        55,
-	        "TLS_DH_RSA_WITH_AES_256_CBC_SHA",
-	        0       },
+		50,
+		"TLS_DHE_DSS_WITH_AES_128_CBC_SHA",
+		0	},
 	{
-	        56,
-	        "TLS_DHE_DSS_WITH_AES_256_CBC_SHA",
-	        0       },
+		51,
+		"TLS_DHE_RSA_WITH_AES_128_CBC_SHA",
+		0	},
 	{
-	        57,
-	        "TLS_DHE_RSA_WITH_AES_256_CBC_SHA",
-	        0       },
+		52,
+		"TLS_DH_anon_WITH_AES_128_CBC_SHA",
+		0	},
 	{
-	        58,
-	        "TLS_DH_anon_WITH_AES_256_CBC_SHA",
-	        0       },
+		53,
+		"TLS_RSA_WITH_AES_256_CBC_SHA",
+		0	},
 	{
-		96,
-		"TLS_RSA_EXPORT1024_WITH_RC4_56_MD5",
+		54,
+		"TLS_DH_DSS_WITH_AES_256_CBC_SHA",
 		0	},
 	{
-		97,
-		"TLS_RSA_EXPORT1024_WITH_RC2_CBC_56_MD5",
+		55,
+		"TLS_DH_RSA_WITH_AES_256_CBC_SHA",
 		0	},
 	{
-		98,
-		"TLS_RSA_EXPORT1024_WITH_DES_CBC_SHA",
+		56,
+		"TLS_DHE_DSS_WITH_AES_256_CBC_SHA",
 		0	},
 	{
-		99,
-		"TLS_DHE_DSS_EXPORT1024_WITH_DES_CBC_SHA",
+		57,
+		"TLS_DHE_RSA_WITH_AES_256_CBC_SHA",
 		0	},
 	{
-		100,
-		"TLS_RSA_EXPORT1024_WITH_RC4_56_SHA",
+		58,
+		"TLS_DH_anon_WITH_AES_256_CBC_SHA",
 		0	},
 	{
-		101,
-		"TLS_DHE_DSS_WITH_RC2_56_CBC_SHA",
+		59,
+		"TLS_RSA_WITH_NULL_SHA256",
 		0	},
 	{
-		102,
-		"TLS_DHE_DSS_WITH_RC4_128_SHA",
+		60,
+		"TLS_RSA_WITH_AES_128_CBC_SHA256",
+		0	},
+	{
+		61,
+		"TLS_RSA_WITH_AES_256_CBC_SHA256",
+		0	},
+	{
+		62,
+		"TLS_DH_DSS_WITH_AES_128_CBC_SHA256",
+		0	},
+	{
+		63,
+		"TLS_DH_RSA_WITH_AES_128_CBC_SHA256",
+		0	},
+	{
+		64,
+		"TLS_DHE_DSS_WITH_AES_128_CBC_SHA256",
+		0	},
+	{
+		65,
+		"TLS_RSA_WITH_CAMELLIA_128_CBC_SHA",
+		0	},
+	{
+		66,
+		"TLS_DH_DSS_WITH_CAMELLIA_128_CBC_SHA",
+		0	},
+	{
+		67,
+		"TLS_DH_RSA_WITH_CAMELLIA_128_CBC_SHA",
+		0	},
+	{
+		68,
+		"TLS_DHE_DSS_WITH_CAMELLIA_128_CBC_SHA",
+		0	},
+	{
+		69,
+		"TLS_DHE_RSA_WITH_CAMELLIA_128_CBC_SHA",
+		0	},
+	{
+		70,
+		"TLS_DH_anon_WITH_CAMELLIA_128_CBC_SHA",
 		0	},
 	{
 		103,
-		"TLS_DHE_DSS_WITH_NULL_SHA",
+		"TLS_DHE_RSA_WITH_AES_128_CBC_SHA256",
 		0	},
 	{
-		65664,
-		"SSL2_CK_RC4",
+		104,
+		"TLS_DH_DSS_WITH_AES_256_CBC_SHA256",
 		0	},
 	{
-		131200,
-		"SSL2_CK_RC4_EXPORT40",
+		105,
+		"TLS_DH_RSA_WITH_AES_256_CBC_SHA256",
 		0	},
 	{
-		196736,
-		"SSL2_CK_RC2",
+		106,
+		"TLS_DHE_DSS_WITH_AES_256_CBC_SHA256",
 		0	},
 	{
-		262272,
-		"SSL2_CK_RC2_EXPORT40",
+		107,
+		"TLS_DHE_RSA_WITH_AES_256_CBC_SHA256",
 		0	},
 	{
-		327808,
-		"SSL2_CK_IDEA",
+		108,
+		"TLS_DH_anon_WITH_AES_128_CBC_SHA256",
 		0	},
 	{
-		393280,
-		"SSL2_CK_DES",
+		109,
+		"TLS_DH_anon_WITH_AES_256_CBC_SHA256",
 		0	},
 	{
-		524416,
-		"SSL2_CK_RC464",
+		132,
+		"TLS_RSA_WITH_CAMELLIA_256_CBC_SHA",
 		0	},
 	{
-		458944,
-		"SSL2_CK_3DES",
+		133,
+		"TLS_DH_DSS_WITH_CAMELLIA_256_CBC_SHA",
 		0	},
 	{
-		74,
-		"TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA",
+		134,
+		"TLS_DH_RSA_WITH_CAMELLIA_256_CBC_SHA",
 		0	},
 	{
-		72,
-		"TLS_ECDH_ECDSA_WITH_RC4_128_SHA",
+		135,
+		"TLS_DHE_DSS_WITH_CAMELLIA_256_CBC_SHA",
 		0	},
 	{
-		65408,
-		"SSL_RSA_WITH_RC2_CBC_MD5",
+		136,
+		"TLS_DHE_RSA_WITH_CAMELLIA_256_CBC_SHA",
 		0	},
 	{
-		73,
-		"TLS_ECDH_ECDSA_WITH_DES_CBC_SHA",
+		137,
+		"TLS_DH_anon_WITH_CAMELLIA_256_CBC_SHA",
 		0	},
 	{
-		65413,
-		"TLS_ECDH_ECDSA_EXPORT_WITH_RC4_56_SHA",
+		138,
+		"TLS_PSK_WITH_RC4_128_SHA",
 		0	},
 	{
-		65412,
-		"TLS_ECDH_ECDSA_EXPORT_WITH_RC4_40_SHA",
+		139,
+		"TLS_PSK_WITH_3DES_EDE_CBC_SHA",
 		0	},
-{-1}
-};
-
-static int decode_AlertLevel_warning(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertLevel_fatal(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-decoder AlertLevel_decoder[]={
 	{
-		1,
-		"warning",
-		decode_AlertLevel_warning
-	},
+		140,
+		"TLS_PSK_WITH_AES_128_CBC_SHA",
+		0	},
 	{
-		2,
-		"fatal",
-		decode_AlertLevel_fatal
-	},
-{0}
-};
-
-static int decode_AlertDescription_close_notify(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_unexpected_message(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_bad_record_mac(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_decryption_failed(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_record_overflow(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_decompression_failure(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_handshake_failure(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_bad_certificate(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_unsupported_certificate(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_certificate_revoked(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_certificate_expired(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_certificate_unknown(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_illegal_parameter(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_unknown_ca(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_access_denied(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_decode_error(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
-static int decode_AlertDescription_decrypt_error(ssl,dir,seg,data)
-  ssl_obj *ssl;
-  int dir;
-  segment *seg;
-  Data *data;
-  {
-	return(0);
-  }
+		141,
+		"TLS_PSK_WITH_AES_256_CBC_SHA",
+		0	},
+	{
+		142,
+		"TLS_DHE_PSK_WITH_RC4_128_SHA",
+		0	},
+	{
+		143,
+		"TLS_DHE_PSK_WITH_3DES_EDE_CBC_SHA",
+		0	},
+	{
+		144,
+		"TLS_DHE_PSK_WITH_AES_128_CBC_SHA",
+		0	},
+	{
+		145,
+		"TLS_DHE_PSK_WITH_AES_256_CBC_SHA",
+		0	},
+	{
+		146,
+		"TLS_RSA_PSK_WITH_RC4_128_SHA",
+		0	},
+	{
+		147,
+		"TLS_RSA_PSK_WITH_3DES_EDE_CBC_SHA",
+		0	},
+	{
+		148,
+		"TLS_RSA_PSK_WITH_AES_128_CBC_SHA",
+		0	},
+	{
+		149,
+		"TLS_RSA_PSK_WITH_AES_256_CBC_SHA",
+		0	},
+	{
+		150,
+		"TLS_RSA_WITH_SEED_CBC_SHA",
+		0	},
+	{
+		151,
+		"TLS_DH_DSS_WITH_SEED_CBC_SHA",
+		0	},
+	{
+		152,
+		"TLS_DH_RSA_WITH_SEED_CBC_SHA",
+		0	},
+	{
+		153,
+		"TLS_DHE_DSS_WITH_SEED_CBC_SHA",
+		0	},
+	{
+		154,
+		"TLS_DHE_RSA_WITH_SEED_CBC_SHA",
+		0	},
+	{
+		155,
+		"TLS_DH_anon_WITH_SEED_CBC_SHA",
+		0	},
+	{
+		156,
+		"TLS_RSA_WITH_AES_128_GCM_SHA256",
+		0	},
+	{
+		157,
+		"TLS_RSA_WITH_AES_256_GCM_SHA384",
+		0	},
+	{
+		158,
+		"TLS_DHE_RSA_WITH_AES_128_GCM_SHA256",
+		0	},
+	{
+		159,
+		"TLS_DHE_RSA_WITH_AES_256_GCM_SHA384",
+		0	},
+	{
+		160,
+		"TLS_DH_RSA_WITH_AES_128_GCM_SHA256",
+		0	},
+	{
+		161,
+		"TLS_DH_RSA_WITH_AES_256_GCM_SHA384",
+		0	},
+	{
+		162,
+		"TLS_DHE_DSS_WITH_AES_128_GCM_SHA256",
+		0	},
+	{
+		163,
+		"TLS_DHE_DSS_WITH_AES_256_GCM_SHA384",
+		0	},
+	{
+		164,
+		"TLS_DH_DSS_WITH_AES_128_GCM_SHA256",
+		0	},
+	{
+		165,
+		"TLS_DH_DSS_WITH_AES_256_GCM_SHA384",
+		0	},
+	{
+		166,
+		"TLS_DH_anon_WITH_AES_128_GCM_SHA256",
+		0	},
+	{
+		167,
+		"TLS_DH_anon_WITH_AES_256_GCM_SHA384",
+		0	},
+	{
+		168,
+		"TLS_PSK_WITH_AES_128_GCM_SHA256",
+		0	},
+	{
+		169,
+		"TLS_PSK_WITH_AES_256_GCM_SHA384",
+		0	},
+	{
+		170,
+		"TLS_DHE_PSK_WITH_AES_128_GCM_SHA256",
+		0	},
+	{
+		171,
+		"TLS_DHE_PSK_WITH_AES_256_GCM_SHA384",
+		0	},
+	{
+		172,
+		"TLS_RSA_PSK_WITH_AES_128_GCM_SHA256",
+		0	},
+	{
+		173,
+		"TLS_RSA_PSK_WITH_AES_256_GCM_SHA384",
+		0	},
+	{
+		174,
+		"TLS_PSK_WITH_AES_128_CBC_SHA256",
+		0	},
+	{
+		175,
+		"TLS_PSK_WITH_AES_256_CBC_SHA384",
+		0	},
+	{
+		176,
+		"TLS_PSK_WITH_NULL_SHA256",
+		0	},
+	{
+		177,
+		"TLS_PSK_WITH_NULL_SHA384",
+		0	},
+	{
+		178,
+		"TLS_DHE_PSK_WITH_AES_128_CBC_SHA256",
+		0	},
+	{
+		179,
+		"TLS_DHE_PSK_WITH_AES_256_CBC_SHA384",
+		0	},
+	{
+		180,
+		"TLS_DHE_PSK_WITH_NULL_SHA256",
+		0	},
+	{
+		181,
+		"TLS_DHE_PSK_WITH_NULL_SHA384",
+		0	},
+	{
+		182,
+		"TLS_RSA_PSK_WITH_AES_128_CBC_SHA256",
+		0	},
+	{
+		183,
+		"TLS_RSA_PSK_WITH_AES_256_CBC_SHA384",
+		0	},
+	{
+		184,
+		"TLS_RSA_PSK_WITH_NULL_SHA256",
+		0	},
+	{
+		185,
+		"TLS_RSA_PSK_WITH_NULL_SHA384",
+		0	},
+	{
+		186,
+		"TLS_RSA_WITH_CAMELLIA_128_CBC_SHA256",
+		0	},
+	{
+		187,
+		"TLS_DH_DSS_WITH_CAMELLIA_128_CBC_SHA256",
+		0	},
+	{
+		188,
+		"TLS_DH_RSA_WITH_CAMELLIA_128_CBC_SHA256",
+		0	},
+	{
+		189,
+		"TLS_DHE_DSS_WITH_CAMELLIA_128_CBC_SHA256",
+		0	},
+	{
+		190,
+		"TLS_DHE_RSA_WITH_CAMELLIA_128_CBC_SHA256",
+		0	},
+	{
+		191,
+		"TLS_DH_anon_WITH_CAMELLIA_128_CBC_SHA256",
+		0	},
+	{
+		192,
+		"TLS_RSA_WITH_CAMELLIA_256_CBC_SHA256",
+		0	},
+	{
+		193,
+		"TLS_DH_DSS_WITH_CAMELLIA_256_CBC_SHA256",
+		0	},
+	{
+		194,
+		"TLS_DH_RSA_WITH_CAMELLIA_256_CBC_SHA256",
+		0	},
+	{
+		195,
+		"TLS_DHE_DSS_WITH_CAMELLIA_256_CBC_SHA256",
+		0	},
+	{
+		196,
+		"TLS_DHE_RSA_WITH_CAMELLIA_256_CBC_SHA256",
+		0	},
+	{
+		197,
+		"TLS_DH_anon_WITH_CAMELLIA_256_CBC_SHA256",
+		0	},
+	{
+		198,
+		"TLS_SM4_GCM_SM3",
+		0	},
+	{
+		199,
+		"TLS_SM4_CCM_SM3",
+		0	},
+	{
+		255,
+		"TLS_EMPTY_RENEGOTIATION_INFO_SCSV",
+		0	},
+	{
+		4865,
+		"TLS_AES_128_GCM_SHA256",
+		0	},
+	{
+		4866,
+		"TLS_AES_256_GCM_SHA384",
+		0	},
+	{
+		4867,
+		"TLS_CHACHA20_POLY1305_SHA256",
+		0	},
+	{
+		4868,
+		"TLS_AES_128_CCM_SHA256",
+		0	},
+	{
+		4869,
+		"TLS_AES_128_CCM_8_SHA256",
+		0	},
+	{
+		22016,
+		"TLS_FALLBACK_SCSV",
+		0	},
+	{
+		49153,
+		"TLS_ECDH_ECDSA_WITH_NULL_SHA",
+		0	},
+	{
+		49154,
+		"TLS_ECDH_ECDSA_WITH_RC4_128_SHA",
+		0	},
+	{
+		49155,
+		"TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA",
+		0	},
+	{
+		49156,
+		"TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA",
+		0	},
+	{
+		49157,
+		"TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA",
+		0	},
+	{
+		49158,
+		"TLS_ECDHE_ECDSA_WITH_NULL_SHA",
+		0	},
+	{
+		49159,
+		"TLS_ECDHE_ECDSA_WITH_RC4_128_SHA",
+		0	},
+	{
+		49160,
+		"TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA",
+		0	},
+	{
+		49161,
+		"TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA",
+		0	},
+	{
+		49162,
+		"TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA",
+		0	},
+	{
+		49163,
+		"TLS_ECDH_RSA_WITH_NULL_SHA",
+		0	},
+	{
+		49164,
+		"TLS_ECDH_RSA_WITH_RC4_128_SHA",
+		0	},
+	{
+		49165,
+		"TLS_ECDH_RSA_WITH_3DES_EDE_CBC_SHA",
+		0	},
+	{
+		49166,
+		"TLS_ECDH_RSA_WITH_AES_128_CBC_SHA",
+		0	},
+	{
+		49167,
+		"TLS_ECDH_RSA_WITH_AES_256_CBC_SHA",
+		0	},
+	{
+		49168,
+		"TLS_ECDHE_RSA_WITH_NULL_SHA",
+		0	},
+	{
+		49169,
+		"TLS_ECDHE_RSA_WITH_RC4_128_SHA",
+		0	},
+	{
+		49170,
+		"TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA",
+		0	},
+	{
+		49171,
+		"TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA",
+		0	},
+	{
+		49172,
+		"TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA",
+		0	},
+	{
+		49173,
+		"TLS_ECDH_anon_WITH_NULL_SHA",
+		0	},
+	{
+		49174,
+		"TLS_ECDH_anon_WITH_RC4_128_SHA",
+		0	},
+	{
+		49175,
+		"TLS_ECDH_anon_WITH_3DES_EDE_CBC_SHA",
+		0	},
+	{
+		49176,
+		"TLS_ECDH_anon_WITH_AES_128_CBC_SHA",
+		0	},
+	{
+		49177,
+		"TLS_ECDH_anon_WITH_AES_256_CBC_SHA",
+		0	},
+	{
+		49178,
+		"TLS_SRP_SHA_WITH_3DES_EDE_CBC_SHA",
+		0	},
+	{
+		49179,
+		"TLS_SRP_SHA_RSA_WITH_3DES_EDE_CBC_SHA",
+		0	},
+	{
+		49180,
+		"TLS_SRP_SHA_DSS_WITH_3DES_EDE_CBC_SHA",
+		0	},
+	{
+		49181,
+		"TLS_SRP_SHA_WITH_AES_128_CBC_SHA",
+		0	},
+	{
+		49182,
+		"TLS_SRP_SHA_RSA_WITH_AES_128_CBC_SHA",
+		0	},
+	{
+		49183,
+		"TLS_SRP_SHA_DSS_WITH_AES_128_CBC_SHA",
+		0	},
+	{
+		49184,
+		"TLS_SRP_SHA_WITH_AES_256_CBC_SHA",
+		0	},
+	{
+		49185,
+		"TLS_SRP_SHA_RSA_WITH_AES_256_CBC_SHA",
+		0	},
+	{
+		49186,
+		"TLS_SRP_SHA_DSS_WITH_AES_256_CBC_SHA",
+		0	},
+	{
+		49187,
+		"TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256",
+		0	},
+	{
+		49188,
+		"TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384",
+		0	},
+	{
+		49189,
+		"TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256",
+		0	},
+	{
+		49190,
+		"TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA384",
+		0	},
+	{
+		49191,
+		"TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256",
+		0	},
+	{
+		49192,
+		"TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384",
+		0	},
+	{
+		49193,
+		"TLS_ECDH_RSA_WITH_AES_128_CBC_SHA256",
+		0	},
+	{
+		49194,
+		"TLS_ECDH_RSA_WITH_AES_256_CBC_SHA384",
+		0	},
+	{
+		49195,
+		"TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256",
+		0	},
+	{
+		49196,
+		"TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384",
+		0	},
+	{
+		49197,
+		"TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256",
+		0	},
+	{
+		49198,
+		"TLS_ECDH_ECDSA_WITH_AES_256_GCM_SHA384",
+		0	},
+	{
+		49199,
+		"TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256",
+		0	},
+	{
+		49200,
+		"TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384",
+		0	},
+	{
+		49201,
+		"TLS_ECDH_RSA_WITH_AES_128_GCM_SHA256",
+		0	},
+	{
+		49202,
+		"TLS_ECDH_RSA_WITH_AES_256_GCM_SHA384",
+		0	},
+	{
+		49203,
+		"TLS_ECDHE_PSK_WITH_RC4_128_SHA",
+		0	},
+	{
+		49204,
+		"TLS_ECDHE_PSK_WITH_3DES_EDE_CBC_SHA",
+		0	},
+	{
+		49205,
+		"TLS_ECDHE_PSK_WITH_AES_128_CBC_SHA",
+		0	},
+	{
+		49206,
+		"TLS_ECDHE_PSK_WITH_AES_256_CBC_SHA",
+		0	},
+	{
+		49207,
+		"TLS_ECDHE_PSK_WITH_AES_128_CBC_SHA256",
+		0	},
+	{
+		49208,
+		"TLS_ECDHE_PSK_WITH_AES_256_CBC_SHA384",
+		0	},
+	{
+		49209,
+		"TLS_ECDHE_PSK_WITH_NULL_SHA",
+		0	},
+	{
+		49210,
+		"TLS_ECDHE_PSK_WITH_NULL_SHA256",
+		0	},
+	{
+		49211,
+		"TLS_ECDHE_PSK_WITH_NULL_SHA384",
+		0	},
+	{
+		49212,
+		"TLS_RSA_WITH_ARIA_128_CBC_SHA256",
+		0	},
+	{
+		49213,
+		"TLS_RSA_WITH_ARIA_256_CBC_SHA384",
+		0	},
+	{
+		49214,
+		"TLS_DH_DSS_WITH_ARIA_128_CBC_SHA256",
+		0	},
+	{
+		49215,
+		"TLS_DH_DSS_WITH_ARIA_256_CBC_SHA384",
+		0	},
+	{
+		49216,
+		"TLS_DH_RSA_WITH_ARIA_128_CBC_SHA256",
+		0	},
+	{
+		49217,
+		"TLS_DH_RSA_WITH_ARIA_256_CBC_SHA384",
+		0	},
+	{
+		49218,
+		"TLS_DHE_DSS_WITH_ARIA_128_CBC_SHA256",
+		0	},
+	{
+		49219,
+		"TLS_DHE_DSS_WITH_ARIA_256_CBC_SHA384",
+		0	},
+	{
+		49220,
+		"TLS_DHE_RSA_WITH_ARIA_128_CBC_SHA256",
+		0	},
+	{
+		49221,
+		"TLS_DHE_RSA_WITH_ARIA_256_CBC_SHA384",
+		0	},
+	{
+		49222,
+		"TLS_DH_anon_WITH_ARIA_128_CBC_SHA256",
+		0	},
+	{
+		49223,
+		"TLS_DH_anon_WITH_ARIA_256_CBC_SHA384",
+		0	},
+	{
+		49224,
+		"TLS_ECDHE_ECDSA_WITH_ARIA_128_CBC_SHA256",
+		0	},
+	{
+		49225,
+		"TLS_ECDHE_ECDSA_WITH_ARIA_256_CBC_SHA384",
+		0	},
+	{
+		49226,
+		"TLS_ECDH_ECDSA_WITH_ARIA_128_CBC_SHA256",
+		0	},
+	{
+		49227,
+		"TLS_ECDH_ECDSA_WITH_ARIA_256_CBC_SHA384",
+		0	},
+	{
+		49228,
+		"TLS_ECDHE_RSA_WITH_ARIA_128_CBC_SHA256",
+		0	},
+	{
+		49229,
+		"TLS_ECDHE_RSA_WITH_ARIA_256_CBC_SHA384",
+		0	},
+	{
+		49230,
+		"TLS_ECDH_RSA_WITH_ARIA_128_CBC_SHA256",
+		0	},
+	{
+		49231,
+		"TLS_ECDH_RSA_WITH_ARIA_256_CBC_SHA384",
+		0	},
+	{
+		49232,
+		"TLS_RSA_WITH_ARIA_128_GCM_SHA256",
+		0	},
+	{
+		49233,
+		"TLS_RSA_WITH_ARIA_256_GCM_SHA384",
+		0	},
+	{
+		49234,
+		"TLS_DHE_RSA_WITH_ARIA_128_GCM_SHA256",
+		0	},
+	{
+		49235,
+		"TLS_DHE_RSA_WITH_ARIA_256_GCM_SHA384",
+		0	},
+	{
+		49236,
+		"TLS_DH_RSA_WITH_ARIA_128_GCM_SHA256",
+		0	},
+	{
+		49237,
+		"TLS_DH_RSA_WITH_ARIA_256_GCM_SHA384",
+		0	},
+	{
+		49238,
+		"TLS_DHE_DSS_WITH_ARIA_128_GCM_SHA256",
+		0	},
+	{
+		49239,
+		"TLS_DHE_DSS_WITH_ARIA_256_GCM_SHA384",
+		0	},
+	{
+		49240,
+		"TLS_DH_DSS_WITH_ARIA_128_GCM_SHA256",
+		0	},
+	{
+		49241,
+		"TLS_DH_DSS_WITH_ARIA_256_GCM_SHA384",
+		0	},
+	{
+		49242,
+		"TLS_DH_anon_WITH_ARIA_128_GCM_SHA256",
+		0	},
+	{
+		49243,
+		"TLS_DH_anon_WITH_ARIA_256_GCM_SHA384",
+		0	},
+	{
+		49244,
+		"TLS_ECDHE_ECDSA_WITH_ARIA_128_GCM_SHA256",
+		0	},
+	{
+		49245,
+		"TLS_ECDHE_ECDSA_WITH_ARIA_256_GCM_SHA384",
+		0	},
+	{
+		49246,
+		"TLS_ECDH_ECDSA_WITH_ARIA_128_GCM_SHA256",
+		0	},
+	{
+		49247,
+		"TLS_ECDH_ECDSA_WITH_ARIA_256_GCM_SHA384",
+		0	},
+	{
+		49248,
+		"TLS_ECDHE_RSA_WITH_ARIA_128_GCM_SHA256",
+		0	},
+	{
+		49249,
+		"TLS_ECDHE_RSA_WITH_ARIA_256_GCM_SHA384",
+		0	},
+	{
+		49250,
+		"TLS_ECDH_RSA_WITH_ARIA_128_GCM_SHA256",
+		0	},
+	{
+		49251,
+		"TLS_ECDH_RSA_WITH_ARIA_256_GCM_SHA384",
+		0	},
+	{
+		49252,
+		"TLS_PSK_WITH_ARIA_128_CBC_SHA256",
+		0	},
+	{
+		49253,
+		"TLS_PSK_WITH_ARIA_256_CBC_SHA384",
+		0	},
+	{
+		49254,
+		"TLS_DHE_PSK_WITH_ARIA_128_CBC_SHA256",
+		0	},
+	{
+		49255,
+		"TLS_DHE_PSK_WITH_ARIA_256_CBC_SHA384",
+		0	},
+	{
+		49256,
+		"TLS_RSA_PSK_WITH_ARIA_128_CBC_SHA256",
+		0	},
+	{
+		49257,
+		"TLS_RSA_PSK_WITH_ARIA_256_CBC_SHA384",
+		0	},
+	{
+		49258,
+		"TLS_PSK_WITH_ARIA_128_GCM_SHA256",
+		0	},
+	{
+		49259,
+		"TLS_PSK_WITH_ARIA_256_GCM_SHA384",
+		0	},
+	{
+		49260,
+		"TLS_DHE_PSK_WITH_ARIA_128_GCM_SHA256",
+		0	},
+	{
+		49261,
+		"TLS_DHE_PSK_WITH_ARIA_256_GCM_SHA384",
+		0	},
+	{
+		49262,
+		"TLS_RSA_PSK_WITH_ARIA_128_GCM_SHA256",
+		0	},
+	{
+		49263,
+		"TLS_RSA_PSK_WITH_ARIA_256_GCM_SHA384",
+		0	},
+	{
+		49264,
+		"TLS_ECDHE_PSK_WITH_ARIA_128_CBC_SHA256",
+		0	},
+	{
+		49265,
+		"TLS_ECDHE_PSK_WITH_ARIA_256_CBC_SHA384",
+		0	},
+	{
+		49266,
+		"TLS_ECDHE_ECDSA_WITH_CAMELLIA_128_CBC_SHA256",
+		0	},
+	{
+		49267,
+		"TLS_ECDHE_ECDSA_WITH_CAMELLIA_256_CBC_SHA384",
+		0	},
+	{
+		49268,
+		"TLS_ECDH_ECDSA_WITH_CAMELLIA_128_CBC_SHA256",
+		0	},
+	{
+		49269,
+		"TLS_ECDH_ECDSA_WITH_CAMELLIA_256_CBC_SHA384",
+		0	},
+	{
+		49270,
+		"TLS_ECDHE_RSA_WITH_CAMELLIA_128_CBC_SHA256",
+		0	},
+	{
+		49271,
+		"TLS_ECDHE_RSA_WITH_CAMELLIA_256_CBC_SHA384",
+		0	},
+	{
+		49272,
+		"TLS_ECDH_RSA_WITH_CAMELLIA_128_CBC_SHA256",
+		0	},
+	{
+		49273,
+		"TLS_ECDH_RSA_WITH_CAMELLIA_256_CBC_SHA384",
+		0	},
+	{
+		49274,
+		"TLS_RSA_WITH_CAMELLIA_128_GCM_SHA256",
+		0	},
+	{
+		49275,
+		"TLS_RSA_WITH_CAMELLIA_256_GCM_SHA384",
+		0	},
+	{
+		49276,
+		"TLS_DHE_RSA_WITH_CAMELLIA_128_GCM_SHA256",
+		0	},
+	{
+		49277,
+		"TLS_DHE_RSA_WITH_CAMELLIA_256_GCM_SHA384",
+		0	},
+	{
+		49278,
+		"TLS_DH_RSA_WITH_CAMELLIA_128_GCM_SHA256",
+		0	},
+	{
+		49279,
+		"TLS_DH_RSA_WITH_CAMELLIA_256_GCM_SHA384",
+		0	},
+	{
+		49280,
+		"TLS_DHE_DSS_WITH_CAMELLIA_128_GCM_SHA256",
+		0	},
+	{
+		49281,
+		"TLS_DHE_DSS_WITH_CAMELLIA_256_GCM_SHA384",
+		0	},
+	{
+		49282,
+		"TLS_DH_DSS_WITH_CAMELLIA_128_GCM_SHA256",
+		0	},
+	{
+		49283,
+		"TLS_DH_DSS_WITH_CAMELLIA_256_GCM_SHA384",
+		0	},
+	{
+		49284,
+		"TLS_DH_anon_WITH_CAMELLIA_128_GCM_SHA256",
+		0	},
+	{
+		49285,
+		"TLS_DH_anon_WITH_CAMELLIA_256_GCM_SHA384",
+		0	},
+	{
+		49286,
+		"TLS_ECDHE_ECDSA_WITH_CAMELLIA_128_GCM_SHA256",
+		0	},
+	{
+		49287,
+		"TLS_ECDHE_ECDSA_WITH_CAMELLIA_256_GCM_SHA384",
+		0	},
+	{
+		49288,
+		"TLS_ECDH_ECDSA_WITH_CAMELLIA_128_GCM_SHA256",
+		0	},
+	{
+		49289,
+		"TLS_ECDH_ECDSA_WITH_CAMELLIA_256_GCM_SHA384",
+		0	},
+	{
+		49290,
+		"TLS_ECDHE_RSA_WITH_CAMELLIA_128_GCM_SHA256",
+		0	},
+	{
+		49291,
+		"TLS_ECDHE_RSA_WITH_CAMELLIA_256_GCM_SHA384",
+		0	},
+	{
+		49292,
+		"TLS_ECDH_RSA_WITH_CAMELLIA_128_GCM_SHA256",
+		0	},
+	{
+		49293,
+		"TLS_ECDH_RSA_WITH_CAMELLIA_256_GCM_SHA384",
+		0	},
+	{
+		49294,
+		"TLS_PSK_WITH_CAMELLIA_128_GCM_SHA256",
+		0	},
+	{
+		49295,
+		"TLS_PSK_WITH_CAMELLIA_256_GCM_SHA384",
+		0	},
+	{
+		49296,
+		"TLS_DHE_PSK_WITH_CAMELLIA_128_GCM_SHA256",
+		0	},
+	{
+		49297,
+		"TLS_DHE_PSK_WITH_CAMELLIA_256_GCM_SHA384",
+		0	},
+	{
+		49298,
+		"TLS_RSA_PSK_WITH_CAMELLIA_128_GCM_SHA256",
+		0	},
+	{
+		49299,
+		"TLS_RSA_PSK_WITH_CAMELLIA_256_GCM_SHA384",
+		0	},
+	{
+		49300,
+		"TLS_PSK_WITH_CAMELLIA_128_CBC_SHA256",
+		0	},
+	{
+		49301,
+		"TLS_PSK_WITH_CAMELLIA_256_CBC_SHA384",
+		0	},
+	{
+		49302,
+		"TLS_DHE_PSK_WITH_CAMELLIA_128_CBC_SHA256",
+		0	},
+	{
+		49303,
+		"TLS_DHE_PSK_WITH_CAMELLIA_256_CBC_SHA384",
+		0	},
+	{
+		49304,
+		"TLS_RSA_PSK_WITH_CAMELLIA_128_CBC_SHA256",
+		0	},
+	{
+		49305,
+		"TLS_RSA_PSK_WITH_CAMELLIA_256_CBC_SHA384",
+		0	},
+	{
+		49306,
+		"TLS_ECDHE_PSK_WITH_CAMELLIA_128_CBC_SHA256",
+		0	},
+	{
+		49307,
+		"TLS_ECDHE_PSK_WITH_CAMELLIA_256_CBC_SHA384",
+		0	},
+	{
+		49308,
+		"TLS_RSA_WITH_AES_128_CCM",
+		0	},
+	{
+		49309,
+		"TLS_RSA_WITH_AES_256_CCM",
+		0	},
+	{
+		49310,
+		"TLS_DHE_RSA_WITH_AES_128_CCM",
+		0	},
+	{
+		49311,
+		"TLS_DHE_RSA_WITH_AES_256_CCM",
+		0	},
+	{
+		49312,
+		"TLS_RSA_WITH_AES_128_CCM_8",
+		0	},
+	{
+		49313,
+		"TLS_RSA_WITH_AES_256_CCM_8",
+		0	},
+	{
+		49314,
+		"TLS_DHE_RSA_WITH_AES_128_CCM_8",
+		0	},
+	{
+		49315,
+		"TLS_DHE_RSA_WITH_AES_256_CCM_8",
+		0	},
+	{
+		49316,
+		"TLS_PSK_WITH_AES_128_CCM",
+		0	},
+	{
+		49317,
+		"TLS_PSK_WITH_AES_256_CCM",
+		0	},
+	{
+		49318,
+		"TLS_DHE_PSK_WITH_AES_128_CCM",
+		0	},
+	{
+		49319,
+		"TLS_DHE_PSK_WITH_AES_256_CCM",
+		0	},
+	{
+		49320,
+		"TLS_PSK_WITH_AES_128_CCM_8",
+		0	},
+	{
+		49321,
+		"TLS_PSK_WITH_AES_256_CCM_8",
+		0	},
+	{
+		49322,
+		"TLS_PSK_DHE_WITH_AES_128_CCM_8",
+		0	},
+	{
+		49323,
+		"TLS_PSK_DHE_WITH_AES_256_CCM_8",
+		0	},
+	{
+		49324,
+		"TLS_ECDHE_ECDSA_WITH_AES_128_CCM",
+		0	},
+	{
+		49325,
+		"TLS_ECDHE_ECDSA_WITH_AES_256_CCM",
+		0	},
+	{
+		49326,
+		"TLS_ECDHE_ECDSA_WITH_AES_128_CCM_8",
+		0	},
+	{
+		49327,
+		"TLS_ECDHE_ECDSA_WITH_AES_256_CCM_8",
+		0	},
+	{
+		49328,
+		"TLS_ECCPWD_WITH_AES_128_GCM_SHA256",
+		0	},
+	{
+		49329,
+		"TLS_ECCPWD_WITH_AES_256_GCM_SHA384",
+		0	},
+	{
+		49330,
+		"TLS_ECCPWD_WITH_AES_128_CCM_SHA256",
+		0	},
+	{
+		49331,
+		"TLS_ECCPWD_WITH_AES_256_CCM_SHA384",
+		0	},
+	{
+		49332,
+		"TLS_SHA256_SHA256",
+		0	},
+	{
+		49333,
+		"TLS_SHA384_SHA384",
+		0	},
+	{
+		49408,
+		"TLS_GOSTR341112_256_WITH_KUZNYECHIK_CTR_OMAC",
+		0	},
+	{
+		49409,
+		"TLS_GOSTR341112_256_WITH_MAGMA_CTR_OMAC",
+		0	},
+	{
+		49410,
+		"TLS_GOSTR341112_256_WITH_28147_CNT_IMIT",
+		0	},
+	{
+		49411,
+		"TLS_GOSTR341112_256_WITH_KUZNYECHIK_MGM_L",
+		0	},
+	{
+		49412,
+		"TLS_GOSTR341112_256_WITH_MAGMA_MGM_L",
+		0	},
+	{
+		49413,
+		"TLS_GOSTR341112_256_WITH_KUZNYECHIK_MGM_S",
+		0	},
+	{
+		49414,
+		"TLS_GOSTR341112_256_WITH_MAGMA_MGM_S",
+		0	},
+	{
+		52392,
+		"TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256",
+		0	},
+	{
+		52393,
+		"TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256",
+		0	},
+	{
+		52394,
+		"TLS_DHE_RSA_WITH_CHACHA20_POLY1305_SHA256",
+		0	},
+	{
+		52395,
+		"TLS_PSK_WITH_CHACHA20_POLY1305_SHA256",
+		0	},
+	{
+		52396,
+		"TLS_ECDHE_PSK_WITH_CHACHA20_POLY1305_SHA256",
+		0	},
+	{
+		52397,
+		"TLS_DHE_PSK_WITH_CHACHA20_POLY1305_SHA256",
+		0	},
+	{
+		52398,
+		"TLS_RSA_PSK_WITH_CHACHA20_POLY1305_SHA256",
+		0	},
+	{
+		53249,
+		"TLS_ECDHE_PSK_WITH_AES_128_GCM_SHA256",
+		0	},
+	{
+		53250,
+		"TLS_ECDHE_PSK_WITH_AES_256_GCM_SHA384",
+		0	},
+	{
+		53251,
+		"TLS_ECDHE_PSK_WITH_AES_128_CCM_8_SHA256",
+		0	},
+	{
+		53253,
+		"TLS_ECDHE_PSK_WITH_AES_128_CCM_SHA256",
+		0	},
+{-1}
+};
+
+static int decode_AlertLevel_warning(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertLevel_fatal(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+decoder AlertLevel_decoder[]={
+	{
+		1,
+		"warning",
+		decode_AlertLevel_warning
+	},
+	{
+		2,
+		"fatal",
+		decode_AlertLevel_fatal
+	},
+{0}
+};
+
+static int decode_AlertDescription_close_notify(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_unexpected_message(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_bad_record_mac(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_decryption_failed(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_record_overflow(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_decompression_failure(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_handshake_failure(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_bad_certificate(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_unsupported_certificate(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_certificate_revoked(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_certificate_expired(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_certificate_unknown(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_illegal_parameter(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_unknown_ca(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_access_denied(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_decode_error(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
+static int decode_AlertDescription_decrypt_error(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
 static int decode_AlertDescription_export_restriction(ssl,dir,seg,data)
   ssl_obj *ssl;
   int dir;
   segment *seg;
@@ -1069,8 +2240,13 @@
 		"internal_error",
 		decode_AlertDescription_internal_error
 	},
 	{
+		86,
+		"inappropriate_fallback",
+		decode_AlertDescription_internal_error
+	},
+	{
 		90,
 		"user_canceled",
 		decode_AlertDescription_user_canceled
 	},
@@ -1078,16 +2254,69 @@
 		100,
 		"no_renegotiation",
 		decode_AlertDescription_no_renegotiation
 	},
+	{
+		109,
+		"missing_extension",
+		decode_AlertDescription_internal_error
+	},
+	{
+		110,
+		"unsupported_extension",
+		decode_AlertDescription_internal_error
+	},
+	{
+		111,
+		"certificate_unobtainable_RESERVED",
+		decode_AlertDescription_internal_error
+	},
+	{
+		112,
+		"unrecognized_name",
+		decode_AlertDescription_internal_error
+	},
+	{
+		113,
+		"bad_certificate_status_response",
+		decode_AlertDescription_internal_error
+	},
+	{
+		114,
+		"bad_certificate_hash_value_RESERVED",
+		decode_AlertDescription_internal_error
+	},
+	{
+		115,
+		"unknown_psk_identity",
+		decode_AlertDescription_internal_error
+	},
+	{
+		116,
+		"certificate_required",
+		decode_AlertDescription_internal_error
+	},
+	{
+		120,
+		"no_application_protocol",
+		decode_AlertDescription_internal_error
+	},
 {0}
 };
 
 decoder compression_method_decoder[]={
 	{
 		0,
 		"NULL",
 		0	},
+	{
+		1,
+		"ansiX962_compressed_prime",
+		0	},
+	{
+		2,
+		"ansiX962_compressed_char2",
+		0	},
 {-1}
 };
 
 static int decode_client_certificate_type_rsa_sign(ssl,dir,seg,data)
@@ -1121,8 +2350,16 @@
   Data *data;
   {
 	return(0);
   }
+static int decode_client_certificate_type_error(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
 decoder client_certificate_type_decoder[]={
 	{
 		1,
 		"rsa_sign",
@@ -1142,7 +2379,47 @@
 		4,
 		"dss_fixed_dh",
 		decode_client_certificate_type_dss_fixed_dh
 	},
+	{
+		5,
+		"rsa_ephemeral_dh",
+		decode_client_certificate_type_error
+	},
+	{
+		6,
+		"dss_ephemeral_dh",
+		decode_client_certificate_type_error
+	},
+	{
+		20,
+		"fortezza_dms",
+		decode_client_certificate_type_error
+	},
+	{
+		64,
+		"ecdsa_sign",
+		decode_client_certificate_type_error
+	},
+	{
+		65,
+		"rsa_fixed_ecdh",
+		decode_client_certificate_type_error
+	},
+	{
+		66,
+		"ecdsa_fixed_ecdh",
+		decode_client_certificate_type_error
+	},
+	{
+		67,
+		"gost_sign256",
+		decode_client_certificate_type_error
+	},
+	{
+		68,
+		"gost_sign512",
+		decode_client_certificate_type_error
+	},
 {0}
 };
 
