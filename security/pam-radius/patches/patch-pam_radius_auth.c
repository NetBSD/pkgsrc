--- pam_radius_auth.c	2007-03-26 04:36:13.000000000 -0500
+++ pam_radius_auth.c	2012-11-30 15:53:29.000000000 -0600
@@ -58,6 +58,5 @@
 #include <errno.h>
+#include <sys/types.h>
 
-#ifdef sun
 #include <security/pam_appl.h>
-#endif
 #include <security/pam_modules.h>
@@ -184,3 +183,3 @@
     while(*ip_str != '.' && *ip_str != '\0' && count < 4) {
-      if(!isdigit(*ip_str)) {
+      if(!isdigit((unsigned char)*ip_str)) {
 	return((UINT4)0);
@@ -220,3 +219,3 @@
       digit_count = 0;
-    } else if(!isdigit(*addr)) {
+    } else if(!isdigit((unsigned char)*addr)) {
       dot_count = 5;
@@ -276,3 +275,3 @@
   if (!server->port) {
-    if (p && isdigit(*p)) {	/* the port looks like it's a number */
+    if (p && isdigit((unsigned char)*p)) {	/* the port looks like it's a number */
       unsigned int i = atoi(p) & 0xffff;
@@ -768,3 +767,4 @@
 {
-  int salen, total_length;
+  socklen_t salen;
+  int total_length;
   fd_set set;
@@ -1101,3 +1101,3 @@
     if (!strcmp("root", user)) {
-      user = userinfo;
+      user = (char *)userinfo;
       DPRINT(LOG_DEBUG, "Username now %s from ruser", user);
