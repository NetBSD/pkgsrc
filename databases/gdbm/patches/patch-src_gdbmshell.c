$NetBSD: patch-src_gdbmshell.c,v 1.1 2021/09/14 13:32:50 schmonz Exp $

Apply upstream patch 32517af7 to check for st_mtim in struct stat.
Fixes macOS build.

--- src/gdbmshell.c.orig	2021-09-02 12:39:55.000000000 +0000
+++ src/gdbmshell.c
@@ -1010,7 +1010,11 @@ print_snapshot (char const *snapname, FI
       fprintf (fp, "%s: ", snapname);
       fprintf (fp, "%03o %s ", st.st_mode & 0777,
 	       decode_mode (st.st_mode, buf));
+#if HAVE_STRUCT_STAT_ST_MTIM
       fprintf (fp, "%ld.%09ld", st.st_mtim.tv_sec, st.st_mtim.tv_nsec);
+#else
+      fprintf (fp, "%ld [%s]", st.st_mtime, _("insufficient precision"));
+#endif
       if (S_ISREG (st.st_mode))
 	{
 	  GDBM_FILE dbf;
