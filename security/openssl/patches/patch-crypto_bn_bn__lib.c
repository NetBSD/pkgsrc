$NetBSD: patch-crypto_bn_bn__lib.c,v 1.1 2014/04/02 12:11:35 he Exp $

Part of fix for CVE-2014-0076.

--- crypto/bn/bn_lib.c.orig	2014-01-06 13:47:42.000000000 +0000
+++ crypto/bn/bn_lib.c
@@ -824,3 +824,55 @@ int bn_cmp_part_words(const BN_ULONG *a,
 		}
 	return bn_cmp_words(a,b,cl);
 	}
+
+/* 
+ * Constant-time conditional swap of a and b.  
+ * a and b are swapped if condition is not 0.  The code assumes that at most one bit of condition is set.
+ * nwords is the number of words to swap.  The code assumes that at least nwords are allocated in both a and b,
+ * and that no more than nwords are used by either a or b.
+ * a and b cannot be the same number
+ */
+void BN_consttime_swap(BN_ULONG condition, BIGNUM *a, BIGNUM *b, int nwords)
+	{
+	BN_ULONG t;
+	int i;
+
+	bn_wcheck_size(a, nwords);
+	bn_wcheck_size(b, nwords);
+
+	assert(a != b);
+	assert((condition & (condition - 1)) == 0);
+	assert(sizeof(BN_ULONG) >= sizeof(int));
+
+	condition = ((condition - 1) >> (BN_BITS2 - 1)) - 1;
+
+	t = (a->top^b->top) & condition;
+	a->top ^= t;
+	b->top ^= t;
+
+#define BN_CONSTTIME_SWAP(ind) \
+	do { \
+		t = (a->d[ind] ^ b->d[ind]) & condition; \
+		a->d[ind] ^= t; \
+		b->d[ind] ^= t; \
+	} while (0)
+ 
+ 
+	switch (nwords) {
+	default:
+		for (i = 10; i < nwords; i++) 
+			BN_CONSTTIME_SWAP(i);
+		/* Fallthrough */
+	case 10: BN_CONSTTIME_SWAP(9); /* Fallthrough */
+	case 9: BN_CONSTTIME_SWAP(8); /* Fallthrough */
+	case 8: BN_CONSTTIME_SWAP(7); /* Fallthrough */
+	case 7: BN_CONSTTIME_SWAP(6); /* Fallthrough */
+	case 6: BN_CONSTTIME_SWAP(5); /* Fallthrough */
+	case 5: BN_CONSTTIME_SWAP(4); /* Fallthrough */
+	case 4: BN_CONSTTIME_SWAP(3); /* Fallthrough */
+	case 3: BN_CONSTTIME_SWAP(2); /* Fallthrough */
+	case 2: BN_CONSTTIME_SWAP(1); /* Fallthrough */
+	case 1: BN_CONSTTIME_SWAP(0);
+	}
+#undef BN_CONSTTIME_SWAP
+}
