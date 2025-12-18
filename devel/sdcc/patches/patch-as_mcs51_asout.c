$NetBSD: patch-as_mcs51_asout.c,v 1.1 2025/12/18 15:43:42 ryoon Exp $

--- as/mcs51/asout.c.orig	2025-12-18 06:33:12.832919475 +0000
+++ as/mcs51/asout.c
@@ -231,7 +231,7 @@ char    *relp = { &rel[0] };
  */
 
 VOID
-outab(b)
+outab(int b)
 {
         if (pass == 2) {
                 out_lb(b,0);
@@ -266,7 +266,7 @@ outab(b)
  */
 
 VOID
-outaw(w)
+outaw(int w)
 {
         if (pass == 2) {
                 out_lw(w,0);
@@ -744,7 +744,7 @@ outdot()
  */
 
 VOID
-outchk(nt, nr)
+outchk(int nt, int nr)
 {
         register struct area *ap;
 
@@ -1300,7 +1300,7 @@ out_t24(int n)
  */
 
 int
-lobyte(n)
+lobyte(int n)
 {
         return (n&0377);
 }
@@ -1326,7 +1326,7 @@ lobyte(n)
  */
 
 int
-hibyte(n)
+hibyte(int n)
 {
         return ((n>>8)&0377);
 }
