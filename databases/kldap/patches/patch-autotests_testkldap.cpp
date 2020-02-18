$NetBSD: patch-autotests_testkldap.cpp,v 1.1 2020/02/18 16:49:13 joerg Exp $

--- autotests/testkldap.cpp.orig	2020-01-14 16:28:11.689663234 +0000
+++ autotests/testkldap.cpp
@@ -89,37 +89,37 @@ void KLdapTest::testBer()
 
     ainteger = 23543;
 
-    ber1.printf(QStringLiteral("i"), ainteger);
-    ber2.printf(QStringLiteral("o"), &aoctetString1);
-    ber3.printf(QStringLiteral("O"), &aoctetString2);
-    ber4.printf(QStringLiteral("s"), &aoctetString3);
-    ber5.printf(QStringLiteral("{v}"), &alist1);
-    ber6.printf(QStringLiteral("{V}"), &alist2);
-    ber7.printf(QStringLiteral("oi{v}O"), &aoctetString1, ainteger, &alist2, &aoctetString2);
+    ber1.printf("i", ainteger);
+    ber2.printf("o", &aoctetString1);
+    ber3.printf("O", &aoctetString2);
+    ber4.printf("s", &aoctetString3);
+    ber5.printf("{v}", &alist1);
+    ber6.printf("{V}", &alist2);
+    ber7.printf("oi{v}O", &aoctetString1, ainteger, &alist2, &aoctetString2);
 
     //test integer:
     bber = ber1;
-    bber.scanf(QStringLiteral("i"), &binteger);
+    bber.scanf("i", &binteger);
     QCOMPARE(ainteger, binteger);
 
     //test octet strings:
     bber = ber2;
-    bber.scanf(QStringLiteral("o"), &boctetString1);
+    bber.scanf("o", &boctetString1);
     QCOMPARE(aoctetString1, boctetString1);
     bber = ber3;
-    bber.scanf(QStringLiteral("o"), &boctetString2);
+    bber.scanf("o", &boctetString2);
     QCOMPARE(aoctetString2, boctetString2);
     bber = ber4;
-    bber.scanf(QStringLiteral("o"), &boctetString3);
+    bber.scanf("o", &boctetString3);
     QCOMPARE(aoctetString3, boctetString3);
 
     //test sequence of octet strings:
     bber = ber5;
-    bber.scanf(QStringLiteral("v"), &blist1);
+    bber.scanf("v", &blist1);
     QCOMPARE(alist1, blist1);
 
     bber = ber6;
-    bber.scanf(QStringLiteral("v"), &blist2);
+    bber.scanf("v", &blist2);
     QCOMPARE(alist2, blist2);
 
     //complex tests
@@ -129,7 +129,7 @@ void KLdapTest::testBer()
     blist2.clear();
 
     bber = ber7;
-    bber.scanf(QStringLiteral("oivO"), &boctetString1, &binteger, &blist2, &boctetString2);
+    bber.scanf("oivO", &boctetString1, &binteger, &blist2, &boctetString2);
     QCOMPARE(aoctetString1, boctetString1);
     QCOMPARE(aoctetString2, boctetString2);
     QCOMPARE(alist2, blist2);
