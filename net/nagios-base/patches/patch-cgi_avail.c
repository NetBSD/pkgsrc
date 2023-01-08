$NetBSD: patch-cgi_avail.c,v 1.6 2023/01/08 23:33:59 sekiya Exp $

64-bit time_t workaround

--- cgi/avail.c.orig	2022-11-17 05:52:51.000000000 +0900
+++ cgi/avail.c	2023-01-09 07:01:49.208846376 +0900
@@ -377,10 +377,10 @@
 				host_report_url("all", "View Availability Report For All Hosts");
 				printf("<BR>\n");
 #ifdef USE_TRENDS
-				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&assumestateretention=%s&assumeinitialstates=%s&includesoftstates=%s&assumestatesduringnotrunning=%s&initialassumedhoststate=%d&backtrack=%d'>View Trends For This Host</a><BR>\n", TRENDS_CGI, url_encode(host_name), t1, t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_host_state, backtrack_archives);
+				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&assumestateretention=%s&assumeinitialstates=%s&includesoftstates=%s&assumestatesduringnotrunning=%s&initialassumedhoststate=%d&backtrack=%d'>View Trends For This Host</a><BR>\n", TRENDS_CGI, url_encode(host_name), (unsigned long)t1, (unsigned long)t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_host_state, backtrack_archives);
 #endif
 #ifdef USE_HISTOGRAM
-				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Alert Histogram For This Host</a><BR>\n", HISTOGRAM_CGI, url_encode(host_name), t1, t2, (assume_state_retention == TRUE) ? "yes" : "no");
+				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Alert Histogram For This Host</a><BR>\n", HISTOGRAM_CGI, url_encode(host_name), (unsigned long)t1, (unsigned long)t2, (assume_state_retention == TRUE) ? "yes" : "no");
 #endif
 				printf("<a href='%s?host=%s'>View Status Detail For This Host</a><BR>\n", STATUS_CGI, url_encode(host_name));
 				printf("<a href='%s?host=%s'>View Alert History For This Host</a><BR>\n", HISTORY_CGI, url_encode(host_name));
@@ -393,11 +393,11 @@
 				printf("<BR>\n");
 #ifdef USE_TRENDS
 				printf("<a href='%s?host=%s", TRENDS_CGI, url_encode(host_name));
-				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s&includesoftstates=%s&assumeinitialstates=%s&assumestatesduringnotrunning=%s&initialassumedservicestate=%d&backtrack=%d'>View Trends For This Service</a><BR>\n", url_encode(svc_description), t1, t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_service_state, backtrack_archives);
+				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s&includesoftstates=%s&assumeinitialstates=%s&assumestatesduringnotrunning=%s&initialassumedservicestate=%d&backtrack=%d'>View Trends For This Service</a><BR>\n", url_encode(svc_description), (unsigned long)t1, (unsigned long)t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_service_state, backtrack_archives);
 #endif
 #ifdef USE_HISTOGRAM
 				printf("<a href='%s?host=%s", HISTOGRAM_CGI, url_encode(host_name));
-				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Alert Histogram For This Service</a><BR>\n", url_encode(svc_description), t1, t2, (assume_state_retention == TRUE) ? "yes" : "no");
+				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Alert Histogram For This Service</a><BR>\n", url_encode(svc_description), (unsigned long)t1, (unsigned long)t2, (assume_state_retention == TRUE) ? "yes" : "no");
 #endif
 				printf("<A HREF='%s?host=%s&", HISTORY_CGI, url_encode(host_name));
 				printf("service=%s'>View Alert History For This Service</A><BR>\n", url_encode(svc_description));
@@ -5254,7 +5254,7 @@
 
 	printf("<a href='%s?host=%s", AVAIL_CGI, url_encode(hn));
 	printf("&show_log_entries");
-	printf("&t1=%lu&t2=%lu", t1, t2);
+	printf("&t1=%lu&t2=%lu", (unsigned long)t1, (unsigned long)t2);
 	printf("&backtrack=%d", backtrack_archives);
 	printf("&assumestateretention=%s", (assume_state_retention == TRUE) ? "yes" : "no");
 	printf("&assumeinitialstates=%s", (assume_initial_states == TRUE) ? "yes" : "no");
@@ -5278,7 +5278,7 @@
 
 	printf("<a href='%s?host=%s", AVAIL_CGI, url_encode(hn));
 	printf("&service=%s", url_encode(sd));
-	printf("&t1=%lu&t2=%lu", t1, t2);
+	printf("&t1=%lu&t2=%lu", (unsigned long)t1, (unsigned long)t2);
 	printf("&backtrack=%d", backtrack_archives);
 	printf("&assumestateretention=%s", (assume_state_retention == TRUE) ? "yes" : "no");
 	printf("&assumeinitialstates=%s", (assume_initial_states == TRUE) ? "yes" : "no");
