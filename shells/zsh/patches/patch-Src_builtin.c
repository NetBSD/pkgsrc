$NetBSD: patch-Src_builtin.c,v 1.1 2015/06/13 12:57:28 ryoon Exp $

https://sourceforge.net/p/zsh/code/ci/ac26fafa03c30e8c79e4bd70bdbb68d025643ee7/

--- Src/builtin.c.orig	2015-05-31 15:39:40.000000000 +0000
+++ Src/builtin.c
@@ -4461,7 +4461,7 @@ bin_print(char *name, char **args, Optio
 			lleft -= chars;
 			ptr += chars;
 		    }
-		    if (width > 0 && flags[2]) width = -width;
+		    if (width > 0 && flags[3]) width = -width;
 		    if (width > 0 && lchars < width)
 		    	count += fprintf(fout, "%*c", width - lchars, ' ');
 		    count += fwrite(b, 1, lbytes, fout);
