$NetBSD: patch-libgupnp_gupnp-acl.h,v 1.1 2014/06/24 06:10:54 dholland Exp $

Fix build.

--- libgupnp/gupnp-acl.h.orig	2014-05-29 12:51:43.000000000 +0000
+++ libgupnp/gupnp-acl.h
@@ -68,8 +68,14 @@ typedef struct _GUPnPAcl GUPnPAcl;
 typedef struct _GUPnPAclInterface GUPnPAclInterface;
 
 /* Forward declarations to avoid recursive includes */
+#ifndef GUPNPDEVICE_DEFINED
+#define GUPNPDEVICE_DEFINED
 typedef struct _GUPnPDevice GUPnPDevice;
+#endif
+#ifndef GUPNPSERVICE_DEFINED
+#define GUPNPSERVICE_DEFINED
 typedef struct _GUPnPService GUPnPService;
+#endif
 
 struct _GUPnPAclInterface {
     GTypeInterface parent;
