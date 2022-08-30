$NetBSD: patch-source3_smbd_quotas.c,v 1.1 2022/08/30 17:47:50 jperkin Exp $

Disable NFS quota support, bundled gssapi headers conflict with system.

--- source3/smbd/quotas.c.orig	2022-01-24 10:26:59.245308200 +0000
+++ source3/smbd/quotas.c
@@ -54,6 +54,7 @@
  Alan Romeril <a.romeril@ic.ac.uk> July 2K.
 ****************************************************************************/
 
+#if 0
 #include <rpc/rpc.h>
 #include <rpc/types.h>
 #include <rpcsvc/rquota.h>
@@ -210,6 +211,7 @@ static bool nfs_quotas(char *nfspath, ui
 	DEBUG(10,("nfs_quotas: End of nfs_quotas\n" ));
 	return ret;
 }
+#endif
 
 /****************************************************************************
 try to get the disk space from disk quotas (SunOS & Solaris2 version)
@@ -252,7 +254,9 @@ bool disk_quotas(connection_struct *conn
 		/* quotas are only on vxfs, UFS or NFS */
 		if ((sbuf.st_ex_dev == devno) && (
 			strcmp( mnt.mnt_fstype, MNTTYPE_UFS ) == 0 ||
+#if 0
 			strcmp( mnt.mnt_fstype, "nfs" ) == 0    ||
+#endif
 			strcmp( mnt.mnt_fstype, "vxfs" ) == 0 )) {
 				found = true;
 				name = talloc_asprintf(talloc_tos(),
@@ -272,6 +276,7 @@ bool disk_quotas(connection_struct *conn
 	}
 	become_root();
 
+#if 0
 	if (strcmp(mnt.mnt_fstype, "nfs") == 0) {
 		bool retval;
 		DEBUG(5,("disk_quotas: looking for mountpath (NFS) \"%s\"\n",
@@ -281,6 +286,7 @@ bool disk_quotas(connection_struct *conn
 		unbecome_root();
 		return retval;
 	}
+#endif
 
 	DEBUG(5,("disk_quotas: looking for quotas file \"%s\"\n", name));
 	if((file=open(name, O_RDONLY,0))<0) {
