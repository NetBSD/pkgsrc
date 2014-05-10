$NetBSD: patch-linkhash.c,v 1.1 2014/05/10 04:09:41 pho Exp $

GCC < 4.1 does not have atomic builtins.

TODO: This check should really be moved to configure.ac.

--- linkhash.c.orig	2014-05-10 03:58:56.000000000 +0000
+++ linkhash.c
@@ -405,7 +405,7 @@ unsigned long lh_char_hash(const void *k
 		int seed;
 		/* we can't use -1 as it is the unitialized sentinel */
 		while ((seed = json_c_get_random_seed()) == -1);
-#if defined __GNUC__
+#if defined __GNUC__ && __GNUC__ >= 4 && __GNUC_MINOR__ >= 1
 		__sync_val_compare_and_swap(&random_seed, -1, seed);
 #elif defined _MSC_VER
 		InterlockedCompareExchange(&random_seed, seed, -1);
