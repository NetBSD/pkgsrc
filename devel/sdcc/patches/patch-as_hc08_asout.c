$NetBSD: patch-as_hc08_asout.c,v 1.1 2025/12/18 15:43:42 ryoon Exp $

--- as/hc08/asout.c.orig	2006-04-22 21:35:27.000000000 +0000
+++ as/hc08/asout.c
@@ -231,7 +231,7 @@ char	*relp = { &rel[0] };
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
@@ -771,7 +771,7 @@ outdot()
  */
 
 VOID
-outchk(nt, nr)
+outchk(int nt, int nr)
 {
 	register struct area *ap;
 
@@ -1327,7 +1327,7 @@ out_t24(int n)
  */
 
 int
-lobyte(n)
+lobyte(int n)
 {
 	return (n&0377);
 }
@@ -1353,7 +1353,7 @@ lobyte(n)
  */
 
 int
-hibyte(n)
+hibyte(int n)
 {
 	return ((n>>8)&0377);
 }
