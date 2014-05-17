$NetBSD: patch_examples_ldns-keygen.c,v 1.1 2014/05/17 14:55:51 he Exp $

Get bugfix #573: ldns-keygen write private keys with mode 0600.
From http://git.nlnetlabs.nl/ldns/commit/?h=develop&id=169f38c1e25750f935838b670871056428977e6b
Fixes CVE-2014-3209.

--- examples/ldns-keygen.c.orig	2010-10-18 13:59:21.000000000 +0000
+++ examples/ldns-keygen.c
@@ -10,6 +10,9 @@
 
 #include <ldns/ldns.h>
 
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <fcntl.h>
 #include <errno.h>
 
 #ifdef HAVE_SSL
@@ -48,6 +51,7 @@ int
 main(int argc, char *argv[])
 {
 	int c;
+	int fd;
 	char *prog;
 
 	/* default key size */
@@ -250,21 +254,21 @@ main(int argc, char *argv[])
 	/* print the priv key to stderr */
 	filename = LDNS_XMALLOC(char, strlen(owner) + 21);
 	snprintf(filename, strlen(owner) + 20, "K%s+%03u+%05u.private", owner, algorithm, (unsigned int) ldns_key_keytag(key));
-	file = fopen(filename, "w");
+	/* use open() here to prevent creating world-readable private keys (CVE-2014-3209)*/
+	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
+	if (fd < 0) {
+		goto fail;
+	}
+
+	file = fdopen(fd, "w");
 	if (!file) {
-		fprintf(stderr, "Unable to open %s: %s\n", filename, strerror(errno));
-		ldns_key_deep_free(key);
-		free(owner);
-		ldns_rr_free(pubkey);
-		ldns_rr_free(ds);
-		LDNS_FREE(filename);
-		exit(EXIT_FAILURE);
-	} else {
-		ldns_key_print(file, key);
-		fclose(file);
-		LDNS_FREE(filename);
+		goto fail;
 	}
 
+	ldns_key_print(file, key);
+	fclose(file);
+	LDNS_FREE(filename);
+
 	/* print the DS to .ds */
 	if (algorithm != LDNS_SIGN_HMACMD5 &&
 		algorithm != LDNS_SIGN_HMACSHA1 &&
@@ -296,6 +300,15 @@ main(int argc, char *argv[])
 	ldns_rr_free(pubkey);
 	ldns_rr_free(ds);
 	exit(EXIT_SUCCESS);
+
+fail:
+	fprintf(stderr, "Unable to open %s: %s\n", filename, strerror(errno));
+	ldns_key_deep_free(key);
+	free(owner);
+	ldns_rr_free(pubkey);
+	ldns_rr_free(ds);
+	LDNS_FREE(filename);
+	exit(EXIT_FAILURE);
 }
 #else
 int
