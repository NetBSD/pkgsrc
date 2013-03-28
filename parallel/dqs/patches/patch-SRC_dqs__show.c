$NetBSD: patch-SRC_dqs__show.c,v 1.1 2013/03/28 21:37:23 joerg Exp $

--- SRC/dqs_show.c.orig	2013-03-28 16:22:14.000000000 +0000
+++ SRC/dqs_show.c
@@ -46,9 +46,7 @@ static char dqs_show_rcsid[]="$Id: dqs_s
 #include "dqs_errno.h"
 
 /************************************************************************/
-int dqs_show_qstat_request(job)
-     dqs_job_type *job;
-     
+void dqs_show_qstat_request(dqs_job_type *job)
 {
   
   int i;
