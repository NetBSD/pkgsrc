$NetBSD: patch-source3_modules_vfs__solarisacl.c,v 1.2 2022/07/21 09:35:19 adam Exp $

https://bugzilla.samba.org/attachment.cgi?id=16710

--- source3/modules/vfs_solarisacl.c.orig	2021-08-09 13:38:36.435381200 +0000
+++ source3/modules/vfs_solarisacl.c
@@ -252,7 +252,7 @@ int solarisacl_sys_acl_delete_def_fd(vfs
 	}
 	ret = acl(fsp->fsp_name->base_name, SETACL, count, solaris_acl);
 	if (ret != 0) {
-		DBG_DEBG("settinge file acl failed!\n");
+		DBG_DEBUG("settinge file acl failed!\n");
 	}
 
  done:
