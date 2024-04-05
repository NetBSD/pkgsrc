$NetBSD: patch-common_version.cpp,v 1.2 2024/04/05 09:22:33 adam Exp $

Recognise NetBSD.

--- common/version.cpp.orig	2024-04-05 09:11:41.485595483 +0000
+++ common/version.cpp
@@ -61,6 +61,8 @@
 #define ONOS    "[Windows]"
 #elif  __linux
 #define ONOS    "[Linux]"
+#elif __NetBSD__
+#define ONOS    "[NetBSD]"
 #elif __OpenBSD__
 #define ONOS    "[OpenBSD]"
 #elif  __CYGWIN__
