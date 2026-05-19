$NetBSD: patch-pack__date.c,v 1.1 2026/05/19 18:38:11 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- pack_date.c.orig	2026-05-16 21:28:43.390275606 +0000
+++ pack_date.c
@@ -16,7 +16,7 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 
@@ -308,7 +308,7 @@ numeric_zone(register char *date)
 	    break;
     }
 
-    for (n = 0; n < MAXZ && *date && isdigit((int) *date);)
+    for (n = 0; n < MAXZ && *date && ISDIGIT(*date);)
 	num[n++] = *date++;
     num[n] = '\0';
 
@@ -348,27 +348,27 @@ tzone(register char *date)
     static char     zone[MAXZ];
     register struct zonetab *z;
 
-    while (*date && isspace((int) *date))
+    while (*date && ISSPACE(*date))
 	date++;
 
-    if (*date == '+' || *date == '-' || isdigit((int) *date))
+    if (*date == '+' || *date == '-' || ISDIGIT(*date))
 	return numeric_zone(date);
 
-    for (; *date && isascii(*date); date++) {
-	if (isspace((int) *date))
+    for (; *date && ISASCII(*date); date++) {
+	if (ISSPACE(*date))
 	    break;
-	if (!isalnum((int) *date))
+	if (!ISALNUM(*date))
 	    continue;		/* p.s.t. -> pst */
 	if (i == MAXZ)
 	    continue;
-	zone[i++] = islower((int) *date) ? toupper((int) *date) : *date;
+	zone[i++] = ISLOWER(*date) ? TOUPPER(*date) : *date;
     }
 
-    while (*date && isspace((int) *date))
+    while (*date && ISSPACE(*date))
 	date++;
     if (i == 0)
 	return 0;
-    if (*date == '+' || *date == '-' || isdigit((int) *date))
+    if (*date == '+' || *date == '-' || ISDIGIT(*date))
 	return numeric_zone(date);
 
     zone[i] = '\0';
@@ -400,11 +400,11 @@ next_int(char **dp)
     register char  *str = *dp;
     register int    i;
 
-    while (*str && !isdigit((int) *str))
+    while (*str && !ISDIGIT(*str))
 	str++;
 
     i = atoi(str);
-    while (*str && isdigit((int) *str))
+    while (*str && ISDIGIT(*str))
 	str++;
 
     *dp = str;
@@ -428,7 +428,7 @@ pack_date(char *date)
     if (date == NULL || (day = next_int(&date)) == 0)
 	return 0;
 
-    while (*date && isspace((int) *date))
+    while (*date && ISSPACE(*date))
 	date++;
 
     if (date[0] == '\0' || date[1] == '\0' || date[2] == '\0')
