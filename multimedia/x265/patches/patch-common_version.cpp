$NetBSD: patch-common_version.cpp,v 1.1 2021/04/10 08:36:03 adam Exp $

Recognise NetBSD.

--- common/version.cpp.orig	2021-04-10 08:24:32.907512619 +0000
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
