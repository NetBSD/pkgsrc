$NetBSD: patch-lib_pgp_keys_pgpRngRead.c,v 1.2 2014/11/28 10:53:40 bsiegert Exp $

--- lib/pgp/keys/pgpRngRead.c.orig	1997-08-09 21:45:09.000000000 +0000
+++ lib/pgp/keys/pgpRngRead.c
@@ -3368,7 +3368,7 @@ ringWrapObject (struct RingSet const *se
 	(void)obj;
 	(void)f;
 	return 0;
-#elif defined(WRAP_SUB);
+#elif defined(WRAP_SUB)
 	/*
 	* Just wrap subkeys, we'll let old PGP complain about DSA keys.
 	* It can't handle subkeys as we have them now.
