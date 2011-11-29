$NetBSD: patch-opensync_opensync_time.c,v 1.1 2011/11/29 15:12:08 hans Exp $

--- opensync/opensync_time.c.orig	2007-03-27 13:49:18.000000000 +0200
+++ opensync/opensync_time.c	2011-11-28 20:41:03.626682362 +0100
@@ -889,16 +889,13 @@ osync_bool osync_time_isdst(const char *
 	osync_trace(TRACE_ENTRY, "%s(%s, %p)", __func__, vtime, tzid);
 
 	int year;
-	char *newyear = NULL;
-	time_t newyear_t, timestamp;
+	time_t timestamp;
 	struct tm *std_changetime, *dst_changetime;
 	time_t dstStamp, stdStamp;
 	xmlNode *current = NULL;
 
 	sscanf(vtime, "%4d%*2d%*2dT%*2d%*d%*2d%*c", &year);
 
-	newyear = g_strdup_printf("%4d0101T000000", year);
-	newyear_t = osync_time_vtime2unix(newyear, 0);
 	timestamp = osync_time_vtime2unix(vtime, 0);
 
 	/* Handle XML Timezone field */
