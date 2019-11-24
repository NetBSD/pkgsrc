$NetBSD: patch-lib_availability.c,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8081/
Fix assorted crashes with xymongen report generation after string changes

--- lib/availability.c.orig	2019-07-23 14:46:51.000000000 +0000
+++ lib/availability.c
@@ -31,6 +31,7 @@ static int reptimecnt = 0;
 
 replog_t *reploghead = NULL;
 
+/* TODO: This logic differs from elsewhere below */
 char *durationstr(time_t duration)
 {
 	static char dur[100];
@@ -42,13 +43,13 @@ char *durationstr(time_t duration)
 	else {
 		dur[0] = '\0';
 		if (duration > 86400) {
-			snprintf(dhelp, sizeof(dhelp), "%u days ", (unsigned int)(duration / 86400));
+			snprintf(dhelp, 100, "%u days ", (unsigned int)(duration / 86400));
 			duration %= 86400;
-			strncpy(dur, dhelp, sizeof(dur));
+			strncpy(dur, dhelp, 100);
 		}
-		snprintf(dhelp, sizeof(dhelp), "%u:%02u:%02u", (unsigned int)(duration / 3600), 
+		snprintf(dhelp, 100, "%u:%02u:%02u", (unsigned int)(duration / 3600), 
 			(unsigned int)((duration % 3600) / 60), (unsigned int)(duration % 60));
-		strncat(dur, dhelp, (sizeof(dur) - strlen(dur)));
+		strncat(dur, dhelp, (100 - strlen(dur)));
 	}
 
 	return dur;
@@ -162,21 +163,21 @@ static char *parse_histlogfile(char *hos
 
 	cause[0] = '\0';
 
-	snprintf(fn, sizeof(fn), "%s/%s", xgetenv("XYMONHISTLOGS"), commafy(hostname));
+	snprintf(fn, PATH_MAX, "%s/%s", xgetenv("XYMONHISTLOGS"), commafy(hostname));
 	for (p = strrchr(fn, '/'); (*p); p++) if (*p == ',') *p = '_';
-	snprintf(p, (sizeof(fn) - (p - fn)), "/%s/%s", servicename, timespec);
+	snprintf(p, (PATH_MAX - (p - fn)), "/%s/%s", servicename, timespec);
 
 	dbgprintf("Looking at history logfile %s\n", fn);
 	fd = fopen(fn, "r");
 	if (fd != NULL) {
-		while (!causefull && fgets(l, sizeof(l), fd)) {
+		while (!causefull && fgets(l, MAX_LINE_LEN, fd)) {
 			p = strchr(l, '\n'); if (p) *p = '\0';
 
 			if ((l[0] == '&') && (strncmp(l, "&green", 6) != 0)) {
 				p = skipwhitespace(skipword(l));
-				if ((strlen(cause) + strlen(p) + strlen("<BR>\n") + 1) < sizeof(cause)) {
-					strncat(cause, p, (sizeof(cause) - strlen(cause)));
-					strncat(cause, "<BR>\n", (sizeof(cause) - strlen(cause)));
+				if ((strlen(cause) + strlen(p) + strlen("<BR>\n") + 1) < MAX_LINE_LEN) {
+					strncat(cause, p, (MAX_LINE_LEN - strlen(cause)));
+					strncat(cause, "<BR>\n", (MAX_LINE_LEN - strlen(cause)));
 				}
 				else causefull = 1;
 			}
@@ -184,7 +185,7 @@ static char *parse_histlogfile(char *hos
 
 #if 1
 		if (strlen(cause) == 0) {
-			strncpy(cause, "See detailed log", sizeof(cause));
+			strncpy(cause, "See detailed log", MAX_LINE_LEN);
 		}
 #else
 		/* What is this code supposed to do ? The sscanf seemingly never succeeds */
@@ -192,28 +193,28 @@ static char *parse_histlogfile(char *hos
 		if (strlen(cause) == 0) {
 			int offset;
 			rewind(fd);
-			if (fgets(l, sizeof(l), fd)) {
+			if (fgets(l, MAX_LINE_LEN, fd)) {
 				p = strchr(l, '\n'); if (p) *p = '\0';
 				if (sscanf(l, "%*s %*s %*s %*s %*s %*s %*s %n", &offset) == 1) {
-					strncpy(cause, l+offset, sizeof(cause));
+					strncpy(cause, l+offset, MAX_LINE_LEN);
 				}
 				else {
 					errprintf("Scan of file %s failed, l='%s'\n", fn, l);
 				}
-				cause[sizeof(cause)-1] = '\0';
+				cause[MAX_LINE_LEN-1] = '\0';
 			}
 		}
 #endif
 
 		if (causefull) {
-			cause[sizeof(cause) - strlen(" [Truncated]") - 1] = '\0';
-			strncat(cause, " [Truncated]", (sizeof(cause) - strlen(cause)));
+			cause[MAX_LINE_LEN - strlen(" [Truncated]") - 1] = '\0';
+			strncat(cause, " [Truncated]", (MAX_LINE_LEN - strlen(cause)));
 		}
 
 		fclose(fd);
 	}
 	else {
-		strncpy(cause, "No historical status available", sizeof(cause));
+		strncpy(cause, "No historical status available", MAX_LINE_LEN);
 	}
 
 	return strdup(cause);
@@ -358,7 +359,7 @@ static char *timename(char *timestring)
 
 	if (tokens[4]) {
 		/* Got all 5 elements */
-		snprintf(timespec, sizeof(timespec), "%s_%s_%s_%s_%s",
+		snprintf(timespec, 25, "%s_%s_%s_%s_%s",
 			 tokens[0], tokens[1], tokens[2], tokens[3], tokens[4]);
 	}
 	else {
@@ -404,17 +405,17 @@ int parse_historyfile(FILE *fd, reportin
 	/* If for_history and fromtime is 0, don't do any seeking */
 	if (!for_history || (fromtime > 0)) {
 		fileerrors = scan_historyfile(fd, fromtime, totime, 
-				      l, sizeof(l), &starttime, &duration, colstr, sizeof(colstr));
+				      l, MAX_LINE_LEN, &starttime, &duration, colstr, MAX_LINE_LEN);
 	}
 	else {
 		/* Already positioned (probably in a pipe) */
-		if (get_historyline(l, sizeof(l), fd, &fileerrors, colstr, &uistart, &uidur, &scanres)) {
+		if (get_historyline(l, MAX_LINE_LEN, fd, &fileerrors, colstr, &uistart, &uidur, &scanres)) {
 			starttime = uistart; duration = uidur;
 			if (scanres == 2) duration = getcurrenttime(NULL) - starttime;
 		}
 		else {
 			starttime = getcurrenttime(NULL); duration = 0;
-			strncpy(colstr, "clear", sizeof(colstr));
+			strncpy(colstr, "clear", MAX_LINE_LEN);
 			fileerrors = 1;
 		}
 	}
@@ -437,7 +438,7 @@ int parse_historyfile(FILE *fd, reportin
 	do {
 		/* If event ends after our reportend, adjust duration */
 		if ((starttime + duration) > totime) duration = (totime - starttime);
-		strncat(colstr, " ", (sizeof(colstr) - strlen(colstr))); color = parse_color(colstr);
+		strncat(colstr, " ", (MAX_LINE_LEN - strlen(colstr))); color = parse_color(colstr);
 
 		if (color != -1) {
 			unsigned long sladuration = 0;
@@ -474,7 +475,7 @@ int parse_historyfile(FILE *fd, reportin
 		}
 
 		if ((starttime + duration) < totime) {
-			if (get_historyline(l, sizeof(l), fd, &fileerrors, colstr, &uistart, &uidur, &scanres)) {
+			if (get_historyline(l, MAX_LINE_LEN, fd, &fileerrors, colstr, &uistart, &uidur, &scanres)) {
 				starttime = uistart; duration = uidur;
 				if (scanres == 2) duration = getcurrenttime(NULL) - starttime;
 			}
@@ -560,9 +561,9 @@ int history_color(FILE *fd, time_t snaps
 	char *p;
 
 	*histlogname = NULL;
-	scan_historyfile(fd, snapshot, snapshot, l, sizeof(l), starttime, &duration, colstr, sizeof(colstr));
+	scan_historyfile(fd, snapshot, snapshot, l, MAX_LINE_LEN, starttime, &duration, colstr, MAX_LINE_LEN);
 	
-	strncat(colstr, " ", (sizeof(colstr) - strlen(colstr)));
+	strncat(colstr, " ", (MAX_LINE_LEN - strlen(colstr)));
 	color = parse_color(colstr);
 	if ((color == COL_PURPLE) || (color == -1)) {
 		color = -2;
@@ -621,25 +622,25 @@ int main(int argc, char *argv[])
 	fclose(fd);
 
 	for (rwalk = reploghead; (rwalk); rwalk = rwalk->next) {
-		char start[30];
-		char end[30];
-		char dur[30], dhelp[30];
+		char start[MAXDURSIZE];
+		char end[MAXDURSIZE];
+		char dur[MAXDURSIZE], dhelp[MAXDURSIZE];
 		time_t endtime;
 		time_t duration;
 
-		strftime(start, sizeof(start), "%a %b %d %H:%M:%S %Y", localtime(&rwalk->starttime));
+		strftime(start, MAXDURSIZE, "%a %b %d %H:%M:%S %Y", localtime(&rwalk->starttime));
 		endtime = rwalk->starttime + rwalk->duration;
-		strftime(end, sizeof(end), "%a %b %d %H:%M:%S %Y", localtime(&endtime));
+		strftime(end, MAXDURSIZE, "%a %b %d %H:%M:%S %Y", localtime(&endtime));
 
 		duration = rwalk->duration;
 		dur[0] = '\0';
 		if (duration > 86400) {
-			snprintf(dhelp, sizeof(dhelp), "%lu days ", (duration / 86400));
+			snprintf(dhelp, MAXDURSIZE, "%lu days ", (duration / 86400));
 			duration %= 86400;
-			strncpy(dur, dhelp, sizeof(dur));
+			strncpy(dur, dhelp, MAXDURSIZE);
 		}
-		snprintf(dhelp, sizeof(dhelp), "%lu:%02lu:%02lu", duration / 3600, ((duration % 3600) / 60), (duration % 60));
-		strncat(dur, dhelp, (sizeof(dur) - strlen(dur)));
+		snprintf(dhelp, MAXDURSIZE, "%lu:%02lu:%02lu", duration / 3600, ((duration % 3600) / 60), (duration % 60));
+		strncat(dur, dhelp, (MAXDURSIZE - strlen(dur)));
 
 		dbgprintf("Start: %s, End: %s, Color: %s, Duration: %s, Cause: %s\n",
 			start, end, colorname(rwalk->color), dur, rwalk->cause);
