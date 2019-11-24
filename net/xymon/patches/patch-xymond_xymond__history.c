$NetBSD: patch-xymond_xymond__history.c,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8080/
Don't crash on a missing allevents file

--- xymond/xymond_history.c.orig	2015-10-01 14:42:42.000000000 +0000
+++ xymond/xymond_history.c
@@ -170,8 +170,11 @@ int main(int argc, char *argv[])
 		alleventsfd = fopen(alleventsfn, "a");
 		if (alleventsfd == NULL) {
 			errprintf("Cannot open the all-events file '%s'\n", alleventsfn);
+			return 1;
+		}
+		else {
+			setvbuf(alleventsfd, (char *)NULL, _IOLBF, 0);
 		}
-		setvbuf(alleventsfd, (char *)NULL, _IOLBF, 0);
 	}
 
 	/* For picking up lost children */
