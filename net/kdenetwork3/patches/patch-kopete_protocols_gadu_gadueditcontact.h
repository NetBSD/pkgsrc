$NetBSD: patch-kopete_protocols_gadu_gadueditcontact.h,v 1.1 2013/03/26 23:30:46 joerg Exp $

--- kopete/protocols/gadu/gadueditcontact.h.orig	2013-03-26 20:06:40.000000000 +0000
+++ kopete/protocols/gadu/gadueditcontact.h
@@ -31,7 +31,6 @@ class QLabel;
 class QString;
 class QWidget;
 class GaduContact;
-class GaduContactsList::ContactLine;
 class QListViewItem;
 
 class GaduEditContact : public KDialogBase
