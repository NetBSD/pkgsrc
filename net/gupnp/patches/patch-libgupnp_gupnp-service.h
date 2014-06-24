$NetBSD: patch-libgupnp_gupnp-service.h,v 1.1 2014/06/24 06:10:54 dholland Exp $

Fix build.

--- libgupnp/gupnp-service.h~	2014-05-29 12:47:53.000000000 +0000
+++ libgupnp/gupnp-service.h
@@ -65,7 +65,10 @@ gupnp_service_action_get_type (void) G_G
 #define GUPNP_TYPE_SERVICE_ACTION (gupnp_service_action_get_type ())
 
 typedef struct _GUPnPServicePrivate GUPnPServicePrivate;
+#ifndef GUPNPSERVICE_DEFINED
+#define GUPNPSERVICE_DEFINED
 typedef struct _GUPnPService GUPnPService;
+#endif
 typedef struct _GUPnPServiceClass GUPnPServiceClass;
 
 /**
