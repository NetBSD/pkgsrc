$NetBSD: patch-libguile_filesys.c,v 1.4 2017/03/08 14:38:34 jperkin Exp $

Pull in upstream patch to fix mkostemp flags.

--- libguile/filesys.c.orig	2016-12-15 00:03:33.000000000 +0000
+++ libguile/filesys.c
@@ -1483,6 +1483,12 @@ SCM_DEFINE (scm_i_mkstemp, "mkstemp!", 1
   else
     {
       open_flags = scm_i_mode_to_open_flags (mode, &is_binary, FUNC_NAME);
+      /* mkostemp(2) only defines O_APPEND, O_SYNC, and O_CLOEXEC to be
+         useful, as O_RDWR|O_CREAT|O_EXCL are implicitly added.  It also
+         notes that other flags may error on some systems, which turns
+         out to be the case.  Of those flags, O_APPEND is the only one
+         of interest anyway, so limit to that flag.  */
+      open_flags &= O_APPEND;
       mode_bits = scm_i_mode_bits (mode);
     }
 
