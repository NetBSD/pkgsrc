$NetBSD: patch-perf_cairo-perf-report.c,v 1.1 2022/04/05 10:06:41 riastradh Exp $

Fix ctype(3) abuse.

--- perf/cairo-perf-report.c.orig	2018-08-17 01:10:53.000000000 +0000
+++ perf/cairo-perf-report.c
@@ -100,7 +100,7 @@ do {									\
 #define parse_string(result)						\
 do {									\
     for (end = s; *end; end++)						\
-	if (isspace (*end))						\
+	if (isspace ((unsigned char)*end))				\
 	    break;							\
     (result) = strndup (s, end - s);					\
     if ((result) == NULL) {						\
