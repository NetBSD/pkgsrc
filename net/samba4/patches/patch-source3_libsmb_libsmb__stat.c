$NetBSD: patch-source3_libsmb_libsmb__stat.c,v 1.1 2020/11/12 06:37:18 adam Exp $

Compatibility fix.

--- source3/libsmb/libsmb_stat.c.orig	2020-11-11 15:02:40.000000000 +0000
+++ source3/libsmb/libsmb_stat.c
@@ -102,18 +102,30 @@ void setup_stat(struct stat *st,
 	}
 
 	st->st_dev = dev;
+#if defined(__APPLE__) || defined(__NetBSD__)
+	st->st_atimespec = access_time_ts;
+	st->st_ctimespec = change_time_ts;
+	st->st_mtimespec = write_time_ts;
+#else
 	st->st_atim = access_time_ts;
 	st->st_ctim = change_time_ts;
 	st->st_mtim = write_time_ts;
+#endif
 }
 
 void setup_stat_from_stat_ex(const struct stat_ex *stex,
 			     const char *fname,
 			     struct stat *st)
 {
+#if defined(__APPLE__) || defined(__NetBSD__)
+	st->st_atimespec = stex->st_ex_atime;
+	st->st_ctimespec = stex->st_ex_ctime;
+	st->st_mtimespec = stex->st_ex_mtime;
+#else
 	st->st_atim = stex->st_ex_atime;
 	st->st_ctim = stex->st_ex_ctime;
 	st->st_mtim = stex->st_ex_mtime;
+#endif
 
 	st->st_mode = stex->st_ex_mode;
 	st->st_size = stex->st_ex_size;
