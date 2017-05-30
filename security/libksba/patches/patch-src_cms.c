$NetBSD: patch-src_cms.c,v 1.1 2017/05/30 22:40:17 gdt Exp $

Avoid dropping leading zeros in encoded session key.
Patch by Daiki Ueno, taken from discussion on gnupg-devel:

https://lists.gnupg.org/pipermail/gnupg-devel/2016-February/030825.html

(Upstream has been asked to apply this patch, but so far has not.)

--- src/cms.c.orig	2013-03-15 19:26:38.000000000 +0000
+++ src/cms.c
@@ -87,6 +87,8 @@ static const char oid_signingTime[9] = "
 
 static const char oidstr_smimeCapabilities[] = "1.2.840.113549.1.9.15";
 
+static const char oidstr_rsaEncryption[] = "1.2.840.113549.1.1.1";
+
 
 
 /* Helper for read_and_hash_cont().  */
@@ -1621,7 +1623,7 @@ ksba_cms_set_sig_val (ksba_cms_t cms, in
     return gpg_error (GPG_ERR_ENOMEM);
   if (n==3 && s[0] == 'r' && s[1] == 's' && s[2] == 'a')
     { /* kludge to allow "rsa" to be passed as algorithm name */
-      sv->algo = xtrystrdup ("1.2.840.113549.1.1.1");
+      sv->algo = xtrystrdup (oidstr_rsaEncryption);
       if (!sv->algo)
         {
           xfree (sv);
@@ -1674,9 +1676,10 @@ ksba_cms_set_sig_val (ksba_cms_t cms, in
       return gpg_error (GPG_ERR_INV_SEXP);
     }
 
-  if (n > 1 && !*s)
+  if (strcmp (sv->algo, oidstr_rsaEncryption) != 0 && n > 1 && !*s)
     { /* We might have a leading zero due to the way we encode
-         MPIs - this zero should not go into the OCTECT STRING.  */
+         MPIs - this zero should not go into the OCTECT STRING,
+         unless it is explicitly allowed in the signature scheme.  */
       s++;
       n--;
     }
@@ -1798,7 +1801,7 @@ ksba_cms_set_enc_val (ksba_cms_t cms, in
   xfree (cl->enc_val.algo);
   if (n==3 && s[0] == 'r' && s[1] == 's' && s[2] == 'a')
     { /* kludge to allow "rsa" to be passed as algorithm name */
-      cl->enc_val.algo = xtrystrdup ("1.2.840.113549.1.1.1");
+      cl->enc_val.algo = xtrystrdup (oidstr_rsaEncryption);
       if (!cl->enc_val.algo)
         return gpg_error (GPG_ERR_ENOMEM);
     }
@@ -1831,9 +1834,10 @@ ksba_cms_set_enc_val (ksba_cms_t cms, in
   if (!n || *s != ':')
     return gpg_error (GPG_ERR_INV_SEXP);
   s++;
-  if (n > 1 && !*s)
+  if (strcmp (cl->enc_val.algo, oidstr_rsaEncryption) != 0 && n > 1 && !*s)
     { /* We might have a leading zero due to the way we encode
-         MPIs - this zero should not go into the OCTECT STRING.  */
+         MPIs - this zero should not go into the OCTECT STRING,
+         unless it is explicitly allowed in the encryption scheme.  */
       s++;
       n--;
     }
