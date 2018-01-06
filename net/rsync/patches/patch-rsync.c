$NetBSD: patch-rsync.c,v 1.1.2.2 2018/01/06 22:51:51 spz Exp $

Fix for CVE-2017-17434, taken from:

https://git.samba.org/?p=rsync.git;a=commitdiff;h=70aeb5fddd1b2f8e143276f8d5a085db16c593b9

--- rsync.c.orig	2015-08-08 12:47:03.000000000 -0700
+++ rsync.c	2017-12-31 12:40:50.353165397 -0800
@@ -49,6 +49,7 @@ extern int flist_eof;
 extern int file_old_total;
 extern int keep_dirlinks;
 extern int make_backups;
+extern int sanitize_paths;
 extern struct file_list *cur_flist, *first_flist, *dir_flist;
 extern struct chmod_mode_struct *daemon_chmod_modes;
 #ifdef ICONV_OPTION
@@ -396,6 +397,11 @@ int read_ndx_and_attrs(int f_in, int f_o
 	if (iflags & ITEM_XNAME_FOLLOWS) {
 		if ((len = read_vstring(f_in, buf, MAXPATHLEN)) < 0)
 			exit_cleanup(RERR_PROTOCOL);
+
+		if (sanitize_paths) {
+			sanitize_path(buf, buf, "", 0, SP_DEFAULT);
+			len = strlen(buf);
+		}
 	} else {
 		*buf = '\0';
 		len = -1;
