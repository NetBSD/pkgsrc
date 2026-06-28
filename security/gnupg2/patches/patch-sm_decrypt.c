$NetBSD: patch-sm_decrypt.c,v 1.1.2.2 2026/06/28 11:23:21 bsiegert Exp $

gpgsm: Require a minimum tag length for GCM decryption.
* sm/decrypt.c (gpgsm_decrypt): Require a minimum authtaglen.
--

Reported-by: Thai Duong <thai@calif.io>
This is similar to OpenSSL's
CVE-id: CVE-2026-34182

https://github.com/gpg/gnupg/commit/4c7e68cf3d335328821bdbb70db309a60d0e4fd4

--- sm/decrypt.c.orig	2026-05-13 12:33:59.000000000 +0000
+++ sm/decrypt.c
@@ -1447,7 +1447,14 @@ gpgsm_decrypt (ctrl_t ctrl, estream_t in_fp, estream_t
                 }
               if (DBG_CRYPTO)
                 log_printhex (authtag, authtaglen, "Authtag ...:");
-              rc = gcry_cipher_checktag (dfparm.hd, authtag, authtaglen);
+              if (authtaglen < 12)
+                {
+                  log_info ("authentication tag is too short (%zu octets)\n",
+                            authtaglen);
+                  rc = gpg_error (GPG_ERR_CHECKSUM);
+                }
+              else
+                rc = gcry_cipher_checktag (dfparm.hd, authtag, authtaglen);
               xfree (authtag);
               if (rc)
                 log_error ("data is not authentic: %s\n", gpg_strerror (rc));
