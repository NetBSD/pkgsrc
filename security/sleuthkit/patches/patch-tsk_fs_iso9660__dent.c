$NetBSD: patch-tsk_fs_iso9660__dent.c,v 1.1 2018/08/23 07:47:34 he Exp $

--- tsk/fs/iso9660_dent.c.orig	2014-01-27 03:27:03.000000000 +0000
+++ tsk/fs/iso9660_dent.c
@@ -98,6 +98,12 @@ iso9660_proc_dir(TSK_FS_INFO * a_fs, TSK
     iso9660_inode_node *in;
     TSK_OFF_T dir_offs = a_dir_addr * a_fs->block_size;
 
+    // had an issue once where dir was too small
+    // manu later calculations assume we can fit at least one entry
+    if (a_length < sizeof(iso9660_dentry)) {
+	return TSK_OK;
+    }
+
     if ((fs_name = tsk_fs_name_alloc(ISO9660_MAXNAMLEN + 1, 0)) == NULL)
         return TSK_ERR;
 
