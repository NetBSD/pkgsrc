$NetBSD: patch-gcc_cp_except.c,v 1.1 2018/06/27 10:07:08 maya Exp $

Backport upstream commit to fix build with newer GCC

 2016-02-19 Jakub Jelinek <jakub@redhat.com>

            Bernd Edlinger  <bernd.edlinger@hotmail.de>

        * Make-lang.in: Invoke gperf with -L C++.
        * cfns.gperf: Remove prototypes for hash and libc_name_p
        inlines.
        * cfns.h: Regenerated.
        * except.c (nothrow_libfn_p): Adjust.

--- gcc/cp/except.c.orig	2013-10-25 13:49:48.000000000 +0000
+++ gcc/cp/except.c
@@ -1025,7 +1025,8 @@ nothrow_libfn_p (const_tree fn)
      unless the system headers are playing rename tricks, and if
      they are, we don't want to be confused by them.  */
   id = DECL_NAME (fn);
-  return !!libc_name_p (IDENTIFIER_POINTER (id), IDENTIFIER_LENGTH (id));
+  return !!libc_name::libc_name_p (IDENTIFIER_POINTER (id),
+				   IDENTIFIER_LENGTH (id));
 }
 
 /* Returns nonzero if an exception of type FROM will be caught by a
