$NetBSD: patch-config.c,v 1.3 2016/02/24 20:50:29 nils Exp $

Solves NetBSD compilation errors. Patch submitted upstream (PR #17).

--- config.c.orig	2016-01-20 09:47:36.000000000 +0000
+++ config.c
@@ -146,11 +146,11 @@ static char *isolateValue(const char *fi
 {
     char *chptr = *startPtr;
 
-    while (chptr - *buf < length && isblank(*chptr))
+    while (chptr - *buf < length && isblank((unsigned char)*chptr))
 	chptr++;
     if (chptr - *buf < length && *chptr == '=') {
 	chptr++;
-	while ( chptr - *buf < length && isblank(*chptr))
+	while ( chptr - *buf < length && isblank((unsigned char)*chptr))
 	    chptr++;
     }
 
@@ -167,7 +167,7 @@ static char *isolateValue(const char *fi
 static char *isolateWord(char **strt, char **buf, size_t length) {
 	char *endtag, *start;
 	start = *strt;
-	while (start - *buf < length && isblank(*start))
+	while (start - *buf < length && isblank((unsigned char)*start))
 		start++;
 	endtag = start;
 	while (endtag - *buf < length && isalpha((unsigned char)*endtag)) {
@@ -868,7 +868,7 @@ static int readConfigFile(const char *co
 	}
 	switch (state) {
 		case STATE_DEFAULT:
-			if (isblank(*start))
+			if (isblank((unsigned char)*start))
 				continue;
 			/* Skip comment */
 			if (*start == '#') {
@@ -1533,7 +1533,7 @@ static int readConfigFile(const char *co
 			break;
 		case STATE_DEFINITION_END:
 		case STATE_DEFINITION_END | STATE_SKIP_CONFIG:
-			if (isblank(*start))
+			if (isblank((unsigned char)*start))
 				continue;
 			if (*start != '\n') {
 				message(MESS_ERROR, "%s:%d, unexpected text after }\n",
