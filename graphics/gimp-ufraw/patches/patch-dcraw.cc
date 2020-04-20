$NetBSD: patch-dcraw.cc,v 1.1 2020/04/20 00:38:36 joerg Exp $

--- dcraw.cc.orig	2020-04-19 19:55:05.713900482 +0000
+++ dcraw.cc
@@ -9240,11 +9240,15 @@ canon_a5:
       filters = 0x16161616;
     }
     if (make[0] == 'O') {
-      i = find_green (12, 32, 1188864, 3576832);
-      c = find_green (12, 32, 2383920, 2387016);
-      if (abs(i) < abs(c)) {
-	SWAP(i,c);
+      float i_ = find_green (12, 32, 1188864, 3576832);
+      float c_ = find_green (12, 32, 2383920, 2387016);
+      if (abs(i_) < abs(c_)) {
+	c = i_;
+	i = c_;
 	load_flags = 24;
+      } else {
+	i = i_;
+	c = c_;
       }
       if ((int) i < 0) filters = 0x61616161;
     }
