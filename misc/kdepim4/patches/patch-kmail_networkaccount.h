$NetBSD: patch-kmail_networkaccount.h,v 1.1 2012/11/11 22:29:14 joerg Exp $

--- kmail/networkaccount.h.orig	2012-11-09 14:02:41.000000000 +0000
+++ kmail/networkaccount.h
@@ -33,7 +33,6 @@
 
 #include <QString>
 
-class AccountManager;
 class KConfig/*Base*/;
 class KUrl;
 namespace KIO {
@@ -41,6 +40,7 @@ namespace KIO {
 }
 
 namespace KMail {
+  class AccountManager;
 
   class NetworkAccount : public KMAccount {
     Q_OBJECT
