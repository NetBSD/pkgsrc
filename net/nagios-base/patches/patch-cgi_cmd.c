$NetBSD: patch-cgi_cmd.c,v 1.2 2014/04/15 10:16:47 obache Exp $

* Fix off-by-one vulnerabilities, ref. http://secunia.com/advisories/55976/
* Fix CVE-2014-1878

--- cgi/cmd.c.orig	2013-08-30 17:46:14.000000000 +0000
+++ cgi/cmd.c
@@ -321,7 +321,6 @@ int process_cgivars(void) {
 
 		/* do some basic length checking on the variable identifier to prevent buffer overflows */
 		if(strlen(variables[x]) >= MAX_INPUT_BUFFER - 1) {
-			x++;
 			continue;
 			}
 
@@ -1923,14 +1922,14 @@ static int cmd_submitf(int id, const cha
 		return ERROR;
 
 	len = snprintf(cmd, sizeof(cmd) - 1, "[%lu] %s;", time(NULL), command);
-	if(len < 0)
+	if(len < 0 || len >= sizeof(cmd))
 		return ERROR;
 
 	if(fmt) {
 		va_start(ap, fmt);
 		len2 = vsnprintf(&cmd[len], sizeof(cmd) - len - 1, fmt, ap);
 		va_end(ap);
-		if(len2 < 0)
+		if(len2 < 0 || len2 >= sizeof(cmd) - len)
 			return ERROR;
 		}
 
