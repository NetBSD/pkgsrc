$NetBSD: patch-plugins_otp.c,v 1.2 2018/04/17 01:57:18 christos Exp $

Fix the OTP plugin on 32 bit machines and add SHA2 support
Submitted upstream as https://bugzilla.cyrusimap.org/show_bug.cgi?id=3914

--- plugins/otp.c.orig	2016-12-10 10:54:27.000000000 -0500
+++ plugins/otp.c	2018-04-16 20:09:59.910785912 -0400
@@ -91,6 +91,10 @@
     {"md4",	0,	"md4"},
     {"md5",	0,	"md5"},
     {"sha1",	4,	"sha1"},
+    {"sha224",	4,	"sha224"},
+    {"sha256",	4,	"sha256"},
+    {"sha384",	4,	"sha384"},
+    {"sha512",	4,	"sha512"},
     {NULL,	0,	NULL}
 };
 
@@ -706,7 +710,7 @@
 	    return SASL_FAIL;
 	}
 	
-	sscanf(secret, "%s\t%04d\t%s\t%s\t%020ld",
+	sscanf(secret, "%s\t%04d\t%s\t%s\t%020lu",
 	       alg, seq, seed, buf, timeout);
 	
 	hex2bin(buf, otp, OTP_HASH_SIZE);
