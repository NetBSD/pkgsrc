$NetBSD: patch-source3_modules_vfs__solarisacl.c,v 1.1 2022/04/25 16:25:02 jperkin Exp $

https://bugzilla.samba.org/attachment.cgi?id=16710

--- source3/modules/vfs_solarisacl.c.orig	2021-08-09 13:38:36.435381200 +0000
+++ source3/modules/vfs_solarisacl.c
@@ -204,7 +204,7 @@ int solarisacl_sys_acl_set_fd(vfs_handle
 	DEBUG(10, ("solarisacl_sys_acl_set_fd %s.\n",
 		   ((ret == 0) ? "succeeded" : "failed" )));
 	SAFE_FREE(solaris_acl);
-	SAFE_FREE(default_acl);
+	SAFE_FREE(other_acl);
 	return ret;
 }
 
@@ -252,7 +252,7 @@ int solarisacl_sys_acl_delete_def_fd(vfs
 	}
 	ret = acl(fsp->fsp_name->base_name, SETACL, count, solaris_acl);
 	if (ret != 0) {
-		DBG_DEBG("settinge file acl failed!\n");
+		DBG_DEBUG("settinge file acl failed!\n");
 	}
 
  done:
