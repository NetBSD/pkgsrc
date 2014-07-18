$NetBSD: patch-colors.c,v 1.1 2014/07/18 13:02:06 ryoon Exp $

--- colors.c.orig	2013-03-20 15:19:08.000000000 +0000
+++ colors.c
@@ -187,8 +187,10 @@ _rl_print_color_indicator (char *f)
                 ? C_ORPHAN : C_LINK);
       else if (S_ISFIFO (mode))
         colored_filetype = C_FIFO;
+#if defined(S_ISSOCK)
       else if (S_ISSOCK (mode))
         colored_filetype = C_SOCK;
+#endif
       else if (S_ISBLK (mode))
         colored_filetype = C_BLK;
       else if (S_ISCHR (mode))
