--- ./tools/libxl/libxl_dm.c.orig	2020-05-08 21:07:35.429483538 +0200
+++ ./tools/libxl/libxl_dm.c	2020-05-08 21:21:20.119079508 +0200
@@ -3351,6 +3351,14 @@
 
     LOGD(DEBUG, domid, "DM reaper: calling setresuid(%d, %d, 0)",
          reaper_uid, dm_kill_uid);
+#ifdef __NetBSD__
+    r = setuid(dm_kill_uid);
+    if (r) {
+        LOGED(ERROR, domid, "setuid to %d", dm_kill_uid);
+        rc = rc ?: ERROR_FAIL;
+        goto out;
+    }
+#else /* __NetBSD__ */
     r = setresuid(reaper_uid, dm_kill_uid, 0);
     if (r) {
         LOGED(ERROR, domid, "setresuid to (%d, %d, 0)",
@@ -3358,6 +3366,7 @@
         rc = rc ?: ERROR_FAIL;
         goto out;
     }
+#endif /* __NetBSD__ */
 
     /*
      * And kill everyone but me.
