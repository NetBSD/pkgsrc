$NetBSD: patch-htapp.cc,v 1.1 2020/05/30 20:48:59 joerg Exp $

--- htapp.cc.orig	2020-05-27 23:39:17.675968433 +0000
+++ htapp.cc
@@ -3023,7 +3023,7 @@ static uint isqr(uint u)
 {
 	uint a = 2;
 	uint b = u/a;
-	while (abs(a - b) > 1) {
+	while (abs((int)a - (int)b) > 1) {
 		a = (a+b)/2;
 		b = u/a;
         }
