$NetBSD: patch-kmymoney2_plugins_viewinterface.h,v 1.1 2011/12/23 01:19:16 joerg Exp $

--- kmymoney2/plugins/viewinterface.h.orig	2008-10-29 12:01:13.000000000 +0000
+++ kmymoney2/plugins/viewinterface.h
@@ -39,6 +39,8 @@ class KPopupMenu;
 // Project Includes
 
 #include <kmymoney/mymoneyaccount.h>
+#include <kmymoney/mymoneysplit.h>
+#include <kmymoney/mymoneytransaction.h>
 #include <kmymoney/mymoneyinstitution.h>
 #include <kmymoney/export.h>
 class KMyMoneyViewBase;
