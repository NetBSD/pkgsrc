$NetBSD: patch-kopete_libkopete_kopetepasswordedaccount.h,v 1.1 2013/03/26 23:30:46 joerg Exp $

--- kopete/libkopete/kopetepasswordedaccount.h.orig	2013-03-26 19:43:12.000000000 +0000
+++ kopete/libkopete/kopetepasswordedaccount.h
@@ -21,10 +21,10 @@
 
 #include "kopete_export.h"
 
-class Kopete::OnlineStatus;
-
 namespace Kopete
 {
+    class OnlineStatus;
+
 
 class Password;
 
