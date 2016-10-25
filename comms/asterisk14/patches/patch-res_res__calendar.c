$NetBSD: patch-res_res__calendar.c,v 1.1.1.1 2016/10/25 08:17:08 jnemeth Exp $

--- res/res_calendar.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ res/res_calendar.c
@@ -1245,7 +1245,7 @@ static int calendar_query_exec(struct as
 	i = ao2_iterator_init(cal->events, 0);
 	while ((event = ao2_iterator_next(&i))) {
 		if (!(start > event->end || end < event->start)) {
-			ast_debug(10, "%s (%ld - %ld) overlapped with (%ld - %ld)\n", event->summary, (long) event->start, (long) event->end, (long) start, (long) end);
+			ast_debug(10, "%s (%jd - %jd) overlapped with (%jd - %jd)\n", event->summary, (intmax_t) event->start, (intmax_t) event->end, (intmax_t) start, (intmax_t) end);
 			if (add_event_to_list(events, event, start, end) < 0) {
 				event = ast_calendar_unref_event(event);
 				cal = unref_calendar(cal);
@@ -1378,9 +1378,9 @@ static int calendar_query_result_exec(st
 		} else if (!strcasecmp(args.field, "uid")) {
 			ast_copy_string(buf, entry->event->uid, len);
 		} else if (!strcasecmp(args.field, "start")) {
-			snprintf(buf, len, "%ld", (long) entry->event->start);
+			snprintf(buf, len, "%jd", (intmax_t) entry->event->start);
 		} else if (!strcasecmp(args.field, "end")) {
-			snprintf(buf, len, "%ld", (long) entry->event->end);
+			snprintf(buf, len, "%jd", (intmax_t) entry->event->end);
 		} else if (!strcasecmp(args.field, "busystate")) {
 			snprintf(buf, len, "%u", entry->event->busy_state);
 		} else if (!strcasecmp(args.field, "attendees")) {
@@ -1739,9 +1739,9 @@ static int calendar_event_read(struct as
 	} else if (!strcasecmp(data, "uid")) {
 		ast_copy_string(buf, event->uid, len);
 	} else if (!strcasecmp(data, "start")) {
-		snprintf(buf, len, "%ld", (long)event->start);
+		snprintf(buf, len, "%jd", (intmax_t)event->start);
 	} else if (!strcasecmp(data, "end")) {
-		snprintf(buf, len, "%ld", (long)event->end);
+		snprintf(buf, len, "%jd", (intmax_t)event->end);
 	} else if (!strcasecmp(data, "busystate")) {
 		snprintf(buf, len, "%u", event->busy_state);
 	} else if (!strcasecmp(data, "attendees")) {
