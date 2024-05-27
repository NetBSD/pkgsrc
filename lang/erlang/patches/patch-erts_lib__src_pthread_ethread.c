$NetBSD: patch-erts_lib__src_pthread_ethread.c,v 1.1 2024/05/27 19:07:50 riastradh Exp $

Fix ctype(3) misuse.

--- erts/lib_src/pthread/ethread.c.orig	2024-03-06 15:30:18.000000000 +0000
+++ erts/lib_src/pthread/ethread.c
@@ -765,19 +765,19 @@ init_get_monotonic_time(void)
     (void) uname(&uts);
     
     for (c = uts.sysname; *c; c++) {
-	if (isupper((int) *c))
-	    *c = tolower((int) *c);
+	if (isupper((unsigned char) *c))
+	    *c = tolower((unsigned char) *c);
     }
 
     c = uts.release;
     for (i = 0; i < sizeof(vsn)/sizeof(int); i++) {
-	if (!isdigit((int) *c))
+	if (!isdigit((unsigned char) *c))
 	    vsn[i] = 0;
 	else {
 	    char *c2 = c;
 	    do {
 		c2++;
-	    } while (isdigit((int) *c2));
+	    } while (isdigit((unsigned char) *c2));
 	    *c2 = '\0';
 	    vsn[i] = atoi(c);
 	    c = c2;
