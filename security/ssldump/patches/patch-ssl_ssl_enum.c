$NetBSD: patch-ssl_ssl_enum.c,v 1.1 2021/08/18 23:19:26 manu Exp $

Handshake types from IANA registry
https://www.iana.org/assignments/tls-parameters/tls-parameters.txt

--- ssl/ssl_enum.c.orig	2021-08-18 10:22:12.808679651 +0200
+++ ssl/ssl_enum.c	2021-08-18 10:26:07.767517923 +0200
@@ -208,8 +208,16 @@
   Data *data;
   {
 	return(0);
   }
+static int decode_HandshakeType_error(ssl,dir,seg,data)
+  ssl_obj *ssl;
+  int dir;
+  segment *seg;
+  Data *data;
+  {
+	return(0);
+  }
 decoder HandshakeType_decoder[]={
 	{
 		0,
 		"hello_request",
@@ -225,8 +233,32 @@
 		"server_hello",
 		decode_HandshakeType_server_hello
 	},
 	{
+		3,
+		"hello_verify_request",
+		decode_HandshakeType_error
+	},
+	{
+		4,
+		"new_session_ticket",
+		decode_HandshakeType_error
+	},
+	{
+		5,
+		"end_of_early_data",
+		decode_HandshakeType_error
+	},
+	{
+		6,
+		"hello_retry_request",
+		decode_HandshakeType_error
+	},
+	{
+		8,
+		"encrypted_extensions",
+		decode_HandshakeType_error
+	},
 		11,
 		"certificate",
 		decode_HandshakeType_certificate
 	},
@@ -259,8 +291,34 @@
 		20,
 		"finished",
 		decode_HandshakeType_finished
 	},
+	{
+		21,
+		"certificate_url",
+		decode_HandshakeType_error
+	},
+	{
+		22,
+		"certificate_status",
+		decode_HandshakeType_error
+	},
+	{
+		23,
+		"supplemental_data",
+		decode_HandshakeType_error
+	},
+	{
+		24,
+		"key_update",
+		decode_HandshakeType_error
+	},
+	{
+		254,
+		"message_hash",
+		decode_HandshakeType_error
+	},
+	{
 {0}
 };
 
 decoder cipher_suite_decoder[]={
