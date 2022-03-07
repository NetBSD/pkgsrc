$NetBSD: patch-source3_smbd_open.c,v 1.1 2022/03/07 21:40:38 thor Exp $

--- source3/smbd/open.c.orig	2022-01-27 18:20:00.791110968 +0000
+++ source3/smbd/open.c
@@ -1189,11 +1189,13 @@ static NTSTATUS reopen_from_procfd(struc
 
 	fsp->fsp_flags.is_pathref = false;
 
+	/* O_CREAT not useful for reopening, and it upsets BSD kernels,
+	 * see https://bugzilla.samba.org/show_bug.cgi?id=14727 . */
 	new_fd = SMB_VFS_OPENAT(fsp->conn,
 				fsp->conn->cwd_fsp,
 				&proc_fname,
 				fsp,
-				flags,
+				flags & ~O_CREAT,
 				mode);
 	if (new_fd == -1) {
 		status = map_nt_error_from_unix(errno);
