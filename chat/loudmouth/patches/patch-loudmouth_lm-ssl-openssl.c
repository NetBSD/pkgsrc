$NetBSD: patch-loudmouth_lm-ssl-openssl.c,v 1.1 2021/01/23 09:08:07 wiz Exp $

From 792d8bd529f5dc0577dcc28c5f31b6a437d970fa Mon Sep 17 00:00:00 2001
From: tmp170422 <tmp131110@ya.ru>
Date: Sat, 22 Apr 2017 18:30:57 +0300
Subject: [PATCH] Fix an issue with wildcard domain names in CN

When CN contains wildcards, the SAN list would be checked against corrupt server name.
---
 loudmouth/lm-ssl-openssl.c | 121 +++++++++++++++++++++----------------
 1 file changed, 69 insertions(+), 52 deletions(-)

https://github.com/mcabber/loudmouth/commit/792d8bd529f5dc0577dcc28c5f31b6a437d970fa.patch

with a manual compilation fix (missing ')')

--- loudmouth/lm-ssl-openssl.c.orig	2016-02-14 17:05:11.000000000 +0000
+++ loudmouth/lm-ssl-openssl.c
@@ -118,11 +118,35 @@ ssl_verify_cb (int preverify_ok, X509_ST
     return 1;
 }
 
+static gboolean
+ssl_match_domain_name (const gchar *server, const gchar *domain)
+{
+    if (domain[0]=='*' && domain[1]=='.') {
+        /* leftmost part wildcard */
+        ++domain;
+
+        if (strchr(domain, '*') != NULL) {
+            /* multiple wildcards not allowed */
+            return FALSE;
+        }
+
+        server = strchr(server, '.'); /* eat the leftmost part */
+        if (server == NULL) {
+            return FALSE;
+        }
+
+        /* fall thru for wildcard match */
+    }
+
+    return (!strcasecmp(server, domain));
+}
+
 /* side effect: fills the ssl->fingerprint buffer */
 static gboolean
 ssl_verify_certificate (LmSSL *ssl, const gchar *server)
 {
     gboolean retval = TRUE;
+    gboolean match_result = FALSE;
     LmSSLBase *base;
     long verify_res;
     int rc;
@@ -219,70 +243,63 @@ ssl_verify_certificate (LmSSL *ssl, cons
 
     /* FWB: deprecated call, can only get first entry */
     if (X509_NAME_get_text_by_NID(crt_subj, NID_commonName, cn, LM_SSL_CN_MAX) > 0) {
-        gchar *domain = cn;
 
         g_log (LM_LOG_DOMAIN, LM_LOG_LEVEL_SSL,
                "%s: server = '%s', cn = '%s'\n",
                __FILE__, server, cn);
 
-        if (domain != NULL) {
-
-            if ((cn[0] == '*') && (cn[1] == '.')) {
-                /*
-                 * FWB: huh? ever tested?
-                 * server="sub.domain.tld";
-                 * cn="*.domain.tld";
-                 * domain=strstr(cn, server); ???
-                 */
-                /* domain = strstr (cn, server); */
-                server = strchr(server, '.') + 1;
-                domain = cn + 2;
-            }
-
-            if (strncasecmp (server, domain, LM_SSL_CN_MAX) != 0) {
-                /* FWB: CN doesn't match, try SANs */
-                int subject_alt_names_nb = -1;
-                int san_result = 0;
-                int san_counter;
-                STACK_OF(GENERAL_NAME) *subject_alt_names = NULL;
-
-                /* g_log (LM_LOG_DOMAIN, LM_LOG_LEVEL_SSL, "%s: CN does not match server name\n", __FILE__); */
-                // Try to extract the names within the SAN extension from the certificate
-                subject_alt_names = X509_get_ext_d2i((X509 *) srv_crt, NID_subject_alt_name, NULL, NULL);
-                if (subject_alt_names != NULL) {
-
-                    // Check each name within the extension
-                    subject_alt_names_nb = sk_GENERAL_NAME_num(subject_alt_names);
-                    for (san_counter=0; san_counter<subject_alt_names_nb; san_counter++) {
-                        const GENERAL_NAME *current_name = sk_GENERAL_NAME_value(subject_alt_names, san_counter);
-                        if (current_name->type == GEN_DNS) {
-                            // Current name is a DNS name, let's check it, it's ASCII
-                            if (strcasecmp(server, (char *)current_name->d.dNSName->data) == 0) {
-                                g_log (LM_LOG_DOMAIN, LM_LOG_LEVEL_SSL, "%s: found SAN '%s' - MATCH\n", __FILE__, current_name->d.dNSName->data);
-                                san_result = 1; /* break; */
-                            } else {
-                                g_log (LM_LOG_DOMAIN, LM_LOG_LEVEL_SSL, "%s: found SAN '%s'\n", __FILE__, current_name->d.dNSName->data);
-                            }
-                        }
-                    }
-
-                }
-                sk_GENERAL_NAME_pop_free(subject_alt_names, GENERAL_NAME_free);
-                if (!san_result) goto cn_and_san_mismatch;
-            } /* SAN */
+        if (cn != NULL && ssl_match_domain_name(server, cn)) {
+            match_result = TRUE;
         } else {
-            cn_and_san_mismatch:
-            if (base->func (ssl,
-                            LM_SSL_STATUS_CERT_HOSTNAME_MISMATCH,
-                            base->func_data) != LM_SSL_RESPONSE_CONTINUE) {
-                retval = FALSE;
-            }
+            /* g_log (LM_LOG_DOMAIN, LM_LOG_LEVEL_SSL, "%s: CN does not match server name\n", __FILE__); */
         }
     } else {
         g_log (LM_LOG_DOMAIN, LM_LOG_LEVEL_SSL,
                "X509_NAME_get_text_by_NID() failed");
     }
 
+    /* RFC6125: "...However, it is perfectly acceptable for the subject field to be empty,
+     * as long as the certificate contains a subject alternative name ("subjectAltName")
+     * extension that includes at least one subjectAltName entry"
+     */
+    if (!match_result) {
+        /* FWB: CN doesn't match, try SANs */
+        int subject_alt_names_nb = -1;
+        int san_counter;
+        STACK_OF(GENERAL_NAME) *subject_alt_names = NULL;
+
+        // Try to extract the names within the SAN extension from the certificate
+        subject_alt_names = X509_get_ext_d2i((X509 *) srv_crt, NID_subject_alt_name, NULL, NULL);
+        if (subject_alt_names != NULL) {
+
+            // Check each name within the extension
+            subject_alt_names_nb = sk_GENERAL_NAME_num(subject_alt_names);
+            for (san_counter=0; san_counter<subject_alt_names_nb; san_counter++) {
+                const GENERAL_NAME *current_name = sk_GENERAL_NAME_value(subject_alt_names, san_counter);
+                if (current_name->type == GEN_DNS) {
+                    // Current name is a DNS name, let's check it, it's ASCII
+                    if (ssl_match_domain_name(server, (const char *)current_name->d.dNSName->data)) {
+                        g_log (LM_LOG_DOMAIN, LM_LOG_LEVEL_SSL, "%s: found SAN '%s' - MATCH\n", __FILE__, current_name->d.dNSName->data);
+                        match_result = TRUE; /* break; */
+                    } else {
+                        g_log (LM_LOG_DOMAIN, LM_LOG_LEVEL_SSL, "%s: found SAN '%s'\n", __FILE__, current_name->d.dNSName->data);
+                    }
+                }
+            }
+
+        }
+
+        sk_GENERAL_NAME_pop_free(subject_alt_names, GENERAL_NAME_free);
+    }
+
+    if (!match_result) {
+        if (base->func (ssl,
+                        LM_SSL_STATUS_CERT_HOSTNAME_MISMATCH,
+                        base->func_data) != LM_SSL_RESPONSE_CONTINUE) {
+            retval = FALSE;
+        }
+    }
+
     g_log (LM_LOG_DOMAIN, LM_LOG_LEVEL_SSL,
            "%s:\n\tIssuer: %s\n\tSubject: %s\n\tFor: %s\n",
            __FILE__,
