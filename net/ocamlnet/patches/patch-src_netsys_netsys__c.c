$NetBSD: patch-src_netsys_netsys__c.c,v 1.6 2016/02/03 13:19:33 jaapb Exp $

Work around absence of AT_REMOVEDIR, as on NetBSD 6.0.
--- src/netsys/netsys_c.c.orig	2015-06-21 15:26:42.000000000 +0000
+++ src/netsys/netsys_c.c
@@ -432,6 +432,10 @@ CAMLprim value netsys_at_fdcwd(value dum
 #define AT_SYMLINK_FOLLOW 0
 #endif
 
+#ifndef AT_REMOVEDIR
+#define AT_REMOVEDIR 0
+#endif
+
 static int at_flags_table[] = {
     AT_EACCESS, AT_SYMLINK_NOFOLLOW, AT_SYMLINK_FOLLOW, AT_REMOVEDIR
 };
@@ -549,7 +553,7 @@ CAMLprim value netsys_renameat(value old
 CAMLprim value netsys_linkat(value olddirfd, value oldpath,
 			     value newdirfd, value newpath, value flags)
 {
-#ifdef HAVE_AT
+#if defined(HAVE_AT) && defined(AT_SYMLINK_FOLLOW)
     int cv_flags;
     cv_flags = convert_flag_list(flags, at_flags_table);
     cv_flags &= AT_SYMLINK_FOLLOW;  /* only allowed flag here */
