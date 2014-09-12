$NetBSD: patch-compose.c,v 1.1 2014/09/12 04:17:38 dholland Exp $

- Use standard headers.
- Silence compiler warning about format string.
- Call varargs functions correctly.

--- compose.c~	1998-05-14 01:29:15.000000000 +0000
+++ compose.c
@@ -38,6 +38,7 @@ static char XRNrcsid[] = "$Id: compose.c
 #include <ctype.h>
 #include <errno.h>
 #include <sys/file.h>
+#include <stdlib.h>
 #include <signal.h>
 #include <assert.h>
 #include "error_hnds.h"
@@ -1907,7 +1908,7 @@ getIncludedArticleText()
 
      if (PostingMode == FORWARD) {
 	 int line_size;
-       (void) sprintf(input, FORWARDED_ARTICLE_END_MSG);
+       (void) sprintf(input, "%s", FORWARDED_ARTICLE_END_MSG);
 	 line_size = strlen(input);
 	 if (prefix_size + line_size > size - cur_size - 1) {
 	     /* See above */
@@ -2334,7 +2335,7 @@ Call_Editor(
 	    for (i = 3; i < maxdesc; i++) {
 		(void) close(i);
 	    }
-	    (void) execl("/bin/sh", "sh", "-c", buffer, 0);
+	    (void) execl("/bin/sh", "sh", "-c", buffer, (const char *)NULL);
           (void) fprintf(stderr, ERROR_EXEC_FAILED_MSG, buffer);
 	    (void) _exit(127);
 	}
@@ -2902,7 +2903,7 @@ static void switch_message_type(Header)
     return;
 
   title = followup_or_reply_title(Header, followup, reply);
-  XtVaSetValues(ComposeLabel, XtNlabel, title, 0);
+  XtVaSetValues(ComposeLabel, XtNlabel, title, (const void *)NULL);
 
   headers = update_headers(Header, False, followup, reply);
   addField(headers);
