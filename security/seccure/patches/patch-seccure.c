$NetBSD: patch-seccure.c,v 1.1 2013/03/02 17:57:53 joerg Exp $

--- seccure.c.orig	2013-03-01 23:39:45.000000000 +0000
+++ seccure.c
@@ -685,10 +685,11 @@ int app_verify(const char *pubkey, const
     fatal("Invalid verification key (wrong length)");
   
   if (decompress_from_string(&Q, pubkey, DF_COMPACT, cp)) {
-    union {
-      char compact[cp->sig_len_compact + 2];
-      char bin[cp->sig_len_bin];
-    } sigbuf;
+    char *sigbuf;
+    size_t len = cp->sig_len_compact + 2;
+    if (len < cp->sig_len_bin)
+	len = cp->sig_len_bin;
+    sigbuf = alloca(len);
     
     err = gcry_md_open(&mh, GCRY_MD_SHA512, 0);
     if (gcry_err_code(err))
@@ -700,7 +701,7 @@ int app_verify(const char *pubkey, const
 	fatal_errno("Cannot open signature file", errno);
 
       if (opt_sigbin) {
-	if (fread(sigbuf.bin, cp->sig_len_bin, 1, sigfile) != 1) {
+	if (fread(sigbuf, cp->sig_len_bin, 1, sigfile) != 1) {
 	  if (ferror(sigfile))
 	    fatal_errno("Cannot read signature", errno);
 	  else {
@@ -711,11 +712,11 @@ int app_verify(const char *pubkey, const
 	}
       }
       else {
-	sigbuf.compact[0] = 0;
-	if (! fgets(sigbuf.compact, cp->sig_len_compact + 2, sigfile) && 
+	sigbuf[0] = 0;
+	if (! fgets(sigbuf, cp->sig_len_compact + 2, sigfile) && 
 	    ferror(sigfile))
 	  fatal_errno("Cannot read signature", errno);
-	sigbuf.compact[strcspn(sigbuf.compact, " \r\n")] = '\0';
+	sigbuf[strcspn(sigbuf, " \r\n")] = '\0';
       }
       
       if (fclose(sigfile))
@@ -727,12 +728,12 @@ int app_verify(const char *pubkey, const
 
     if (opt_sigappend) {
       if (opt_sigbin)
-	verisign_loop(opt_fdin, opt_fdout, &mh, sigbuf.bin, 
+	verisign_loop(opt_fdin, opt_fdout, &mh, sigbuf, 
 		      cp->sig_len_bin, opt_sigcopy);
       else {
-	verisign_loop(opt_fdin, opt_fdout, &mh, sigbuf.compact,
+	verisign_loop(opt_fdin, opt_fdout, &mh, sigbuf,
 		      cp->sig_len_compact, opt_sigcopy);
-	sigbuf.compact[cp->sig_len_compact] = 0;
+	sigbuf[cp->sig_len_compact] = 0;
       }
     }
     else
@@ -751,7 +752,7 @@ int app_verify(const char *pubkey, const
 	
     if (! opt_sigbin) {
       if (! sig)
-	sig = sigbuf.compact;
+	sig = sigbuf;
       if (strlen(sig) != cp->sig_len_compact) {
 	print_quiet("Invalid signature (wrong length)!\n", 1);
 	goto error;
@@ -763,7 +764,7 @@ int app_verify(const char *pubkey, const
 	}
     }
     else
-      assert(deserialize_mpi(&s, DF_BIN, sigbuf.bin, cp->sig_len_bin));
+      assert(deserialize_mpi(&s, DF_BIN, sigbuf, cp->sig_len_bin));
 
     if ((res = ECDSA_verify(md, &Q, s, cp)))
       print_quiet("Signature successfully verified!\n", 0);
