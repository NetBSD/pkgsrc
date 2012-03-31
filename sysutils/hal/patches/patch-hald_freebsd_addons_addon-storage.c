$NetBSD: patch-hald_freebsd_addons_addon-storage.c,v 1.1 2012/03/31 16:06:56 ryoon Exp $

* From FreeBSD ports repository to fix build on FreeBSD 9.0 RELEASE.

--- hald/freebsd/addons/addon-storage.c.orig	2009-08-24 12:42:29.000000000 +0000
+++ hald/freebsd/addons/addon-storage.c
@@ -107,8 +107,12 @@ hf_addon_storage_update (void)
 
 	  if (hf_addon_storage_cdrom_eject_pressed(cdrom))
 	    {
+#if defined(__FreeBSD__)
+	      libhal_device_emit_condition(hfp_ctx, hfp_udi, "EjectPressed", "", NULL);
+#else
 	      libhal_device_emit_condition(hfp_ctx, hfp_udi, "EjectPressed", "", &hfp_error);
 	      dbus_error_free(&hfp_error);
+#endif
 	    }
 
 	  hfp_cdrom_free(cdrom);
@@ -164,11 +168,17 @@ unmount_volumes (void)
                                                          "block.storage_device",
 							 hfp_udi,
 							 &num_volumes,
+#if defined(__FreeBSD__)
+							 NULL)) != NULL)
+#else
 							 &hfp_error)) != NULL)
+#endif
     {
       int i;
 
+#if !defined(__FreeBSD__)
       dbus_error_free(&hfp_error);
+#endif
 
       for (i = 0; i < num_volumes; i++)
         {
@@ -176,7 +186,11 @@ unmount_volumes (void)
 
 	  vol_udi = volumes[i];
 
+#if defined(__FreeBSD__)
+	  if (libhal_device_get_property_bool(hfp_ctx, vol_udi, "volume.is_mounted", NULL))
+#else
 	  if (libhal_device_get_property_bool(hfp_ctx, vol_udi, "volume.is_mounted", &hfp_error))
+#endif
             {
               DBusMessage *msg = NULL;
 	      DBusMessage *reply = NULL;
@@ -185,7 +199,9 @@ unmount_volumes (void)
 	      char **options = NULL;
 	      char *devfile;
 
+#if !defined(__FreeBSD__)
 	      dbus_error_free(&hfp_error);
+#endif
               hfp_info("Forcing unmount of volume '%s'", vol_udi);
 
 	      dbus_connection = libhal_ctx_get_dbus_connection(hfp_ctx);
@@ -265,10 +281,16 @@ poll_for_media (boolean check_only, bool
       check_lock_state = FALSE;
 
       hfp_info("Checking whether device %s is locked by HAL", addon.device_file);
+#if defined(__FreeBSD__)
+      if (libhal_device_is_locked_by_others(hfp_ctx, hfp_udi, "org.freedesktop.Hal.Device.Storage", NULL))
+#else
       if (libhal_device_is_locked_by_others(hfp_ctx, hfp_udi, "org.freedesktop.Hal.Device.Storage", &hfp_error))
+#endif
         {
           hfp_info("... device %s is locked by HAL", addon.device_file);
+#if !defined(__FreeBSD__)
 	  dbus_error_free(&hfp_error);
+#endif
 	  is_locked_by_hal = TRUE;
 	  update_proc_title(addon.device_file);
 	  goto skip_check;
@@ -278,9 +300,13 @@ poll_for_media (boolean check_only, bool
           hfp_info("... device %s is not locked by HAL", addon.device_file);
 	  is_locked_by_hal = FALSE;
 	}
+#if defined(__FreeBSD__)
+      should_poll = libhal_device_get_property_bool(hfp_ctx, hfp_udi, "storage.media_check_enabled", NULL);
+#else
       dbus_error_free(&hfp_error);
 
       should_poll = libhal_device_get_property_bool(hfp_ctx, hfp_udi, "storage.media_check_enabled", &hfp_error);
+#endif
       dbus_error_free(&hfp_error);
       polling_disabled = ! should_poll;
       update_proc_title(addon.device_file);
@@ -314,8 +340,12 @@ poll_for_media (boolean check_only, bool
       unmount_volumes();
 #endif
 
+#if defined(__FreeBSD__)
+      libhal_device_rescan(hfp_ctx, hfp_udi, NULL);
+#else
       libhal_device_rescan(hfp_ctx, hfp_udi, &hfp_error);
       dbus_error_free(&hfp_error);
+#endif
       addon.had_media = has_media;
 
       return TRUE;
@@ -412,12 +442,19 @@ main (int argc, char **argv)
     ! strcmp(driver, "cd")))) && ! strcmp(removable, "true");
   addon.had_media = poll_for_media(TRUE, FALSE);
 
+#if defined(__FreeBSD__)
+  if (! libhal_device_addon_is_ready(hfp_ctx, hfp_udi, NULL))
+    goto end;
+
+  syscon = dbus_bus_get(DBUS_BUS_SYSTEM, NULL);
+#else
   if (! libhal_device_addon_is_ready(hfp_ctx, hfp_udi, &hfp_error))
     goto end;
   dbus_error_free(&hfp_error);
 
   syscon = dbus_bus_get(DBUS_BUS_SYSTEM, &hfp_error);
   dbus_error_free(&hfp_error);
+#endif
   assert(syscon != NULL);
   dbus_connection_set_exit_on_disconnect(syscon, 0);
 
@@ -452,12 +489,18 @@ main (int argc, char **argv)
 				      "    <method name=\"CheckForMedia\">\n"
 				      "      <arg name=\"call_had_sideeffect\" direction=\"out\" type=\"b\"/>\n"
 				      "    </method>\n",
+#if defined(__FreeBSD__)
+				      NULL))
+#else
 				      &hfp_error))
+#endif
     {
       hfp_critical("Cannot claim interface 'org.freedesktop.Hal.Device.Storage.Removable'");
       goto end;
     }
+#if !defined(__FreeBSD__)
   dbus_error_free(&hfp_error);
+#endif
 
   while (TRUE)
     {
