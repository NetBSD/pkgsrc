$NetBSD: patch-colors.c,v 1.2 2016/09/19 09:04:29 wiz Exp $

--- colors.c.orig	2016-01-25 15:38:00.000000000 +0000
+++ colors.c
@@ -215,8 +215,10 @@ _rl_print_color_indicator (const char *f
         colored_filetype = C_LINK;
       else if (S_ISFIFO (mode))
         colored_filetype = C_FIFO;
+#if defined(S_ISSOCK)
       else if (S_ISSOCK (mode))
         colored_filetype = C_SOCK;
+#endif
       else if (S_ISBLK (mode))
         colored_filetype = C_BLK;
       else if (S_ISCHR (mode))
