$NetBSD: patch-libgupnp_gupnp-device.h,v 1.1 2014/06/24 06:10:54 dholland Exp $

Fix build.

--- libgupnp/gupnp-device.h~	2014-05-29 12:47:53.000000000 +0000
+++ libgupnp/gupnp-device.h
@@ -51,7 +51,10 @@ gupnp_device_get_type (void) G_GNUC_CONS
                  GUPnPDeviceClass))
 
 typedef struct _GUPnPDevicePrivate GUPnPDevicePrivate;
+#ifndef GUPNPDEVICE_DEFINED
+#define GUPNPDEVICE_DEFINED
 typedef struct _GUPnPDevice GUPnPDevice;
+#endif
 typedef struct _GUPnPDeviceClass GUPnPDeviceClass;
 
 /**
