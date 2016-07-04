$NetBSD: patch-libxl_libxl__netbsd.c,v 1.1.1.1 2016/07/04 07:30:53 jnemeth Exp $

--- libxl/libxl_netbsd.c.orig	2016-06-20 12:08:22.000000000 +0000
+++ libxl/libxl_netbsd.c
@@ -68,7 +68,25 @@ int libxl__get_hotplug_script_info(libxl
 
     switch (dev->backend_kind) {
     case LIBXL__DEVICE_KIND_VBD:
+        if (num_exec != 0) {
+            LOG(DEBUG, "num_exec %d, not running hotplug scripts", num_exec);
+            rc = 0;
+            goto out;
+        }
+        rc = libxl__hotplug(gc, dev, args, action);
+        if (!rc) rc = 1;
+        break;
     case LIBXL__DEVICE_KIND_VIF:
+        /*
+         * If domain has a stubdom we don't have to execute hotplug scripts
+         * for emulated interfaces
+         */
+        if ((num_exec != 0) ||
+            (libxl_get_stubdom_id(CTX, dev->domid) && num_exec)) {
+            LOG(DEBUG, "num_exec %d, not running hotplug scripts", num_exec);
+            rc = 0;
+            goto out;
+        }
         rc = libxl__hotplug(gc, dev, args, action);
         if (!rc) rc = 1;
         break;
