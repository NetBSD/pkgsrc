$NetBSD: patch-src_cd-sensor.h,v 1.1 2026/04/26 14:48:57 vins Exp $

Make udev support optional.

--- src/cd-sensor.h.orig	2025-06-23 14:06:37.000000000 +0000
+++ src/cd-sensor.h
@@ -27,10 +27,10 @@
 #include <glib-object.h>
 #include <gio/gio.h>
 #include <colord-private.h>
-
+#ifdef HAVE_UDEV
 #include <gudev/gudev.h>
+#endif
 #include <gusb.h>
-
 #include "cd-common.h"
 
 G_BEGIN_DECLS
@@ -66,10 +66,12 @@ gboolean	 cd_sensor_register_object	(CdS
 						 GDBusConnection	*connection,
 						 GDBusInterfaceInfo	*info,
 						 GError			**error);
+#ifdef HAVE_UDEV
 gboolean	 cd_sensor_set_from_device	(CdSensor		*sensor,
 						 GUdevDevice		*device,
 						 GError			**error);
 GUdevDevice	*cd_sensor_get_device		(CdSensor		*sensor);
+#endif
 void		 cd_sensor_set_index		(CdSensor		*sensor,
 						 guint			 idx);
 GUsbDevice	*cd_sensor_open_usb_device	(CdSensor		*sensor,
