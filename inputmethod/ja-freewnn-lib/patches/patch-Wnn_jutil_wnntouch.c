$NetBSD: patch-Wnn_jutil_wnntouch.c,v 1.1 2026/07/10 23:32:38 tsutsui Exp $

- Remove unnecessary old style function declarations

--- Wnn/jutil/wnntouch.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/jutil/wnntouch.c
@@ -54,7 +54,6 @@ static char *rcs_id = "$Id: wnntouch.c,v
 
 #include "etc.h"
 
-extern int input_file_header (), check_inode (), change_file_uniq ();
 static void usage (void);
 
 char *com_name;
