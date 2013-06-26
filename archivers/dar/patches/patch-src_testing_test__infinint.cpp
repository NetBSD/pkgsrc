$NetBSD: patch-src_testing_test__infinint.cpp,v 1.1 2013/06/26 15:49:31 joerg Exp $

--- src/testing/test_infinint.cpp.orig	2013-06-20 19:28:49.000000000 +0000
+++ src/testing/test_infinint.cpp
@@ -83,9 +83,9 @@ static void routine1()
     infinint f2 = f1;
     infinint f3 = 0;
 
-    deci d1 = f1;
-    deci d2 = f2;
-    deci d3 = f3;
+    libdar::deci d1 = f1;
+    libdar::deci d2 = f2;
+    libdar::deci d3 = f3;
 
     ui->warning(d1.human() + " " + d2.human() + " " + d3.human());
 
@@ -98,7 +98,7 @@ static void routine1()
         if(fd >= 0)
         {
             f3 = infinint(*ui, fd);
-            d3 = deci(f3);
+            d3 = libdar::deci(f3);
             ui->warning(d3.human());
         }
         close(fd);
@@ -106,33 +106,33 @@ static void routine1()
     }
 
     f1 += 3;
-    d1 = deci(f1);
+    d1 = libdar::deci(f1);
     ui->warning(d1.human());
 
     f1 -= 2;
-    d1 = deci(f1);
+    d1 = libdar::deci(f1);
     ui->warning(d1.human());
 
     f1 *= 10;
-    d1 = deci(f1);
+    d1 = libdar::deci(f1);
     ui->warning(d1.human());
 
     f2 = f1;
     f1 /= 3;
-    d1 = deci(f1);
+    d1 = libdar::deci(f1);
     ui->warning(d1.human());
 
     f2 %= 3;
-    d2 = deci(f2);
+    d2 = libdar::deci(f2);
     ui->warning(d2.human());
 
     f2 >>= 12;
-    d2 = deci(f2);
+    d2 = libdar::deci(f2);
     ui->warning(d2.human());
 
     f1 = 4;
     f2 >>= f1;
-    d2 = deci(f2);
+    d2 = libdar::deci(f2);
     ui->warning(d2.human());
 
     f1 = 4+12;
@@ -143,9 +143,9 @@ static void routine1()
     cout << f3 << endl;
     cout << (123 << 16) << endl;
     f2 <<= 4+12;
-    d2 = deci(f2);
+    d2 = libdar::deci(f2);
     ui->warning(d2.human());
-    d3 = deci(f3);
+    d3 = libdar::deci(f3);
     ui->warning(d3.human());
 
     try
@@ -184,12 +184,12 @@ static void routine1()
     {
         for(f3 = 2; f3 <= f1; f3++)
         {
-            d1 = deci(f1);
-            d2 = deci(f2);
-            d3 = deci(f3);
+            d1 = libdar::deci(f1);
+            d2 = libdar::deci(f2);
+            d3 = libdar::deci(f3);
             ui->warning(d1.human() + " " + d2.human() + " " + d3.human());
             f2 *= f3;
-            d2 = deci(f2);
+            d2 = libdar::deci(f2);
             ui->warning(d2.human());
         }
     }
@@ -197,17 +197,17 @@ static void routine1()
     {
         ui->warning(e.get_message());
     }
-    d2 = deci(f2);
-    d1 = deci(f1);
+    d2 = libdar::deci(f2);
+    d1 = libdar::deci(f1);
     ui->warning(string("factoriel(") + d1.human() + ") = " + d2.human());
 }
 
 static void routine2()
 {
-    ui->warning(deci(infinint(2).power((U_I)0)).human());
-    ui->warning(deci(infinint(2).power(infinint(0))).human());
-    ui->warning(deci(infinint(2).power((U_I)1)).human());
-    ui->warning(deci(infinint(2).power(infinint(1))).human());
-    ui->warning(deci(infinint(2).power((U_I)2)).human());
-    ui->warning(deci(infinint(2).power(infinint(2))).human());
+    ui->warning(libdar::deci(infinint(2).power((U_I)0)).human());
+    ui->warning(libdar::deci(infinint(2).power(infinint(0))).human());
+    ui->warning(libdar::deci(infinint(2).power((U_I)1)).human());
+    ui->warning(libdar::deci(infinint(2).power(infinint(1))).human());
+    ui->warning(libdar::deci(infinint(2).power((U_I)2)).human());
+    ui->warning(libdar::deci(infinint(2).power(infinint(2))).human());
 }
