$NetBSD: patch-nc_test4_run_bm_ar4.sh,v 1.1 2012/03/07 16:11:30 adam Exp $

Fix compatibility issue.

--- nc_test4/run_bm_ar4.sh.orig	2012-03-07 11:54:25.000000000 +0000
+++ nc_test4/run_bm_ar4.sh
@@ -44,7 +44,7 @@ do
 	do
 	    for c2 in 128
 	    do
-		if test $d == -1; then
+		if test $d = -1; then
 		    file_out="pr_A1_${c0}_${c1}_${c2}.nc"
 		else
 		    file_out="pr_A1_z${d}_${c0}_${c1}_${c2}.nc"
