$NetBSD: patch-src_unexmacosx.c,v 1.1 2011/09/15 22:06:38 minskim Exp $

Upstream git commit c8bba48c5889c4773c62a10f7c3d4383881f11c1.

--- src/unexmacosx.c.orig	2011-01-08 17:45:14.000000000 +0000
+++ src/unexmacosx.c
@@ -823,6 +823,7 @@ copy_data_segment (struct load_command *
       else if (strncmp (sectp->sectname, "__la_symbol_ptr", 16) == 0
 	       || strncmp (sectp->sectname, "__nl_symbol_ptr", 16) == 0
 	       || strncmp (sectp->sectname, "__la_sym_ptr2", 16) == 0
+	       || strncmp (sectp->sectname, "__got", 16) == 0
 	       || strncmp (sectp->sectname, "__dyld", 16) == 0
 	       || strncmp (sectp->sectname, "__const", 16) == 0
 	       || strncmp (sectp->sectname, "__cfstring", 16) == 0
