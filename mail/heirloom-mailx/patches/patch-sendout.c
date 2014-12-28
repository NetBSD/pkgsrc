$NetBSD: patch-sendout.c,v 1.1 2014/12/28 14:16:14 bsiegert Exp $

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
