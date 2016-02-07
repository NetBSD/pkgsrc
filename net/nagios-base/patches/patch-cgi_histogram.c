$NetBSD: patch-cgi_histogram.c,v 1.3 2016/02/07 21:52:06 bouyer Exp $

64bit time_t workaround

--- cgi/histogram.c.orig	2016-02-07 22:21:30.000000000 +0100
+++ cgi/histogram.c	2016-02-07 22:22:24.000000000 +0100
@@ -338,9 +338,9 @@
 
 			if(display_type == DISPLAY_HOST_HISTOGRAM) {
 #ifdef USE_TRENDS
-				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Trends For This Host</a><BR>\n", TRENDS_CGI, url_encode(host_name), t1, t2, (assume_state_retention == TRUE) ? "yes" : "no");
+				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Trends For This Host</a><BR>\n", TRENDS_CGI, url_encode(host_name), (unsigned long)t1, (unsigned long)t2, (assume_state_retention == TRUE) ? "yes" : "no");
 #endif
-				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&assumestateretention=%s&show_log_entries'>View Availability Report For This Host</a><BR>\n", AVAIL_CGI, url_encode(host_name), t1, t2, (assume_state_retention == TRUE) ? "yes" : "no");
+				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&assumestateretention=%s&show_log_entries'>View Availability Report For This Host</a><BR>\n", AVAIL_CGI, url_encode(host_name), (unsigned long)t1, (unsigned long)t2, (assume_state_retention == TRUE) ? "yes" : "no");
 				printf("<a href='%s?host=%s'>View Status Detail For This Host</a><BR>\n", STATUS_CGI, url_encode(host_name));
 				printf("<a href='%s?host=%s'>View History For This Host</a><BR>\n", HISTORY_CGI, url_encode(host_name));
 				printf("<a href='%s?host=%s'>View Notifications For This Host</a><BR>\n", NOTIFICATIONS_CGI, url_encode(host_name));
@@ -349,9 +349,9 @@
 #ifdef USE_TRENDS
 				printf("<a href='%s?host=%s", TRENDS_CGI, url_encode(host_name));
 #endif
-				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Trends For This Service</a><BR>\n", url_encode(svc_description), t1, t2, (assume_state_retention == TRUE) ? "yes" : "no");
+				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Trends For This Service</a><BR>\n", url_encode(svc_description), (unsigned long)t1, (unsigned long)t2, (assume_state_retention == TRUE) ? "yes" : "no");
 				printf("<a href='%s?host=%s", AVAIL_CGI, url_encode(host_name));
-				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s&show_log_entries'>View Availability Report For This Service</a><BR>\n", url_encode(svc_description), t1, t2, (assume_state_retention == TRUE) ? "yes" : "no");
+				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s&show_log_entries'>View Availability Report For This Service</a><BR>\n", url_encode(svc_description), (unsigned long)t1, (unsigned long)t2, (assume_state_retention == TRUE) ? "yes" : "no");
 				printf("<A HREF='%s?host=%s&", HISTORY_CGI, url_encode(host_name));
 				printf("service=%s'>View History For This Service</A><BR>\n", url_encode(svc_description));
 				printf("<A HREF='%s?host=%s&", NOTIFICATIONS_CGI, url_encode(host_name));
