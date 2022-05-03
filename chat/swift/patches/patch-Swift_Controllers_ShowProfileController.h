$NetBSD: patch-Swift_Controllers_ShowProfileController.h,v 1.1 2022/05/03 20:03:31 nia Exp $

GCC 11 build fix, via Arch Linux.

--- Swift/Controllers/ShowProfileController.h.orig	2018-04-06 10:06:46.000000000 +0000
+++ Swift/Controllers/ShowProfileController.h
@@ -18,6 +18,8 @@
 
 #include <Swift/Controllers/UIEvents/UIEvent.h>
 
+#include <map>
+
 namespace Swift {
     class VCardManager;
     class ProfileWindow;
