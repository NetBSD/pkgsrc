$NetBSD: patch-plugins_otp.c,v 1.1 2015/11/10 08:46:06 manu Exp $

Fix the OTP plugin on 32 bit machines and add SHA2 support
Submitted upstream as https://bugzilla.cyrusimap.org/show_bug.cgi?id=3914

--- plugins/otp.c.orig	2012-10-12 16:05:48.000000000 +0200
+++ plugins/otp.c	2015-11-07 15:19:43.000000000 +0100
@@ -92,8 +92,12 @@
 static algorithm_option_t algorithm_options[] = {
     {"md4",	0,	"md4"},
     {"md5",	0,	"md5"},
     {"sha1",	4,	"sha1"},
+    {"sha224",	4,	"sha224"},
+    {"sha256",	4,	"sha256"},
+    {"sha384",	4,	"sha384"},
+    {"sha512",	4,	"sha512"},
     {NULL,	0,	NULL}
 };
 
 /* Convert the binary data into ASCII hex */
@@ -675,9 +679,9 @@
 	    SETERROR(utils, "OTP secret too short");
 	    return SASL_FAIL;
 	}
 	
-	sscanf(secret, "%s\t%04d\t%s\t%s\t%020ld",
+	sscanf(secret, "%s\t%04d\t%s\t%s\t%020lu",
 	       alg, seq, seed, buf, timeout);
 	
 	hex2bin(buf, otp, OTP_HASH_SIZE);
 	
