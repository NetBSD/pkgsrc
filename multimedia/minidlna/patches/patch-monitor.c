$NetBSD: patch-monitor.c,v 1.1 2018/06/02 12:53:10 jmcneill Exp $

--- monitor.c.orig	2018-05-04 23:11:25.000000000 +0000
+++ monitor.c
@@ -442,7 +442,7 @@ monitor_insert_file(const char *name, co
 			}
 			depth++;
 			strcpy(last_dir, parent_buf);
-			parent_buf = dirname(parent_buf);
+			parent_buf = dirname(last_dir);
 		}
 		while( strcmp(parent_buf, "/") != 0 );
 
