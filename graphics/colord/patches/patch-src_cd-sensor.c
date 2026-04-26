$NetBSD: patch-src_cd-sensor.c,v 1.1 2026/04/26 14:48:56 vins Exp $

Make udev support optional.

--- src/cd-sensor.c.orig	2025-06-23 14:06:37.000000000 +0000
+++ src/cd-sensor.c
@@ -89,7 +89,9 @@ typedef struct
 	gchar				*serial;
 	gchar				*model;
 	gchar				*vendor;
+#ifdef HAVE_UDEV
 	GUdevDevice			*device;
+#endif
 	gboolean			 native;
 	gboolean			 embedded;
 	gboolean			 locked;
@@ -1229,8 +1231,12 @@ cd_sensor_register_object (CdSensor *sen
 const gchar *
 cd_sensor_get_device_path (CdSensor *sensor)
 {
+#ifdef HAVE_UDEV
 	CdSensorPrivate *priv = GET_PRIVATE (sensor);
 	return g_udev_device_get_sysfs_path (priv->device);
+#else
+	return NULL;
+#endif
 }
 
 const gchar *
@@ -1246,6 +1252,7 @@ cd_sensor_open_usb_device (CdSensor *sen
 			   gint interface,
 			   GError **error)
 {
+#ifdef HAVE_UDEV
 	CdSensorPrivate *priv = GET_PRIVATE (sensor);
 	guint8 busnum;
 	guint8 devnum;
@@ -1270,6 +1277,10 @@ cd_sensor_open_usb_device (CdSensor *sen
 		return NULL;
 	}
 	return g_object_ref (device);
+#else
+	g_set_error_literal (error, 1, 0, "failed: no gudev support");
+	return NULL;
+#endif
 }
 
 void
@@ -1283,6 +1294,7 @@ cd_sensor_add_cap (CdSensor *sensor, CdS
 
 }
 
+#ifdef HAVE_UDEV
 GUdevDevice *
 cd_sensor_get_device (CdSensor *sensor)
 {
@@ -1411,6 +1423,7 @@ cd_sensor_set_from_device (CdSensor *sen
 	/* success */
 	return TRUE;
 }
+#endif
 
 void
 cd_sensor_set_index (CdSensor *sensor,
@@ -1656,8 +1669,10 @@ cd_sensor_finalize (GObject *object)
 	g_hash_table_unref (priv->options);
 	g_hash_table_unref (priv->metadata);
 	g_object_unref (priv->usb_ctx);
+#ifdef HAVE_UDEV
 	if (priv->device != NULL)
 		g_object_unref (priv->device);
+#endif
 
 	G_OBJECT_CLASS (cd_sensor_parent_class)->finalize (object);
 }
