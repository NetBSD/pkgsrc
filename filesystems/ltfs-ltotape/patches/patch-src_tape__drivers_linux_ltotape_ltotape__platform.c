$NetBSD: patch-src_tape__drivers_linux_ltotape_ltotape__platform.c,v 1.1 2020/12/26 05:23:12 mef Exp $

ICU_6.8 adaptation

--- src/tape_drivers/linux/ltotape/ltotape_platform.c.orig	2019-03-15 04:24:46.000000000 +0000
+++ src/tape_drivers/linux/ltotape/ltotape_platform.c
@@ -292,8 +292,8 @@ int ltotape_scsiexec (ltotape_scsi_io_ty
  */
 int ltotape_map_st2sg (const char *devname, char *sgdevname)
 {
-  bool  found = FALSE;
-  bool  allocated = FALSE;
+  bool  found = false;
+  bool  allocated = false;
   int   fd = 0;
   int   outcome = 0;
   int   i = 0;
@@ -357,7 +357,7 @@ int ltotape_map_st2sg (const char *devna
 
     strncat (nstdevname, "/dev/nst", strlen ("/dev/nst"));
     strncat (nstdevname, temp, strlen (temp));
-    allocated = TRUE;
+    allocated = true;
 
     ltfsmsg (LTFS_DEBUG, "20101D", devname, nstdevname);
 
@@ -410,10 +410,10 @@ int ltotape_map_st2sg (const char *devna
       dev_lun     = (devinfo.four_in_one >> 8) & 0xFF;
       dev_channel = (devinfo.four_in_one >> 16) & 0xFF;
       dev_host_no = (devinfo.four_in_one >> 24) & 0xFF;
-      found = FALSE;
+      found = false;
       while (fscanf (fp, "%d %d %d %d %d %*d %*d %*d %*d", &sg_hba, &sg_chan, &sg_addr, &sg_lun, &sg_devtype) == 5) {
         if ((sg_hba == dev_host_no) && (sg_chan == dev_channel) && (sg_addr == dev_scsi_id) && (sg_lun == dev_lun)) {
-          found = TRUE;
+          found = true;
           break;
         } else {
           i++;
