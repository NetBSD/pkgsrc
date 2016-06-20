$NetBSD: patch-libs_ardour_session__state.cc,v 1.1 2016/06/20 08:17:43 kamil Exp $

Detect free space on NetBSD.

--- libs/ardour/session_state.cc.orig	2016-02-19 01:28:56.000000000 +0000
+++ libs/ardour/session_state.cc
@@ -2180,7 +2180,7 @@ Session::save_template (string template_
 void
 Session::refresh_disk_space ()
 {
-#if __APPLE__ || (HAVE_SYS_VFS_H && HAVE_SYS_STATVFS_H)
+#if __APPLE__ || (HAVE_SYS_VFS_H && HAVE_SYS_STATVFS_H) || defined(__NetBSD__)
 
 	Glib::Threads::Mutex::Lock lm (space_lock);
 
@@ -2190,10 +2190,15 @@ Session::refresh_disk_space ()
 	_total_free_4k_blocks_uncertain = false;
 
 	for (vector<space_and_path>::iterator i = session_dirs.begin(); i != session_dirs.end(); ++i) {
+#if defined(__NetBSD__)
+		struct statvfs statfsbuf;
 
+		statvfs (i->path.c_str(), &statfsbuf);
+#else
 		struct statfs statfsbuf;
-		statfs (i->path.c_str(), &statfsbuf);
 
+		statfs (i->path.c_str(), &statfsbuf);
+#endif
 		double const scale = statfsbuf.f_bsize / 4096.0;
 
 		/* See if this filesystem is read-only */
