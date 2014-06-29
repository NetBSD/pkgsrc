$NetBSD: patch-mstime.i,v 1.1 2014/06/29 03:24:33 dholland Exp $

supply missing return type

--- mstime.i~	1991-07-16 15:53:11.000000000 +0000
+++ mstime.i
@@ -12,6 +12,7 @@ static char mstimeid[]="@(#) mstime.i 2.
 Function mstime() converts time in seconds since January 1 of BASEYEAR
 to MS-DOS format date and time.
 */
+void
 mstime(longtime, date, time)
 long longtime;       /* input:  seconds since Jan 1, BASEYEAR   */
 int *date, *time;    /* output: MS-DOS format date and time */
