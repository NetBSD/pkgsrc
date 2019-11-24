$NetBSD: patch-xymond_combostatus.c,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8106/
Fix problems with meta-combostatuses (Thanks, Dominique Delporte)

--- xymond/combostatus.c.orig	2015-11-03 01:37:39.000000000 +0000
+++ xymond/combostatus.c
@@ -251,6 +251,7 @@ static long getvalue(char *hostname, cha
 	for (walk = testhead; (walk && ( (strcmp(walk->reshostname, hostname) != 0) || (strcmp(walk->restestname, testname) != 0) ) ); walk = walk->next);
 	if (walk != NULL) {
 		/* It is a combo test they want the result of. */
+		*color = (walk->result ? COL_GREEN : COL_RED);
 		return walk->result;
 	}
 
