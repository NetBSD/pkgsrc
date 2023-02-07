$NetBSD: patch-etc_afpd_volume.c,v 1.1 2023/02/07 23:00:40 hauke Exp $

Unlink temp file after using it to check for EA support. 
Fixes GitHub issue #188

Patch from upstream

--- etc/afpd/volume.c.orig	2022-07-12 04:08:24.000000000 +0000
+++ etc/afpd/volume.c
@@ -2217,6 +2217,7 @@ static void check_ea_sys_support(struct 
     uid_t process_uid = 0;
     char eaname[] = {"org.netatalk.supports-eas.XXXXXX"};
     const char *eacontent = "yes";
+    int fd;
 
     if (vol->v_vfs_ea == AFPVOL_EA_AUTO) {
 
@@ -2226,7 +2227,6 @@ static void check_ea_sys_support(struct 
             return;
         }
 
-        int fd;
         fd = mkstemp(eaname);
         close(fd);
 
@@ -2234,6 +2234,7 @@ static void check_ea_sys_support(struct 
         if (process_uid)
             if (seteuid(0) == -1) {
                 LOG(log_error, logtype_afpd, "check_ea_sys_support: can't seteuid(0): %s", strerror(errno));
+                unlink(eaname);
                 exit(EXITERR_SYS);
             }
 
@@ -2249,9 +2250,12 @@ static void check_ea_sys_support(struct 
         if (process_uid) {
             if (seteuid(process_uid) == -1) {
                 LOG(log_error, logtype_afpd, "can't seteuid back %s", strerror(errno));
+                unlink(eaname);
                 exit(EXITERR_SYS);
             }
         }
+
+        unlink(eaname);
     }
 }
 
