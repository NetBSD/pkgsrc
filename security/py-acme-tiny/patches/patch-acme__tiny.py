$NetBSD: patch-acme__tiny.py,v 1.1 2018/03/10 17:18:42 schmonz Exp $

The user agreement URL moved. Find it again. (Upstream patch c4940d2.)

--- acme_tiny.py.orig	2016-08-18 03:29:25.000000000 +0000
+++ acme_tiny.py
@@ -82,7 +82,7 @@ def get_crt(account_key, csr, acme_dir, 
     log.info("Registering account...")
     code, result = _send_signed_request(CA + "/acme/new-reg", {
         "resource": "new-reg",
-        "agreement": "https://letsencrypt.org/documents/LE-SA-v1.1.1-August-1-2016.pdf",
+        "agreement": json.load(urlopen(CA + "/directory"))['meta']['terms-of-service'],
     })
     if code == 201:
         log.info("Registered!")
