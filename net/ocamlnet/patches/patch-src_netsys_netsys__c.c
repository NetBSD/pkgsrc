$NetBSD: patch-src_netsys_netsys__c.c,v 1.3 2013/01/19 20:37:44 riastradh Exp $

DragonFly doesn't define AT_SYMLINK_FOLLOW.  The added patch will
at least unbreak the build for some code that obviously won't work.
https://sourceforge.net/tracker/?func=detail&aid=3545170&group_id=19774&atid=319774

Also work around absence of AT_REMOVEDIR, as on NetBSD 6.0.

--- src/netsys/netsys_c.c.orig	2012-07-19 23:25:25.000000000 +0000
+++ src/netsys/netsys_c.c
@@ -428,6 +428,10 @@ CAMLprim value netsys_at_fdcwd(value dum
 #define AT_SYMLINK_NOFOLLOW 0
 #endif
 
+#ifndef AT_REMOVEDIR
+#define AT_REMOVEDIR 0
+#endif
+
 static int at_flags_table[] = {
     AT_EACCESS, AT_SYMLINK_NOFOLLOW, AT_REMOVEDIR
 };
@@ -528,7 +532,7 @@ CAMLprim value netsys_renameat(value old
 CAMLprim value netsys_linkat(value olddirfd, value oldpath,
 			     value newdirfd, value newpath, value flags)
 {
-#ifdef HAVE_AT
+#if defined(HAVE_AT) && defined(AT_SYMLINK_FOLLOW)
     int cv_flags;
     cv_flags = convert_flag_list(flags, at_flags_table);
     cv_flags &= AT_SYMLINK_FOLLOW;  /* only allowed flag here */
