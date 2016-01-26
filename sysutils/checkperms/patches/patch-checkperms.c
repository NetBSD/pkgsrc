$NetBSD: patch-checkperms.c,v 1.2 2016/01/26 00:13:20 rillig Exp $

Fix build under SCO OpenServer 5.0.7/3.2 It has no S_ISSOCK.

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
