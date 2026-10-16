$NetBSD: patch-sendout.c,v 1.2 2026/10/16 19:38:11 bsiegert Exp $

Imported Debian package fixes:
- disable option processing for email addresses when calling sendmail

Ref: patch-af,v 1.1.1.1 2008/10/30 13:01:00 obache

--- sendout.c.orig	2011-04-26 21:23:22.000000000 +0000
+++ sendout.c
@@ -51,6 +51,15 @@ static char sccsid[] = "@(#)sendout.c	2.
 #include <time.h>
 #include "md5.h"
 
+#ifdef HAVE_PATHS_H
+#include <paths.h>
+#endif
+
+#ifdef _PATH_SENDMAIL
+#undef SENDMAIL
+#define SENDMAIL _PATH_SENDMAIL
+#endif
+
 /*
  * Mail -- a mail program
  *
@@ -835,7 +844,7 @@ start_mta(struct name *to, struct name *
 #endif	/* HAVE_SOCKETS */
 
 	if ((smtp = value("smtp")) == NULL) {
-		args = unpack(cat(mailargs, to));
+                args = unpack(mailargs, to);
 		if (debug || value("debug")) {
 			printf(catgets(catd, CATSET, 181,
 					"Sendmail arguments:"));
@@ -1135,13 +1144,11 @@ mkdate(FILE *fo, const char *field)
 	int tzdiff, tzdiff_hour, tzdiff_min;
 
 	time(&t);
-	tzdiff = t - mktime(gmtime(&t));
+	tmptr = localtime(&t);
+	tzdiff = tmptr->tm_gmtoff;
 	tzdiff_hour = (int)(tzdiff / 60);
 	tzdiff_min = tzdiff_hour % 60;
 	tzdiff_hour /= 60;
-	tmptr = localtime(&t);
-	if (tmptr->tm_isdst > 0)
-		tzdiff_hour++;
 	return fprintf(fo, "%s: %s, %02d %s %04d %02d:%02d:%02d %+05d\n",
 			field,
 			weekday_names[tmptr->tm_wday],
