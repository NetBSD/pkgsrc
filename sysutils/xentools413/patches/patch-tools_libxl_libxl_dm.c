$NetBSD: patch-tools_libxl_libxl_dm.c,v 1.2 2020/08/27 13:39:04 bouyer Exp $

--- tools/libxl/libxl_dm.c.orig	2020-05-14 14:19:32.000000000 +0200
+++ tools/libxl/libxl_dm.c	2020-08-27 14:12:38.150082263 +0200
@@ -742,6 +742,10 @@
         int nr_set_cpus = 0;
         char *s;
 
+	static char buf[12];
+	snprintf(buf, sizeof(buf), "%d", domid);
+        flexarray_append_pair(dm_envs, "XEN_DOMAIN_ID", buf);
+
         if (b_info->kernel) {
             LOGD(ERROR, domid, "HVM direct kernel boot is not supported by "
                  "qemu-xen-traditional");
@@ -1503,8 +1507,10 @@
                 flexarray_append(dm_args, "-netdev");
                 flexarray_append(dm_args,
                                  GCSPRINTF("type=tap,id=net%d,ifname=%s,"
+					   "br=%s,"
                                            "script=%s,downscript=%s",
                                            nics[i].devid, ifname,
+					   nics[i].bridge,
                                            libxl_tapif_script(gc),
                                            libxl_tapif_script(gc)));
 
@@ -1772,6 +1778,10 @@
     flexarray_append(dm_args, GCSPRINTF("%"PRId64, ram_size));
 
     if (b_info->type == LIBXL_DOMAIN_TYPE_HVM) {
+	static char buf[12];
+	snprintf(buf, sizeof(buf), "%d", guest_domid);
+        flexarray_append_pair(dm_envs, "XEN_DOMAIN_ID", buf);
+
         if (b_info->u.hvm.hdtype == LIBXL_HDTYPE_AHCI)
             flexarray_append_pair(dm_args, "-device", "ahci,id=ahci0");
         for (i = 0; i < num_disks; i++) {
@@ -3351,6 +3361,14 @@
 
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
@@ -3358,6 +3376,7 @@
         rc = rc ?: ERROR_FAIL;
         goto out;
     }
+#endif /* __NetBSD__ */
 
     /*
      * And kill everyone but me.
