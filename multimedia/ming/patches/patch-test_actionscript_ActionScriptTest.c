$NetBSD: patch-test_actionscript_ActionScriptTest.c,v 1.1 2012/05/12 06:36:40 obache Exp $

* Allow tabs in addition to spaces in the macro listing testcases.
  https://github.com/libming/libming/commit/d2e12f8

--- test/actionscript/ActionScriptTest.c.orig	2011-10-26 06:33:18.000000000 +0000
+++ test/actionscript/ActionScriptTest.c
@@ -30,6 +30,7 @@
 
 #include <libming.h>
 #include <run_test.h>
+#include <ctype.h>
 #include <stdio.h>
 #include <string.h>
 #include <stdarg.h>
@@ -81,19 +82,18 @@ do_tests()
 	char vstr[2];
 	const char *from, *to, *end;
 	char *ptr;
-	int version;
+	size_t len = strlen(all_tests);
 
 	from = all_tests;
-	end = from+strlen(all_tests);
+	end = from+len;
 	do
 	{
-		while (*from && *from == ' ') ++from;
+		while (*from && isspace(*from)) ++from;
 		if ( ! *from ) break;
 
-		to=strchr(from, ' ');
-		if ( ! to ) to = end;
+		to = from + strcspn(from, " \t");
 
-		size_t len = to-from;
+		len = to-from;
 		if ( len+1 >= PATH_MAX )
 		{
 			fprintf(stderr,
