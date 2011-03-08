$NetBSD: patch-uuid.c,v 1.2 2011/03/08 03:20:16 brook Exp $

Use the openssl SHA1 API instead of the FreeBSD API.

--- uuid.c.orig	2010-03-14 03:04:29.000000000 -0600
+++ uuid.c	2011-02-12 10:51:10.000000000 -0700
@@ -40,7 +40,7 @@
 #undef uuid_hash
 
 #include <md5.h>
-#include <sha.h>
+#include <sha1.h>
 
 PG_MODULE_MAGIC;
 
@@ -158,13 +158,13 @@
 
 	case 5:  /* namespace-based SHA1 uuids */
 	{
-	    SHA_CTX ctx;
+	    SHA1_CTX ctx;
 	    unsigned char buf[20];
 
-	    SHA1_Init(&ctx);
-	    SHA1_Update(&ctx, ns, 16);
-	    SHA1_Update(&ctx, (unsigned char *)ptr, len);
-	    SHA1_Final(buf, &ctx);
+	    SHA1Init(&ctx);
+	    SHA1Update(&ctx, ns, 16);
+	    SHA1Update(&ctx, (unsigned char *)ptr, len);
+	    SHA1Final(buf, &ctx);
 
 	    sprintf(strbuf,
 		    "%02x%02x%02x%02x-"
