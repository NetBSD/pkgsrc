$NetBSD: patch-cgi_trends.c,v 1.6 2023/01/08 23:33:59 sekiya Exp $

64-bit time_t workaround

--- cgi/trends.c.orig	2022-11-17 05:52:51.000000000 +0900
+++ cgi/trends.c	2023-01-09 07:06:43.682160687 +0900
@@ -448,9 +448,9 @@
 			printf("<TR><TD CLASS='linkBox'>\n");
 
 			if(display_type == DISPLAY_HOST_TRENDS) {
-				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&includesoftstates=%s&assumestateretention=%s&assumeinitialstates=%s&assumestatesduringnotrunning=%s&initialassumedhoststate=%d&backtrack=%d&show_log_entries'>View Availability Report For This Host</a><BR>\n", AVAIL_CGI, url_encode(host_name), t1, t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_host_state, backtrack_archives);
+				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&includesoftstates=%s&assumestateretention=%s&assumeinitialstates=%s&assumestatesduringnotrunning=%s&initialassumedhoststate=%d&backtrack=%d&show_log_entries'>View Availability Report For This Host</a><BR>\n", AVAIL_CGI, url_encode(host_name), (unsigned long)t1, (unsigned long)t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_host_state, backtrack_archives);
 #ifdef USE_HISTOGRAM
-				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Alert Histogram For This Host</a><BR>\n", HISTOGRAM_CGI, url_encode(host_name), t1, t2, (assume_state_retention == TRUE) ? "yes" : "no");
+				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Alert Histogram For This Host</a><BR>\n", HISTOGRAM_CGI, url_encode(host_name), (unsigned long)t1, (unsigned long)t2, (assume_state_retention == TRUE) ? "yes" : "no");
 #endif
 				printf("<a href='%s?host=%s'>View Status Detail For This Host</a><BR>\n", STATUS_CGI, url_encode(host_name));
 				printf("<a href='%s?host=%s'>View Alert History For This Host</a><BR>\n", HISTORY_CGI, url_encode(host_name));
@@ -458,14 +458,14 @@
 				}
 			else {
 #ifdef LEGACY_GRAPHICAL_CGIS
-				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&includesoftstates=%s&assumestateretention=%s&assumeinitialstates=%s&assumestatesduringnotrunning=%s&initialassumedservicestate=%d&backtrack=%d'>View Trends For This Host</a><BR>\n", TRENDS_CGI, url_encode(host_name), t1, t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_service_state, backtrack_archives);
+				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&includesoftstates=%s&assumestateretention=%s&assumeinitialstates=%s&assumestatesduringnotrunning=%s&initialassumedservicestate=%d&backtrack=%d'>View Trends For This Host</a><BR>\n", TRENDS_CGI, url_encode(host_name), (unsigned long)t1, (unsigned long)t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_service_state, backtrack_archives);
 #else
-				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&includesoftstates=%s&assumestateretention=%s&assumeinitialstates=%s&assumestatesduringnotrunning=%s&initialassumedservicestate=%d&backtrack=%d'>View Trends For This Host</a><BR>\n", LEGACY_TRENDS_CGI, url_encode(host_name), t1, t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_service_state, backtrack_archives);
+				printf("<a href='%s?host=%s&t1=%lu&t2=%lu&includesoftstates=%s&assumestateretention=%s&assumeinitialstates=%s&assumestatesduringnotrunning=%s&initialassumedservicestate=%d&backtrack=%d'>View Trends For This Host</a><BR>\n", LEGACY_TRENDS_CGI, url_encode(host_name), (unsigned long)t1, (unsigned long)t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_service_state, backtrack_archives);
 #endif
 				printf("<a href='%s?host=%s", AVAIL_CGI, url_encode(host_name));
-				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s&includesoftstates=%s&assumeinitialstates=%s&assumestatesduringnotrunning=%s&initialassumedservicestate=%d&backtrack=%d&show_log_entries'>View Availability Report For This Service</a><BR>\n", url_encode(svc_description), t1, t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_service_state, backtrack_archives);
+				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s&includesoftstates=%s&assumeinitialstates=%s&assumestatesduringnotrunning=%s&initialassumedservicestate=%d&backtrack=%d&show_log_entries'>View Availability Report For This Service</a><BR>\n", url_encode(svc_description), (unsigned long)t1, (unsigned long)t2, (include_soft_states == TRUE) ? "yes" : "no", (assume_state_retention == TRUE) ? "yes" : "no", (assume_initial_states == TRUE) ? "yes" : "no", (assume_states_during_notrunning == TRUE) ? "yes" : "no", initial_assumed_service_state, backtrack_archives);
 				printf("<a href='%s?host=%s", HISTOGRAM_CGI, url_encode(host_name));
-				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Alert Histogram For This Service</a><BR>\n", url_encode(svc_description), t1, t2, (assume_state_retention == TRUE) ? "yes" : "no");
+				printf("&service=%s&t1=%lu&t2=%lu&assumestateretention=%s'>View Alert Histogram For This Service</a><BR>\n", url_encode(svc_description), (unsigned long)t1, (unsigned long)t2, (assume_state_retention == TRUE) ? "yes" : "no");
 				printf("<A HREF='%s?host=%s&", HISTORY_CGI, url_encode(host_name));
 				printf("service=%s'>View Alert History For This Service</A><BR>\n", url_encode(svc_description));
 				printf("<A HREF='%s?host=%s&", NOTIFICATIONS_CGI, url_encode(host_name));
