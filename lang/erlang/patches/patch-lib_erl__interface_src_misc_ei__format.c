$NetBSD: patch-lib_erl__interface_src_misc_ei__format.c,v 1.1 2024/05/27 19:07:50 riastradh Exp $

Fix ctype(3) misuse.

--- lib/erl_interface/src/misc/ei_format.c.orig	2024-05-02 13:07:57.000000000 +0000
+++ lib/erl_interface/src/misc/ei_format.c
@@ -71,7 +71,7 @@ static int eiformat(const char** fmt, un
     int res;
     ei_x_buff x2;
 
-    while (isspace((int)*p))
+    while (isspace((unsigned char)*p))
 	++p;
     switch (*p) {
     case '~':
@@ -117,11 +117,11 @@ static int eiformat(const char** fmt, un
 	    break;
 	}
     default:
-	if (isdigit((int)*p))
+	if (isdigit((unsigned char)*p))
 	    res = pdigit(&p, x);
-	else if ((*p == '-' || *p == '+') && isdigit((int)*(p+1)))
+	else if ((*p == '-' || *p == '+') && isdigit((unsigned char)*(p+1)))
 	    res = pdigit(&p, x);
-	else if (islower((int)*p))
+	else if (islower((unsigned char)*p))
 	    res = patom(&p, x);
 	else
 	    res = -1;
@@ -142,7 +142,7 @@ static int patom(const char** fmt, ei_x_
     
     for (;;) {
 	c = *(*fmt)++;
-	if (isalnum((int) c) || (c == '_') || (c == '@'))
+	if (isalnum((unsigned char) c) || (c == '_') || (c == '@'))
 	    continue;
 	else
 	    break;
@@ -168,7 +168,7 @@ static int pdigit(const char** fmt, ei_x
 	(*fmt)++;
     for (;;) {
 	c = *(*fmt)++;
-	if (isdigit((int)c))
+	if (isdigit((unsigned char)c))
 	    continue;
 	else if (!dotp && (c == '.')) {
 	    dotp = 1;
@@ -304,7 +304,7 @@ static int ptuple(const char** fmt, unio
 	*fmt = p;
 	return size;
     }
-    while (isspace((int)*p))
+    while (isspace((unsigned char)*p))
 	++p;
     switch (*p++) {
     case '}':
@@ -342,7 +342,7 @@ static int plist(const char** fmt, union
 
     if (after == ']')
 	--p;
-    while (isspace((int)*p))
+    while (isspace((unsigned char)*p))
 	++p;
     switch (*p++) {
     case ']':
@@ -372,7 +372,7 @@ static int plist(const char** fmt, union
 	++size;
 	if (res >= 0) {
 	    if (after == '|') {
-	        while (isspace((int)*p))
+	        while (isspace((unsigned char)*p))
 		    ++p;
 		if (*p != ']')
 		    res = -1;
@@ -394,7 +394,7 @@ static int pmap(const char ** fmt, union
     const char * p = *fmt;
     int size = 0;
 
-    while (isspace(*p))
+    while (isspace((unsigned char)*p))
         ++p;
 
     if (*p == '}') {
@@ -406,7 +406,7 @@ static int pmap(const char ** fmt, union
         /* Key */
         if (eiformat(&p, args, x) < 0)
             return -1;
-        while (isspace(*p))
+        while (isspace((unsigned char)*p))
             ++p;
 
         if (!(p[0] == '=' && p[1] == '>')) {
@@ -417,7 +417,7 @@ static int pmap(const char ** fmt, union
         /* Value */
         if (eiformat(&p, args, x) < 0)
             return -1;
-        while (isspace(*p))
+        while (isspace((unsigned char)*p))
             ++p;
 
         ++size;
@@ -427,7 +427,7 @@ static int pmap(const char ** fmt, union
         }
         if (*p++ != ',')
             return -1;
-        while (isspace((int)*p))
+        while (isspace((unsigned char)*p))
             ++p;
     }
 }
