$NetBSD: patch-libmy_argv.c,v 1.1 2019/12/16 12:52:23 he Exp $

Include space for the terminating 0 character.

--- libmy/argv.c.orig	2019-10-14 16:25:11.000000000 +0000
+++ libmy/argv.c
@@ -482,7 +482,7 @@ static	int	expand_buf(const void *buf, c
       if (out_p + 2 >= max_p) {
 	break;
       }
-      LOC_SNPRINTF(SNP_ARG(out_p, 2), "\\%c", *(spec_p - 1));
+      LOC_SNPRINTF(SNP_ARG(out_p, 3), "\\%c", *(spec_p - 1));
       out_p += 2;
       continue;
     }
@@ -499,7 +499,7 @@ static	int	expand_buf(const void *buf, c
       if (out_p + 4 >= max_p) {
 	break;
       }
-      LOC_SNPRINTF(SNP_ARG(out_p, 4), "\\%03o", *buf_p);
+      LOC_SNPRINTF(SNP_ARG(out_p, 5), "\\%03o", *buf_p);
       out_p += 4;
     }
   }
