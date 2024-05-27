$NetBSD: patch-erts_emulator_sys_unix_sys.c,v 1.3 2024/05/27 19:07:50 riastradh Exp $

Fix ctype(3) misuse.

--- erts/emulator/sys/unix/sys.c.orig	2024-03-06 15:30:18.000000000 +0000
+++ erts/emulator/sys/unix/sys.c
@@ -717,7 +717,7 @@ get_number(char **str_ptr)
     char* s = *str_ptr;		/* Pointer to beginning of string. */
     char* dot;			/* Pointer to dot in string or NULL. */
 
-    if (!isdigit((int) *s))
+    if (!isdigit((unsigned char) *s))
 	return 0;
     if ((dot = strchr(s, '.')) == NULL) {
 	*str_ptr = s+strlen(s);
@@ -735,8 +735,8 @@ void os_flavor(char* namebuf, unsigned s
 
     (void) uname(&uts);
     for (s = uts.sysname; *s; s++) {
-	if (isupper((int) *s)) {
-	    *s = tolower((int) *s);
+	if (isupper((unsigned char) *s)) {
+	    *s = tolower((unsigned char) *s);
 	}
     }
     strcpy(namebuf, uts.sysname);
