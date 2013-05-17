$NetBSD: patch-kmail_mailcomposerIface.h,v 1.1 2013/05/17 13:19:10 joerg Exp $

--- kmail/mailcomposerIface.h.orig	2013-05-17 11:28:46.000000000 +0000
+++ kmail/mailcomposerIface.h
@@ -13,6 +13,10 @@
 class MailComposerIface : virtual public DCOPObject
 {
     K_DCOP
+
+  public:
+    MailComposerIface() : DCOPObject("MailComposerIface") {}
+
   k_dcop:
     /**
       Send message.      
