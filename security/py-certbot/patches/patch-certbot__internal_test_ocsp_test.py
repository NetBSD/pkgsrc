$NetBSD: patch-certbot__internal_test_ocsp_test.py,v 1.1 2024/08/04 09:42:35 kim Exp $

Patch tests for py-cryptography 43 and later (#9968).
This is unlikely to be the official patch (#9667).

Source: https://github.com/certbot/certbot/pull/9968
See also: https://github.com/certbot/certbot/issues/9967

--- certbot/_internal/tests/ocsp_test.py
+++ certbot/_internal/tests/ocsp_test.py
@@ -324,8 +324,8 @@ def _construct_mock_ocsp_response(certificate_status, response_status):
         responder_name=responder.subject,
         certificates=[responder],
         hash_algorithm=hashes.SHA1(),
-        next_update=datetime.now(pytz.UTC).replace(tzinfo=None) + timedelta(days=1),
-        this_update=datetime.now(pytz.UTC).replace(tzinfo=None) - timedelta(days=1),
+        next_update_utc=datetime.now(pytz.UTC).replace(tzinfo=None) + timedelta(days=1),
+        this_update_utc=datetime.now(pytz.UTC).replace(tzinfo=None) - timedelta(days=1),
         signature_algorithm_oid=x509.oid.SignatureAlgorithmOID.RSA_WITH_SHA1,
     )
 
