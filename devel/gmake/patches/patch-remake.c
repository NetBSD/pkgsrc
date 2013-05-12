$NetBSD: patch-remake.c,v 1.1 2013/05/12 05:47:24 richard Exp $

upstream: http://git.savannah.gnu.org/cgit/make.git/commit/?id=fbe5b2c9cd612b962836b9391fa2b58c8baed6fc
Force intermediate targets to be considered if their non-intermediate

--- remake.c.orig	2010-07-13 01:20:42.000000000 +0000
+++ remake.c
@@ -614,6 +614,10 @@ update_file_1 (struct file *file, unsign
                 d->file->dontcare = file->dontcare;
               }
 
+	    /* We may have already considered this file, when we didn't know
+	       we'd need to update it. Force update_file() to consider it and
+	       not prune it. */
+	    d->file->considered = !considered;
 
 	    dep_status |= update_file (d->file, depth);
 
