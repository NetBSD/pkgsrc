$NetBSD: patch-wmbiff_gnutls-common.c,v 1.1 2012/07/03 10:16:20 tron Exp $

Fix build with GnuTLS 3.0.

--- wmbiff/gnutls-common.c.orig	2004-06-23 03:52:42.000000000 +0100
+++ wmbiff/gnutls-common.c	2012-07-03 10:56:31.000000000 +0100
@@ -3,7 +3,6 @@
 #include <stdlib.h>
 #include <string.h>
 #include <gnutls/gnutls.h>
-#include <gnutls/extra.h>
 #include <gnutls/x509.h>
 #include <gnutls/openpgp.h>
 #include <time.h>
@@ -508,7 +507,6 @@
 
 	printf("Compression methods:");
 	printf(" ZLIB");
-	printf(", LZO");
 	printf(", NULL\n");
 }
 
@@ -636,8 +634,6 @@
 				comp_priority[j++] = GNUTLS_COMP_NULL;
 			if (strncasecmp(comp[i], "ZLI", 3) == 0)
 				comp_priority[j++] = GNUTLS_COMP_ZLIB;
-			if (strncasecmp(comp[i], "LZO", 3) == 0)
-				comp_priority[j++] = GNUTLS_COMP_LZO;
 		}
 		comp_priority[j] = 0;
 	}
