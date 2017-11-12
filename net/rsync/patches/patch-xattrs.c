$NetBSD: patch-xattrs.c,v 1.1.2.2 2017/11/12 12:27:20 spz Exp $

patch for CVE-2017-16548 from
https://git.samba.org/rsync.git/?p=rsync.git;a=blobdiff;f=xattrs.c;h=4867e6f5b8ad2934d43b06f3b99b7b3690a6dc7a;hp=68305d7559b34f5cc2f196b74429b82fa6ff49dd;hb=47a63d90e71d3e19e0e96052bb8c6b9cb140ecc1;hpb=bc112b0e7feece62ce98708092306639a8a53cce

--- xattrs.c.orig	2015-08-08 19:47:03.000000000 +0000
+++ xattrs.c
@@ -696,6 +696,10 @@ void receive_xattr(int f, struct file_st
 			out_of_memory("receive_xattr");
 		name = ptr + dget_len + extra_len;
 		read_buf(f, name, name_len);
+		if (name_len < 1 || name[name_len-1] != '\0') {
+			rprintf(FERROR, "Invalid xattr name received (missing trailing \\0).\n");
+			exit_cleanup(RERR_FILEIO);
+		}
 		if (dget_len == datum_len)
 			read_buf(f, ptr, dget_len);
 		else {
