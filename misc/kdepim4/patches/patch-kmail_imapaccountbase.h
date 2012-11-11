$NetBSD: patch-kmail_imapaccountbase.h,v 1.1 2012/11/11 22:29:14 joerg Exp $

--- kmail/imapaccountbase.h.orig	2012-11-09 14:04:05.000000000 +0000
+++ kmail/imapaccountbase.h
@@ -37,7 +37,6 @@
 #include <QByteArray>
 #include "progressmanager.h"
 
-class AccountManager;
 class KMFolder;
 class KConfigGroup;
 class KMMessagePart;
@@ -55,6 +54,7 @@ namespace KPIM {
 }
 
 namespace KMail {
+  class AccountManager;
   struct ACLListEntry;
   class QuotaInfo;
   typedef QVector<KMail::ACLListEntry> ACLList;
