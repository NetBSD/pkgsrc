$NetBSD: patch-src_netsys_netsys__c.c,v 1.1 2012/07/17 17:45:23 marino Exp $

--- src/netsys/netsys_c.c.orig	2012-02-29 18:02:52.000000000 +0000
+++ src/netsys/netsys_c.c
@@ -528,7 +528,7 @@ CAMLprim value netsys_renameat(value old
 CAMLprim value netsys_linkat(value olddirfd, value oldpath,
 			     value newdirfd, value newpath, value flags)
 {
-#ifdef HAVE_AT
+#if defined(HAVE_AT) && defined(AT_SYMLINK_FOLLOW)
     int cv_flags;
     cv_flags = convert_flag_list(flags, at_flags_table);
     cv_flags &= AT_SYMLINK_FOLLOW;  /* only allowed flag here */
