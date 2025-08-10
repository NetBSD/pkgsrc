$NetBSD: patch-xmpp_transports.py,v 1.6 2025/08/10 14:36:24 gdt Exp $

Upstream disables validating certificates.  In 2025, this is a bug.
Record how to address the bug, and why that fails.

https://github.com/xmpppy/xmpppy/issues/71

--- xmpp/transports.py.orig	2025-08-09 12:24:46.000000000 +0000
+++ xmpp/transports.py
@@ -385,6 +385,11 @@ class TLS(PlugIn):
         """ Here we should switch pending_data to hint mode."""
         tcpsock=self._owner.Connection
         context=ssl.SSLContext(ssl.PROTOCOL_TLS_CLIENT)
+        #pkgsrc:
+        #  - Choose defaults for 2025.
+        #  - https://github.com/xmpppy/xmpppy/issues/71
+        #  - \todo hostname is not set, and thus cannot be checked
+        #  - \todo "ssl.SSLCertVerificationError: (SSLCertVerificationError(1, '[SSL: CERTIFICATE_VERIFY_FAILED] certificate verify failed: unable to get local issuer certificate (_ssl.c:1010)'),)"
         context.check_hostname = False
         context.verify_mode = ssl.CERT_NONE
 
