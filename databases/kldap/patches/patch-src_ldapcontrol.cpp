$NetBSD: patch-src_ldapcontrol.cpp,v 1.1 2020/02/18 16:49:13 joerg Exp $

--- src/ldapcontrol.cpp.orig	2020-01-14 16:22:02.256391951 +0000
+++ src/ldapcontrol.cpp
@@ -123,7 +123,7 @@ int LdapControl::parsePageControl(QByteA
 
     Ber ber(d->mValue);
     int size;
-    if (ber.scanf(QStringLiteral("{iO}"), &size, &cookie) == -1) {
+    if (ber.scanf("{iO}", &size, &cookie) == -1) {
         return -1;
     } else {
         return size;
@@ -135,7 +135,7 @@ LdapControl LdapControl::createPageContr
     LdapControl control;
     Ber ber;
 
-    ber.printf(QStringLiteral("{iO}"), pagesize, &cookie);
+    ber.printf("{iO}", pagesize, &cookie);
     control.setOid(QStringLiteral("1.2.840.113556.1.4.319"));
     control.setValue(ber.flatten());
     return control;
