$NetBSD: patch-cgi_statuswml.c,v 1.1 2014/04/02 10:22:37 he Exp $

Fix off-by-one vulnerabilities, ref. http://secunia.com/advisories/55976/

--- cgi/statuswml.c.orig	2011-08-17 07:36:27.000000000 +0000
+++ cgi/statuswml.c
@@ -235,8 +235,13 @@ int process_cgivars(void) {
 
 	for(x = 0; variables[x] != NULL; x++) {
 
+		/* do some basic length checking on the variable identifier to prevent buffer overflows */
+		if(strlen(variables[x]) >= MAX_INPUT_BUFFER - 1) {
+			continue;
+			}
+
 		/* we found the hostgroup argument */
-		if(!strcmp(variables[x], "hostgroup")) {
+		else if(!strcmp(variables[x], "hostgroup")) {
 			display_type = DISPLAY_HOSTGROUP;
 			x++;
 			if(variables[x] == NULL) {
