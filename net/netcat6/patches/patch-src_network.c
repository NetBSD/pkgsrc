$NetBSD: patch-src_network.c,v 1.1 2020/08/27 14:24:08 uwe Exp $

Do not set AI_ADDRCONFIG when we set AI_NUMERICHOST.  The semantic of
this combination is vague and it does the wrong thing at least on some
glibc versions.

--- src/network.c.orig	2006-01-19 22:46:23.000000000 +0000
+++ src/network.c
@@ -91,14 +91,14 @@ static int net_connect(const connection_
 	/* setup getaddrinfo hints */
 	memset(&hints, 0, sizeof(hints));
 	ca_to_addrinfo(&hints, attrs);
-#ifdef HAVE_GETADDRINFO_AI_ADDRCONFIG
-	/* make calls to getaddrinfo send AAAA queries only if at least one
-	 * IPv6 interface is configured */
-	hints.ai_flags |= AI_ADDRCONFIG;
-#endif
 	if (ca_is_flag_set(attrs, CA_NUMERIC_MODE))
 		hints.ai_flags |= AI_NUMERICHOST;
-
+#ifdef HAVE_GETADDRINFO_AI_ADDRCONFIG
+	else
+		/* make calls to getaddrinfo send AAAA queries only if
+		 * at least one IPv6 interface is configured */
+		hints.ai_flags |= AI_ADDRCONFIG;
+#endif
 	/* get addresses */
 	remote = ca_remote_address(attrs);
 	local = ca_local_address(attrs);
@@ -157,11 +157,12 @@ static int net_listen(const connection_a
 	memset(&hints, 0, sizeof(hints));
 	ca_to_addrinfo(&hints, attrs);
 	hints.ai_flags = AI_PASSIVE;
-#ifdef HAVE_GETADDRINFO_AI_ADDRCONFIG
-	hints.ai_flags |= AI_ADDRCONFIG;
-#endif
 	if (ca_is_flag_set(attrs, CA_NUMERIC_MODE))
 		hints.ai_flags |= AI_NUMERICHOST;
+#ifdef HAVE_GETADDRINFO_AI_ADDRCONFIG
+	else
+		hints.ai_flags |= AI_ADDRCONFIG;
+#endif
 
 	/* get addresses */
 	remote = ca_remote_address(attrs);
