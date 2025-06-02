$NetBSD: patch-src_input_proc__diskstats.c,v 1.1 2025/06/02 16:49:08 vins Exp $

Fix buffer dereference.  

--- src/input/proc_diskstats.c.orig	2021-01-10 14:52:39.000000000 +0000
+++ src/input/proc_diskstats.c
@@ -158,8 +158,8 @@ void get_disk_stats_proc (char verbose) 
 				} else {
 					/* neither new nor old /proc/partitions nor /proc/diskstats */
 					free(name);
-					free(buffer);
 					deinit(1, "wrong format of procfile. %i: %s\n",n,buffer);
+					free(buffer);
 				}
 			}
 		}
