$NetBSD: patch-src_modules_mpqs.c,v 1.2 2016/03/03 13:28:22 wiz Exp $

--- src/modules/mpqs.c.orig	2014-09-15 11:32:55.000000000 +0000
+++ src/modules/mpqs.c
@@ -2215,7 +2215,7 @@ mpqs_combine_large_primes(mpqs_handle_t 
     *f = gerepileuptoint(av0, inv_q);
     return c;
   }
-  Y1 = strtoi(e[0].Y);
+  Y1 = pari_strtoi(e[0].Y);
   av2 = avma; /* preserve inv_q and Y1 */
 
   while (fgets(buf, MPQS_STRING_LENGTH, COMB))
@@ -2241,7 +2241,7 @@ mpqs_combine_large_primes(mpqs_handle_t 
         *f = gerepileuptoint(av0, inv_q);
         return c;
       }
-      Y1 = strtoi(e[i].Y);
+      Y1 = pari_strtoi(e[i].Y);
       i = 1 - i; /* subsequent relations go to other row */
       av2 = avma; /* preserve inv_q and Y1 */
       continue;
@@ -2251,7 +2251,7 @@ mpqs_combine_large_primes(mpqs_handle_t 
     memset((void *)ei, 0, ei_size * sizeof(long));
     mpqs_set_exponents(ei, e[0].E);
     mpqs_set_exponents(ei, e[1].E);
-    Y2 = strtoi(e[i].Y);
+    Y2 = pari_strtoi(e[i].Y);
     new_Y = modii(mulii(mulii(Y1, Y2), inv_q), h->N);
     new_Y1 = subii(h->N, new_Y);
     if (absi_cmp(new_Y1, new_Y) < 0) new_Y = new_Y1;
@@ -2362,7 +2362,7 @@ mpqs_add_relation(GEN Y_prod, GEN N, lon
   s = strchr(rel, ':') - 1;
   *s = '\0';
 
-  res = remii(mulii(Y_prod, strtoi(rel)), N);
+  res = remii(mulii(Y_prod, pari_strtoi(rel)), N);
 
   s = paristrtok_r(s + 3, " \n", &tok);
   while (s != NULL)
