$NetBSD: patch-src_modules_mpqs.c,v 1.1 2015/01/23 15:07:53 joerg Exp $

--- src/modules/mpqs.c.orig	2015-01-22 19:57:31.000000000 +0000
+++ src/modules/mpqs.c
@@ -2345,7 +2345,7 @@ mpqs_combine_large_primes(mpqs_handle_t 
     *f = gerepileuptoint(av0, inv_q);
     return c;
   }
-  Y1 = strtoi(e[0].Y);
+  Y1 = pari_strtoi(e[0].Y);
   av2 = avma; /* preserve inv_q and Y1 */
 
   while (fgets(buf, MPQS_STRING_LENGTH, COMB))
@@ -2371,7 +2371,7 @@ mpqs_combine_large_primes(mpqs_handle_t 
         *f = gerepileuptoint(av0, inv_q);
         return c;
       }
-      Y1 = strtoi(e[i].Y);
+      Y1 = pari_strtoi(e[i].Y);
       i = 1 - i; /* subsequent relations go to other row */
       av2 = avma; /* preserve inv_q and Y1 */
       continue;
@@ -2381,7 +2381,7 @@ mpqs_combine_large_primes(mpqs_handle_t 
     memset((void *)ei, 0, ei_size * sizeof(long));
     mpqs_set_exponents(ei, e[0].E);
     mpqs_set_exponents(ei, e[1].E);
-    Y2 = strtoi(e[i].Y);
+    Y2 = pari_strtoi(e[i].Y);
     new_Y = modii(mulii(mulii(Y1, Y2), inv_q), h->N);
     new_Y1 = subii(h->N, new_Y);
     if (absi_cmp(new_Y1, new_Y) < 0) new_Y = new_Y1;
@@ -2692,7 +2692,7 @@ mpqs_add_relation(GEN Y_prod, GEN N, lon
   s = strchr(rel, ':') - 1;
   *s = '\0';
   
-  res = remii(mulii(Y_prod, strtoi(rel)), N);
+  res = remii(mulii(Y_prod, pari_strtoi(rel)), N);
 
   s = strtok(s + 3, " \n");
   while (s != NULL)
