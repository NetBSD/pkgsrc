$NetBSD: patch-checkperms.c,v 1.1 2014/03/14 22:30:36 ryoon Exp $

--- checkperms.c.orig	2009-12-05 09:56:11.000000000 +0000
+++ checkperms.c
@@ -420,8 +420,10 @@ check_perms(const char *fname)
 			    fname, (unsigned int)unfixed, m);
 		}
 
+#if defined(S_ISLNK) && defined(S_ISSOCK)
 	} else if (S_ISLNK(st.st_mode) || S_ISSOCK(st.st_mode)) {
 		/* Fine. */
+#endif
 
 	} else if (S_ISCHR(st.st_mode) || S_ISBLK(st.st_mode)) {
 		/* Fine. */
