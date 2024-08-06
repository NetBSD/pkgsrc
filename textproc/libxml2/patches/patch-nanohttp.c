$NetBSD: patch-nanohttp.c,v 1.1 2024/08/06 18:48:42 riastradh Exp $

Avoid ctype(3) abuse.

--- nanohttp.c.orig	2024-06-12 10:56:14.000000000 +0000
+++ nanohttp.c
@@ -1274,7 +1274,7 @@ xmlNanoHTTPHostnameMatch(const char *pat
 
     for (; idx_pattern >= 0 && idx_hostname >= 0; 
            --idx_pattern, --idx_hostname) {
-	if (tolower(pattern_start[idx_pattern]) != tolower(hostname[idx_hostname]))
+	if (tolower((unsigned char)pattern_start[idx_pattern]) != tolower((unsigned char)hostname[idx_hostname]))
 	    break;
     }
 
@@ -1306,7 +1306,7 @@ xmlNanoHTTPBypassProxy(const char *hostn
     env = cpy;
 
     /* The remainder of the function is basically a tokenizing: */
-    while (isspace(*env))
+    while (isspace((unsigned char)*env))
     	++env;
     if (*env == '\0') {
     	xmlFree(cpy);
@@ -1327,7 +1327,7 @@ xmlNanoHTTPBypassProxy(const char *hostn
 	    return 1;
 	}
 
-	while (isspace(*env))
+	while (isspace((unsigned char)*env))
 	    ++env;
 	p = env;
     }
