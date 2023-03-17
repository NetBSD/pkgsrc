$NetBSD: patch-libpkgconf_argvsplit.c,v 1.1 2023/03/17 20:20:45 riastradh Exp $

Fix ctype(3) misuse.
https://github.com/pkgconf/pkgconf/issues/291
https://github.com/pkgconf/pkgconf/pull/292

--- libpkgconf/argvsplit.c.orig	2023-01-21 19:50:40.000000000 +0000
+++ libpkgconf/argvsplit.c
@@ -108,7 +108,7 @@ pkgconf_argv_split(const char *src, int 
 			else
 				*dst_iter++ = *src_iter;
 		}
-		else if (isspace((unsigned int)*src_iter))
+		else if (isspace((unsigned char)*src_iter))
 		{
 			if ((*argv)[argc_count] != NULL)
 			{
