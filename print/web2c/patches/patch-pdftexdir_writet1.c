$NetBSD: patch-pdftexdir_writet1.c,v 1.1 2018/11/01 11:02:34 markd Exp $

writet1 protection against buffer overflow

git-svn-id: svn://tug.org/texlive/trunk/Build/source@48697 c570f23f-e606-0410-a88d-b1316a301751

--- pdftexdir/writet1.c.orig	2016-11-25 18:24:37.000000000 +0000
+++ pdftexdir/writet1.c
@@ -1598,7 +1598,9 @@ static void t1_check_unusual_charstring(
         *(strend(t1_buf_array) - 1) = ' ';
 
         t1_getline();
+	alloc_array(t1_buf, strlen(t1_line_array) + strlen(t1_buf_array) + 1, T1_BUF_SIZE);
         strcat(t1_buf_array, t1_line_array);
+	alloc_array(t1_line, strlen(t1_buf_array) + 1, T1_BUF_SIZE);
         strcpy(t1_line_array, t1_buf_array);
         t1_line_ptr = eol(t1_line_array);
     }
