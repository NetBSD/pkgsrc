$NetBSD: patch-kmail_networkaccount.h,v 1.1 2012/05/04 16:27:59 joerg Exp $

--- kmail/networkaccount.h.orig	2012-04-27 16:26:50.000000000 +0000
+++ kmail/networkaccount.h
@@ -33,7 +33,6 @@
 
 #include <qstring.h>
 
-class AccountManager;
 class KConfig/*Base*/;
 class KURL;
 namespace KIO {
@@ -42,6 +41,7 @@ namespace KIO {
 }
 
 namespace KMail {
+  class AccountManager;
 
   class NetworkAccount : public KMAccount {
     Q_OBJECT
