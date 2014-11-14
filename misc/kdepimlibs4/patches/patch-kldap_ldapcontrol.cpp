$NetBSD: patch-kldap_ldapcontrol.cpp,v 1.1 2014/11/14 22:23:40 joerg Exp $

--- kldap/ldapcontrol.cpp.orig	2014-11-14 15:54:02.000000000 +0000
+++ kldap/ldapcontrol.cpp
@@ -124,7 +124,7 @@ int LdapControl::parsePageControl( QByte
 
   Ber ber( d->mValue );
   int size;
-  if ( ber.scanf( QLatin1String("{iO}"), &size, &cookie ) == -1 ) {
+  if ( ber.scanf( "{iO}", &size, &cookie ) == -1 ) {
     return -1;
   } else {
     return size;
@@ -136,7 +136,7 @@ LdapControl LdapControl::createPageContr
   LdapControl control;
   Ber ber;
 
-  ber.printf( QLatin1String("{iO}"), pagesize, &cookie );
+  ber.printf( "{iO}", pagesize, &cookie );
   control.setOid( QLatin1String("1.2.840.113556.1.4.319") );
   control.setValue( ber.flatten() );
   return control;
