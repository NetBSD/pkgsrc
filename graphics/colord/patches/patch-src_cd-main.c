$NetBSD: patch-src_cd-main.c,v 1.2 2026/04/26 14:48:56 vins Exp $

Make udev support optional. 

--- src/cd-main.c.orig	2025-06-23 14:06:37.000000000 +0000
+++ src/cd-main.c
@@ -60,7 +60,9 @@ typedef struct {
 	CdMappingDb		*mapping_db;
 	CdDeviceDb		*device_db;
 	CdProfileDb		*profile_db;
+#ifdef HAVE_UDEV
 	CdSensorClient		*sensor_client;
+#endif
 	GPtrArray		*sensors;
 	GPtrArray		*plugins;
 	GMainLoop		*loop;
@@ -1905,8 +1907,10 @@ cd_main_on_name_acquired_cb (GDBusConnec
 		cd_main_add_disk_device (priv, device_id);
 	}
 
+#ifdef HAVE_UDEV
 	/* add sensor devices */
 	cd_sensor_client_coldplug (priv->sensor_client);
+#endif
 
 	/* coldplug plugin devices */
 	cd_main_plugin_phase (priv, CD_PLUGIN_PHASE_COLDPLUG);
@@ -1936,7 +1940,7 @@ cd_main_on_name_lost_cb (GDBusConnection
 	g_main_loop_quit (priv->loop);
 }
 
-
+#ifdef HAVE_UDEV
 static void
 cd_main_client_sensor_added_cb (CdSensorClient *sensor_client_,
 				CdSensor *sensor,
@@ -1967,6 +1971,7 @@ cd_main_client_sensor_removed_cb (CdSens
 				       NULL);
 	g_ptr_array_remove (priv->sensors, sensor);
 }
+#endif
 
 static gboolean
 cd_main_timed_exit_cb (gpointer user_data)
@@ -2390,6 +2395,7 @@ main (int argc, char *argv[])
 	priv->devices_array = cd_device_array_new ();
 	priv->profiles_array = cd_profile_array_new ();
 	priv->sensors = g_ptr_array_new_with_free_func ((GDestroyNotify) g_object_unref);
+#ifdef HAVE_UDEV
 	priv->sensor_client = cd_sensor_client_new ();
 	g_signal_connect (priv->sensor_client, "sensor-added",
 			  G_CALLBACK (cd_main_client_sensor_added_cb),
@@ -2397,6 +2403,7 @@ main (int argc, char *argv[])
 	g_signal_connect (priv->sensor_client, "sensor-removed",
 			  G_CALLBACK (cd_main_client_sensor_removed_cb),
 			  priv);
+#endif
 
 	/* connect to the mapping db */
 	priv->mapping_db = cd_mapping_db_new ();
@@ -2519,8 +2526,10 @@ out:
 			g_ptr_array_unref (priv->sensors);
 		if (priv->plugins != NULL)
 			g_ptr_array_unref (priv->plugins);
+#ifdef HAVE_UDEV
 		if (priv->sensor_client != NULL)
 			g_object_unref (priv->sensor_client);
+#endif
 		if (priv->icc_store != NULL)
 			g_object_unref (priv->icc_store);
 		if (priv->mapping_db != NULL)
