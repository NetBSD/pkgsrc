$NetBSD: patch-receiver.c,v 1.1.2.2 2018/01/06 22:51:51 spz Exp $

Fix for CVE-2017-17433, taken from:

https://git.samba.org/?p=rsync.git;a=commitdiff;h=3e06d40029cfdce9d0f73d87cfd4edaf54be9c51

Fix for CVE-2017-17434, taken from:

https://git.samba.org/?p=rsync.git;a=commitdiff;h=5509597decdbd7b91994210f700329d8a35e70a1

--- receiver.c.orig	2015-09-07 10:07:17.000000000 -0700
+++ receiver.c	2017-12-31 12:46:27.078487190 -0800
@@ -580,6 +580,12 @@ int recv_files(int f_in, int f_out, char
 			file = dir_flist->files[cur_flist->parent_ndx];
 		fname = local_name ? local_name : f_name(file, fbuf);
 
+		if (daemon_filter_list.head
+		    && check_filter(&daemon_filter_list, FLOG, fname, 0) < 0) {
+			rprintf(FERROR, "attempt to hack rsync failed.\n");
+			exit_cleanup(RERR_PROTOCOL);
+		}
+
 		if (DEBUG_GTE(RECV, 1))
 			rprintf(FINFO, "recv_files(%s)\n", fname);
 
@@ -651,12 +657,6 @@ int recv_files(int f_in, int f_out, char
 
 		cleanup_got_literal = 0;
 
-		if (daemon_filter_list.head
-		    && check_filter(&daemon_filter_list, FLOG, fname, 0) < 0) {
-			rprintf(FERROR, "attempt to hack rsync failed.\n");
-			exit_cleanup(RERR_PROTOCOL);
-		}
-
 		if (read_batch) {
 			int wanted = redoing
 				   ? we_want_redo(ndx)
@@ -728,7 +728,7 @@ int recv_files(int f_in, int f_out, char
 				break;
 			}
 			if (!fnamecmp || (daemon_filter_list.head
-			  && check_filter(&daemon_filter_list, FLOG, fname, 0) < 0)) {
+			  && check_filter(&daemon_filter_list, FLOG, fnamecmp, 0) < 0)) {
 				fnamecmp = fname;
 				fnamecmp_type = FNAMECMP_FNAME;
 			}
