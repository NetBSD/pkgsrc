$NetBSD: patch-panel-plugin_devices.c,v 1.1 2015/04/21 08:56:40 jperkin Exp $

Fix NetBSD build.
Add SunOS support.
--- panel-plugin/devices.c.orig	2014-04-26 21:31:42.000000000 +0000
+++ panel-plugin/devices.c
@@ -25,7 +25,12 @@ Foundation, Inc., 675 Mass Ave, Cambridg
 #include <config.h>
 #endif
 
+#ifdef __sun
+#include <stdio.h>
+#include <sys/vfstab.h>
+#else
 #include <fstab.h>
+#endif
 #include <glib.h>
 #include <stdio.h>
 #include <string.h>
@@ -33,7 +38,12 @@ Foundation, Inc., 675 Mass Ave, Cambridg
 #include <sys/types.h>
 #include <sys/wait.h>
 #ifdef HAVE_GETMNTENT
+#ifdef __sun
+#include <sys/mntent.h>
+#include <sys/mnttab.h>
+#else
 #include <mntent.h>
+#endif
 #include <sys/vfs.h>
 #elif defined (HAVE_GETMNTINFO)
 #include <sys/param.h>
@@ -42,6 +52,10 @@ Foundation, Inc., 675 Mass Ave, Cambridg
 #error no getmntent/getmntinfo ? send patches !
 #endif
 
+#if defined(__NetBSD__) || defined(__sun)
+#define statfs statvfs
+#endif
+
 #include <libxfce4panel/xfce-panel-plugin.h>
 #include <libxfce4util/libxfce4util.h>
 #include <libxfce4ui/libxfce4ui.h>
@@ -57,7 +71,6 @@ t_mount_info * mount_info_new_from_stat
 
 #define MTAB "/etc/mtab"
 
-
 /**
  * Return a string containing a size expressed in KB, MB or GB and the unit
  * it is expressed in.
@@ -427,7 +440,15 @@ disks_new (gboolean include_NFSs, gboole
 {
     GPtrArray * pdisks; /* to be returned */
     t_disk * pdisk;
+#ifdef __sun
+    struct vfstab *pfstab;
+    FILE *fd = NULL;
+    fd = fopen(VFSTAB, "r");
+    if (fd == NULL)
+	    return NULL;
+#else
     struct fstab *pfstab;
+#endif
     gboolean has_valid_mount_device;
     GtkWidget *dialog;
 
@@ -452,23 +473,46 @@ disks_new (gboolean include_NFSs, gboole
     }
 
 
+#ifdef __sun
+    for (getvfsent(fd, pfstab); pfstab!=NULL; getvfsent(fd, pfstab))
+#else
     for (pfstab = getfsent(); pfstab!=NULL; pfstab = getfsent())
+#endif
     {
         has_valid_mount_device =
+#ifdef __sun
+                        g_str_has_prefix(pfstab->vfs_special, "/dev/") ||  g_str_has_prefix(pfstab->vfs_special, "UUID=") ||  g_str_has_prefix(pfstab->vfs_special, "LABEL=");
+#else
                         g_str_has_prefix(pfstab->fs_spec, "/dev/") ||  g_str_has_prefix(pfstab->fs_spec, "UUID=") ||  g_str_has_prefix(pfstab->fs_spec, "LABEL=");
+#endif
 
         if (include_NFSs)
             has_valid_mount_device = has_valid_mount_device |
+#ifdef __sun
+                g_str_has_prefix(pfstab->vfs_fstype, "fuse") |
+                g_str_has_prefix(pfstab->vfs_fstype, "shfs") |
+                g_str_has_prefix(pfstab->vfs_fstype, "nfs") |
+                g_str_has_prefix(pfstab->vfs_fstype, "cifs") |
+                g_str_has_prefix(pfstab->vfs_fstype, "smbfs");
+#else
                 g_str_has_prefix(pfstab->fs_vfstype, "fuse") |
                 g_str_has_prefix(pfstab->fs_vfstype, "shfs") |
                 g_str_has_prefix(pfstab->fs_vfstype, "nfs") |
                 g_str_has_prefix(pfstab->fs_vfstype, "cifs") |
                 g_str_has_prefix(pfstab->fs_vfstype, "smbfs");
+#endif
 
+#ifdef __sun
+        if ( has_valid_mount_device &&
+                g_str_has_prefix(pfstab->vfs_mountp, "/") ) {
+            pdisk = disk_new (pfstab->vfs_special, pfstab->vfs_mountp, length);
+            pdisk->dc = disk_classify (pfstab->vfs_special, pfstab->vfs_mountp);
+#else
         if ( has_valid_mount_device &&
                 g_str_has_prefix(pfstab->fs_file, "/") ) {
             pdisk = disk_new (pfstab->fs_spec, pfstab->fs_file, length);
             pdisk->dc = disk_classify (pfstab->fs_spec, pfstab->fs_file);
+#endif
             if (!device_or_mountpoint_exists(pdisks, pdisk))
               g_ptr_array_add (pdisks , pdisk);
 
@@ -476,6 +520,9 @@ disks_new (gboolean include_NFSs, gboole
 
     } /* end for */
 
+#ifdef __sun
+    fclose(fd);
+#endif
     endfsent(); /* close file */
 
     return pdisks;
@@ -697,7 +744,11 @@ disks_refresh(GPtrArray * pdisks, GPtrAr
 
 #ifdef HAVE_GETMNTENT
     FILE * fmtab = NULL; /* file /etc/mtab */
+#ifdef __sun
+    struct mnttab * pmntent = NULL;
+#else
     struct mntent * pmntent = NULL; /* struct for mnt info */
+#endif
 #elif defined (HAVE_GETMNTINFO)
     int i, nb_mounted_fs = 0;
 #endif
@@ -717,7 +768,13 @@ disks_refresh(GPtrArray * pdisks, GPtrAr
     pstatfs = g_new0 (struct statfs, 1);
 
     /* open file */
+#ifdef __sun
+    fmtab = fopen(MTAB, "r");
+    if (fmtab == NULL)
+	    return;
+#else
     fmtab = setmntent (MTAB, "r"); /* mtab file */
+#endif
 #elif defined (HAVE_GETMNTINFO)
     /* get mounted fs */
     nb_mounted_fs = getmntinfo(&pstatfs,MNT_WAIT);
@@ -725,11 +782,19 @@ disks_refresh(GPtrArray * pdisks, GPtrAr
 
     /* start looking for mounted devices */
 #ifdef HAVE_GETMNTENT
+#ifdef __sun
+    for (getmntent(fmtab, pmntent); pmntent!=NULL; getmntent(fmtab, pmntent)) {
+#else
     for (pmntent=getmntent(fmtab); pmntent!=NULL; pmntent=getmntent(fmtab)) {
+#endif
 
         DBG (" have entry: %s on %s", pmntent->mnt_fsname, pmntent->mnt_dir );
 
+#ifdef __sun
+        statfs (pmntent->mnt_mountp, pstatfs);
+#else
         statfs (pmntent->mnt_dir, pstatfs);
+#endif
 #elif defined (HAVE_GETMNTINFO)
     for (i = 0; i < nb_mounted_fs ; i++) {
         DBG (" have entry: %s on %s : type %s", pstatfs[i].f_mntfromname, pstatfs[i].f_mntonname, pstatfs[i].f_fstypename );
@@ -740,13 +805,21 @@ disks_refresh(GPtrArray * pdisks, GPtrAr
         /* get pointer on disk from pdisks */
         /* CHANGED to reflect change in disk_search */
 #ifdef HAVE_GETMNTENT
+#ifdef __sun
+        pdisk = disks_search (pdisks, pmntent->mnt_mountp);
+#else
         pdisk = disks_search (pdisks, pmntent->mnt_dir);
+#endif
 #elif defined (HAVE_GETMNTINFO)
         pdisk = disks_search (pdisks, pstatfs[i].f_mntonname);
 #endif
         if (excluded_FSs!=NULL)
 #ifdef HAVE_GETMNTENT
+#ifdef __sun
+            exclude = exclude_filesystem (excluded_FSs, pmntent->mnt_mountp, pmntent->mnt_special);
+#else
             exclude = exclude_filesystem (excluded_FSs, pmntent->mnt_dir, pmntent->mnt_fsname);
+#endif
 #elif defined (HAVE_GETMNTINFO)
             exclude = exclude_filesystem (excluded_FSs, pstatfs[i].f_mntonname, pstatfs[i].f_mntfromname);
 #endif
@@ -757,6 +830,18 @@ disks_refresh(GPtrArray * pdisks, GPtrAr
             /* test for mnt_dir==none or neither block device nor NFS or system device */
             if ( exclude ||
 #ifdef HAVE_GETMNTENT
+#ifdef __sun
+              g_ascii_strcasecmp(pmntent->mnt_mountp, "none") == 0 ||
+              g_str_has_prefix(pmntent->mnt_special, "gvfs-fuse-daemon") ||
+              !(g_str_has_prefix(pmntent->mnt_special, "/dev/") ||
+                g_str_has_prefix(pmntent->mnt_fstype, "fuse") ||
+                g_str_has_prefix(pmntent->mnt_fstype, "nfs") ||
+                g_str_has_prefix(pmntent->mnt_fstype, "smbfs") ||
+                g_str_has_prefix(pmntent->mnt_fstype, "cifs") ||
+                g_str_has_prefix(pmntent->mnt_fstype, "shfs") 
+              ) ||
+              g_str_has_prefix(pmntent->mnt_mountp, "/sys/")
+#else
               g_ascii_strcasecmp(pmntent->mnt_dir, "none") == 0 ||
               g_str_has_prefix(pmntent->mnt_fsname, "gvfs-fuse-daemon") ||
               !(g_str_has_prefix(pmntent->mnt_fsname, "/dev/") ||
@@ -767,6 +852,7 @@ disks_refresh(GPtrArray * pdisks, GPtrAr
                 g_str_has_prefix(pmntent->mnt_type, "shfs") 
               ) ||
               g_str_has_prefix(pmntent->mnt_dir, "/sys/")
+#endif
 #elif defined (HAVE_GETMNTINFO)
               /* TODO: add support for more fs types on BSD */
               g_ascii_strcasecmp(pstatfs[i].f_mntonname, "none") == 0 ||
@@ -779,8 +865,13 @@ disks_refresh(GPtrArray * pdisks, GPtrAr
 
             /* else have valid entry reflecting block device or NFS */
 #ifdef HAVE_GETMNTENT
+#ifdef __sun
+            pdisk = disk_new (pmntent->mnt_special, pmntent->mnt_mountp, length);
+            pdisk->dc = disk_classify (pmntent->mnt_special, pmntent->mnt_mountp);
+#else
             pdisk = disk_new (pmntent->mnt_fsname, pmntent->mnt_dir, length);
             pdisk->dc = disk_classify (pmntent->mnt_fsname, pmntent->mnt_dir);
+#endif
 #elif defined (HAVE_GETMNTINFO)
             pdisk = disk_new (pstatfs[i].f_mntfromname, pstatfs[i].f_mntonname, length);
             pdisk->dc = disk_classify (pstatfs[i].f_mntfromname, pstatfs[i].f_mntonname);
@@ -790,8 +881,13 @@ disks_refresh(GPtrArray * pdisks, GPtrAr
 
         /* create new t_mount_info */
 #ifdef HAVE_GETMNTENT
+#ifdef __sun
+        mount_info = mount_info_new_from_stat (pstatfs, pmntent->mnt_fstype,
+                                               pmntent->mnt_mountp);
+#else
         mount_info = mount_info_new_from_stat (pstatfs, pmntent->mnt_type,
                                                pmntent->mnt_dir);
+#endif
 #elif defined (HAVE_GETMNTINFO)
         mount_info = mount_info_new_from_stat (&pstatfs[i], pstatfs[i].f_fstypename,
                                                pstatfs[i].f_mntonname);
@@ -847,7 +943,11 @@ disk_check_mounted (const char *disk)
 {
 #ifdef HAVE_GETMNTENT
     FILE *fmtab = NULL; /* file /etc/mtab */
+#ifdef __sun
+    struct mnttab *pmntent = NULL;
+#else
     struct mntent *pmntent = NULL; /* struct for mnt info */
+#endif
 #elif defined (HAVE_GETMNTINFO)
     struct statfs * pstatfs = NULL;
     int i, nb_mounted_fs = 0;
@@ -856,7 +956,13 @@ disk_check_mounted (const char *disk)
 
 #ifdef HAVE_GETMNTENT
     /* open file */
+#ifdef __sun
+    fmtab = fopen(MTAB, "r");
+    if (fmtab == NULL)
+	    return;
+#else
     fmtab = setmntent (MTAB, "r"); /* mtab file */
+#endif
 #elif defined (HAVE_GETMNTINFO)
     /* get mounted fs */
     nb_mounted_fs = getmntinfo(&pstatfs,MNT_WAIT);
@@ -864,14 +970,23 @@ disk_check_mounted (const char *disk)
 
     /* start looking for mounted devices */
 #ifdef HAVE_GETMNTENT
+#ifdef __sun
+    for (getmntent(fmtab, pmntent); pmntent!=NULL; getmntent(fmtab, pmntent))
+#else
     for (pmntent=getmntent(fmtab); pmntent!=NULL; pmntent=getmntent(fmtab))
+#endif
 #elif defined (HAVE_GETMNTINFO)
     for (i = 0; i < nb_mounted_fs ; i++)
 #endif
     {
 #ifdef HAVE_GETMNTENT
+#ifdef __sun
+        if (strcmp(pmntent->mnt_mountp, disk)==0 ||
+            strcmp(pmntent->mnt_special, disk)==0 )
+#else
         if (strcmp(pmntent->mnt_dir, disk)==0 ||
             strcmp(pmntent->mnt_fsname, disk)==0 )
+#endif
 #elif defined (HAVE_GETMNTINFO)
         if (strcmp(pstatfs[i].f_mntonname, disk)==0 ||
             strcmp(pstatfs[i].f_mntfromname, disk)==0 )
