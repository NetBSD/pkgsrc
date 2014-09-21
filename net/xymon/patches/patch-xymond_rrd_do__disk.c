$NetBSD: patch-xymond_rrd_do__disk.c,v 1.1 2014/09/21 14:49:45 spz Exp $

BSDish systems' df -i retains the block stats, so you'd want 8, 7 and 5.
Fortunately, counting from behind instead works out.
This also fits AIX if you are using df -v.

--- xymond/rrd/do_disk.c.orig	2012-07-13 14:05:20.000000000 +0000
+++ xymond/rrd/do_disk.c	2014-09-21 13:52:45.000000000 +0000
@@ -139,10 +139,10 @@
 			aused = str2ll(columns[2], NULL);
 			break;
 		  case DT_UNIX:
-			diskname = xstrdup(columns[5]);
-			p = strchr(columns[4], '%'); if (p) *p = ' ';
-			pused = atoi(columns[4]);
-			aused = str2ll(columns[2], NULL);
+			diskname = xstrdup(columns[columncount-1]);
+			p = strchr(columns[columncount-2], '%'); if (p) *p = ' ';
+			pused = atoi(columns[columncount-2]);
+			aused = str2ll(columns[columncount-4], NULL);
 			break;
 		  case DT_NETAPP:
 			diskname = xstrdup(columns[1]);
