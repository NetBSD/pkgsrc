$NetBSD: patch-extras_immodules_common_scim-bridge-messenger.h,v 1.1 2012/08/19 08:09:08 obache Exp $

--- extras/immodules/common/scim-bridge-messenger.h.orig	2012-06-13 15:22:28.000000000 +0000
+++ extras/immodules/common/scim-bridge-messenger.h
@@ -33,6 +33,8 @@
  */
 typedef struct _ScimBridgeMessenger ScimBridgeMessenger;
 
+struct timeval;
+
 #ifdef __cplusplus
 extern "C"
 {
