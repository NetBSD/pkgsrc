$NetBSD: patch-binutils_objcopy.c,v 1.1 2021/02/11 09:26:51 fcambus Exp $

Unbreak the build on at least NetBSD.

Cherry-picked from upstream commit 95b91a043aeaeb546d2fea556d84a2de1e917770.

--- binutils/objcopy.c.orig	2021-02-10 08:48:37.130505053 +0000
+++ binutils/objcopy.c
@@ -3769,7 +3767,7 @@ copy_file (const char *input_filename, c
   /* To allow us to do "strip *" without dying on the first
      non-object file, failures are nonfatal.  */
   ibfd = bfd_openr (input_filename, input_target);
-  if (ibfd == NULL || fstat (fileno (ibfd->iostream), in_stat) != 0)
+  if (ibfd == NULL || bfd_stat (ibfd, in_stat) != 0)
     {
       bfd_nonfatal_message (input_filename, NULL, NULL, NULL);
       status = 1;
