$NetBSD: patch-arj__user.c,v 1.1 2015/04/12 16:09:27 tnn Exp $

Add patch from Debian (security_format.patch) to fix unsafe format string usage.

--- arj_user.c.orig	2004-06-18 16:19:36.000000000 +0000
+++ arj_user.c
@@ -2303,7 +2303,7 @@ void process_archive()
   timestamp_to_str(timetext, &ftime_stamp);
   msg_cprintf(H_HL|H_NFMT, M_ARCHIVE_CREATED, timetext);
   if(show_ansi_comments)
-   printf(cmt_ptr);
+   fputs(cmt_ptr, stdout);
   else
    display_comment(cmt_ptr);
   /* The sfx_setup() occurs here */
