$NetBSD: patch-certbot_ocsp.py,v 1.1 2024/08/04 09:42:35 kim Exp $

Patch certbot/ocsp.py for py-cryptography 43 and later (#9968).
This is unlikely to be the official patch (#9667).

Source: https://github.com/certbot/certbot/pull/9968
See also: https://github.com/certbot/certbot/issues/9967

--- certbot/ocsp.py
+++ certbot/ocsp.py
@@ -235,11 +235,11 @@ def _check_ocsp_response(response_ocsp: 'ocsp.OCSPResponse', request_ocsp: 'ocsp
     # https://github.com/openssl/openssl/blob/ef45aa14c5af024fcb8bef1c9007f3d1c115bd85/crypto/ocsp/ocsp_cl.c#L338-L391
     # thisUpdate/nextUpdate are expressed in UTC/GMT time zone
     now = datetime.now(pytz.UTC).replace(tzinfo=None)
-    if not response_ocsp.this_update:
+    if not response_ocsp.this_update_utc:
         raise AssertionError('param thisUpdate is not set.')
-    if response_ocsp.this_update > now + timedelta(minutes=5):
+    if response_ocsp.this_update_utc > now + timedelta(minutes=5):
         raise AssertionError('param thisUpdate is in the future.')
-    if response_ocsp.next_update and response_ocsp.next_update < now - timedelta(minutes=5):
+    if response_ocsp.next_update_utc and response_ocsp.next_update_utc < now - timedelta(minutes=5):
         raise AssertionError('param nextUpdate is in the past.')
 
 

