$NetBSD: patch-src_tape__drivers_linux_ltotape_ltotape.c,v 1.1 2020/12/26 05:23:12 mef Exp $

ICU_6.8 adaptation

--- src/tape_drivers/linux/ltotape/ltotape.c.orig	2019-03-15 04:24:46.000000000 +0000
+++ src/tape_drivers/linux/ltotape/ltotape.c
@@ -538,11 +538,11 @@ int ltotape_read (void *device, char *bu
       break;
     case -EFAULT:
       ltfsmsg (LTFS_ERR, "20041E", "read");
-      ltotape_log_snapshot (device, FALSE);
+      ltotape_log_snapshot (device, false);
       break;
     case -EIO:
       ltfsmsg (LTFS_ERR, "20042E", "read");
-      ltotape_log_snapshot (device, FALSE);
+      ltotape_log_snapshot (device, false);
       break;
     case -ENOMEM:
       ltfsmsg (LTFS_ERR, "20043E", "read");
@@ -552,20 +552,20 @@ int ltotape_read (void *device, char *bu
       break;
     case -EPERM:
       ltfsmsg (LTFS_ERR, "20045E", "read");
-      ltotape_log_snapshot (device, FALSE);
+      ltotape_log_snapshot (device, false);
       break;
     case -ETIMEDOUT:
       ltfsmsg (LTFS_ERR, "20046E", "read");
-      ltotape_log_snapshot (device, FALSE);
+      ltotape_log_snapshot (device, false);
       break;
       // read specific errors
     case -EINVAL:
       ltfsmsg (LTFS_ERR, "20047E", "read");
-      ltotape_log_snapshot (device, FALSE);
+      ltotape_log_snapshot (device, false);
       break;
     case -EAGAIN:
       ltfsmsg (LTFS_ERR, "20055E", "read");
-      ltotape_log_snapshot (device, FALSE);
+      ltotape_log_snapshot (device, false);
       break;
     default:
       ltfsmsg (LTFS_ERR, "20054E", "read", -rc);
@@ -604,15 +604,15 @@ int ltotape_write (void *device, const c
       // General errors
     case -EBUSY:
       ltfsmsg (LTFS_ERR, "20040E", "write");
-      ltotape_log_snapshot (device, FALSE);
+      ltotape_log_snapshot (device, false);
       break;
     case -EFAULT:
       ltfsmsg (LTFS_ERR, "20041E", "write");
-      ltotape_log_snapshot (device, FALSE);
+      ltotape_log_snapshot (device, false);
       break;
     case -EIO:
       ltfsmsg (LTFS_ERR, "20042E", "write");
-      ltotape_log_snapshot (device, FALSE);
+      ltotape_log_snapshot (device, false);
       break;
     case -ENOMEM:
       ltfsmsg (LTFS_ERR, "20043E", "write");
@@ -625,12 +625,12 @@ int ltotape_write (void *device, const c
       break;
     case -ETIMEDOUT:
       ltfsmsg (LTFS_ERR, "20046E", "write");
-      ltotape_log_snapshot (device, FALSE);
+      ltotape_log_snapshot (device, false);
       break;
       // write specific errors
     case -EINVAL:
       ltfsmsg (LTFS_ERR, "20047E", "write");
-      ltotape_log_snapshot (device, FALSE);
+      ltotape_log_snapshot (device, false);
       break;
     case -ENOSPC:
       ltfsmsg (LTFS_WARN, "20048W", "write");
@@ -840,7 +840,7 @@ int ltotape_locate (void *device, struct
 
     } else {
       ltfsmsg (LTFS_ERR, "20064E", status);
-      ltotape_log_snapshot (device, FALSE);
+      ltotape_log_snapshot (device, false);
     }
   }
 
@@ -1048,7 +1048,7 @@ int ltotape_load (void *device, struct t
     return read_pos_status;
 #endif   
 
-   status = ltotape_loadunload (device, TRUE, FALSE);  /* TRUE to load, FALSE to load fully (not hold)*/
+   status = ltotape_loadunload (device, true, false);  /* true to load, false to load fully (not hold)*/
 
   ltotape_readposition (device, pos);
 
@@ -1104,7 +1104,7 @@ int ltotape_load (void *device, struct t
  */
 int ltotape_unload(void *device, struct tc_position *pos)
 {
-   int status = ltotape_loadunload (device, FALSE, FALSE);   /* FALSE to unload, FALSE to unload fully (not hold)*/
+   int status = ltotape_loadunload (device, false, false);   /* false to unload, false to unload fully (not hold)*/
    
    ltotape_readposition (device, pos);
    return status;
@@ -1120,8 +1120,8 @@ int ltotape_unload(void *device, struct 
 *  is wise or will succeed is beyond our control here.
 * @param device a pointer to the ltotape backend
 * @param pos a pointer to position data. This function will update position infomation.
-* @param load TRUE if load is required, FALSE if unload
-* @param hold TRUE if cart should be left in hold position, FALSE if full load/unload
+* @param load true if load is required, false if unload
+* @param hold true if cart should be left in hold position, false if full load/unload
 * @return 0 on success or a negative value on error
 */
 int ltotape_ext_loadunload (void *device, struct tc_position *pos, bool load, bool hold)
@@ -1243,7 +1243,7 @@ int ltotape_readposition (void *device, 
 
     } else {
       ltfsmsg (LTFS_ERR, "20066E", status);
-      ltotape_log_snapshot (device, FALSE);
+      ltotape_log_snapshot (device, false);
     }
   }
 
@@ -1348,7 +1348,7 @@ int ltotape_format (void *device, TC_FOR
   /* If it failed, take a log snapshot: */
   if (status == -1) {
     ltfsmsg (LTFS_ERR, "20068E", status);
-    ltotape_log_snapshot (device, FALSE);
+    ltotape_log_snapshot (device, false);
 
   /* But if it passed, set some CM attributes: */
   } else {
@@ -1531,7 +1531,7 @@ int ltotape_modesense (void *device, con
 
   if (status == -1) {
     ltfsmsg (LTFS_ERR, "20072E", status);
-    ltotape_log_snapshot (device, FALSE);
+    ltotape_log_snapshot (device, false);
   }
 
   return status;
@@ -1607,7 +1607,7 @@ int ltotape_modeselect (void *device, un
 
   if (status == -1) {
     ltfsmsg (LTFS_ERR, "20073E", status);
-    ltotape_log_snapshot (device, FALSE);
+    ltotape_log_snapshot (device, false);
   }
 
   return status;
@@ -1745,7 +1745,7 @@ int ltotape_allow_medium_removal (void *
   int status;
   status = ltotape_prevent_allow_medium_removal (device, 0); /* 0 = ALLOW */
 
-  ltotape_log_snapshot (device, TRUE); /* sneak in to grab a log snapshot */
+  ltotape_log_snapshot (device, true); /* sneak in to grab a log snapshot */
 
   return status;
 }
@@ -1916,7 +1916,7 @@ int ltotape_write_attribute (void *devic
 
   if (status == -1) {
      ltfsmsg(LTFS_ERR, "20075E", status);
-     ltotape_log_snapshot (device, FALSE);
+     ltotape_log_snapshot (device, false);
   }
 
   free (pRawData);
@@ -3175,7 +3175,7 @@ int ltotape_get_keyalias (void *device, 
 int ltotape_takedump_drive (void *device)
 {
   // CR10859 - this was stubbed out before...
-  return ltotape_log_snapshot (device, FALSE); // FALSE = not a minidump
+  return ltotape_log_snapshot (device, false); // false = not a minidump
 }
 
 bool ltotape_is_mountable (void *device, const char *barcode, const unsigned char density_code)
