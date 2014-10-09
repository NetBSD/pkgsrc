$NetBSD: patch-sshconnect.c,v 1.1.2.2 2014/10/09 13:53:43 tron Exp $

Fix for CVE-2014-2653 from
https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=742513.

--- sshconnect.c.orig	2014-02-06 22:24:34.000000000 +0000
+++ sshconnect.c
@@ -1213,6 +1213,51 @@ fail:
 	return -1;
 }
 
+static int
+check_host_key_sshfp(char *host, struct sockaddr *hostaddr, Key *host_key)
+{
+	int rc = -1;
+	int flags = 0;
+	Key *raw_key = NULL;
+
+	if (!options.verify_host_key_dns)
+		goto done;
+
+	/* XXX certs are not yet supported for DNS; try looking the raw key
+	 * up in the DNS anyway.
+	 */
+	if (key_is_cert(host_key)) {
+	  debug2("Extracting key from cert for SSHFP lookup");
+		raw_key = key_from_private(host_key);
+		if (key_drop_cert(raw_key))
+			fatal("Couldn't drop certificate");
+		host_key = raw_key;
+	}
+
+	if (verify_host_key_dns(host, hostaddr, host_key, &flags))
+		goto done;
+
+	if (flags & DNS_VERIFY_FOUND) {
+
+		if (options.verify_host_key_dns == 1 &&
+		    flags & DNS_VERIFY_MATCH &&
+		    flags & DNS_VERIFY_SECURE) {
+			rc = 0;
+		} else if (flags & DNS_VERIFY_MATCH) {
+			matching_host_key_dns = 1;
+		} else {
+			warn_changed_key(host_key);
+			error("Update the SSHFP RR in DNS with the new "
+			      "host key to get rid of this message.");
+		}
+	}
+
+done:
+	if (raw_key)
+		key_free(raw_key);
+	return rc;
+}
+
 /* returns 0 if key verifies or -1 if key does NOT verify */
 int
 verify_host_key(char *host, struct sockaddr *hostaddr, Key *host_key)
@@ -1224,25 +1269,8 @@ verify_host_key(char *host, struct socka
 	debug("Server host key: %s %s", key_type(host_key), fp);
 	free(fp);
 
-	/* XXX certs are not yet supported for DNS */
-	if (!key_is_cert(host_key) && options.verify_host_key_dns &&
-	    verify_host_key_dns(host, hostaddr, host_key, &flags) == 0) {
-		if (flags & DNS_VERIFY_FOUND) {
-
-			if (options.verify_host_key_dns == 1 &&
-			    flags & DNS_VERIFY_MATCH &&
-			    flags & DNS_VERIFY_SECURE)
-				return 0;
-
-			if (flags & DNS_VERIFY_MATCH) {
-				matching_host_key_dns = 1;
-			} else {
-				warn_changed_key(host_key);
-				error("Update the SSHFP RR in DNS with the new "
-				    "host key to get rid of this message.");
-			}
-		}
-	}
+	if (check_host_key_sshfp(host, hostaddr, host_key) == 0)
+		return 0;
 
 	return check_host_key(host, hostaddr, options.port, host_key, RDRW,
 	    options.user_hostfiles, options.num_user_hostfiles,
