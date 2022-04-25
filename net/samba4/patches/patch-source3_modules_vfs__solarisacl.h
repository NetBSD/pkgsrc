$NetBSD: patch-source3_modules_vfs__solarisacl.h,v 1.1 2022/04/25 16:25:02 jperkin Exp $

Fix function prototype to match.

--- source3/modules/vfs_solarisacl.h.orig	2022-03-15 13:19:34.136201100 +0000
+++ source3/modules/vfs_solarisacl.h
@@ -20,7 +20,7 @@
 #ifndef __VFS_SOLARISACL_H__
 #define __VFS_SOLARISACL_H__
 
-SMB_ACL_T solarisacl_sys_acl_get_file(vfs_handle_struct *handle,
+static SMB_ACL_T solarisacl_sys_acl_get_file(vfs_handle_struct *handle,
 				const struct smb_filename *smb_fname,
 				SMB_ACL_TYPE_T type,
 				TALLOC_CTX *mem_ctx);
