$NetBSD: patch-pp__pack.c,v 1.1 2026/07/13 18:44:25 wiz Exp $

Perl versions through 5.43.10 have an integer overflow in
S_measure_struct leading to an out-of-bounds heap read in pack and
unpack
https://github.com/Perl/perl5/commit/40754edc72dd3e513d758153c0e2f0215897740e.patch
https://github.com/Perl/perl5/commit/5f7eb6bbbe0510964e3fb1d6bb691e5445913e55.patch

--- pp_pack.c.orig	2026-01-18 17:50:04.000000000 +0000
+++ pp_pack.c
@@ -513,12 +513,12 @@ S_measure_struct(pTHX_ tempsym_t* symptr)
                 break;
             case 'B':
             case 'b':
-                len = (len + 7)/8;
+                len = (len / 8) + !!(len % 8);
                 size = 1;
                 break;
             case 'H':
             case 'h':
-                len = (len + 1)/2;
+                len = (len / 2) + !!(len % 2);
                 size = 1;
                 break;
 
@@ -528,6 +528,10 @@ S_measure_struct(pTHX_ tempsym_t* symptr)
                 break;
             }
         }
+        if ((size > 0) &&
+                ((len > SSize_t_MAX / size) ||         /* detect overflow of len * size */
+                 (len * size > SSize_t_MAX - total)))  /* detect overflow of total + len * size */
+            croak("Pack template structure size is too large");
         total += len * size;
     }
     return total;
