$NetBSD: patch-manual.c,v 1.1 2023/03/01 23:48:00 vins Exp $

Pull patches from Debian.

--- manual.c.orig	1994-05-19 02:01:09.000000000 +0000
+++ manual.c
@@ -1,5 +1,5 @@
-#ifndef lint
-static char rcsid[] = "manual.c,v 2.0 1994/05/19 02:01:09 dan Exp";
+#if 0
+static char rcsid[] __attribute__((unused)) = "manual.c,v 2.0 1994/05/19 02:01:09 dan Exp";
 #endif
 
 /*
@@ -134,14 +134,14 @@ void show_manual_page (Widget parent)
 	if (value == NULL) {	/* system calls in popen failed */
 	    char buffer[1024];
 
-	    (void) sprintf (buffer, "System routine \"popen\" failed executing\nthis command (resource \"manCommand\"):\n\n\"%s\"", cmd);
+	    (void) snprintf (buffer, sizeof (buffer), "System routine \"popen\" failed executing\nthis command (resource \"manCommand\"):\n\n\"%s\"", cmd);
 	    xms = XmStringCreateLtoR (buffer, XmSTRING_DEFAULT_CHARSET);
 	    iserror = 1;
 	}
 	else if (value[0] == '\0') { /* command produced no output */
 	    char buffer[1024];
 
-	    (void) sprintf (buffer, "Shell command (resource \"manCommand\"):\n\n\"%s\"\n\nproduced no output", cmd);
+	    (void) snprintf (buffer, sizeof (buffer), "Shell command (resource \"manCommand\"):\n\n\"%s\"\n\nproduced no output", cmd);
 	    xms = XmStringCreateLtoR (buffer, XmSTRING_DEFAULT_CHARSET);
 	    iserror = 1;
 	}
@@ -151,7 +151,7 @@ void show_manual_page (Widget parent)
 
 	    if ((tmp = strrchr (value, '\n')) != NULL)
 		*tmp = '\0';
-	    (void) sprintf (buffer, "Shell command (resource \"manCommand\"):\n\n    \"%s\"\n\nproduced this output: \n\n    \"%s\"", cmd, value);
+	    (void) snprintf (buffer, sizeof (buffer), "Shell command (resource \"manCommand\"):\n\n    \"%s\"\n\nproduced this output: \n\n    \"%s\"", cmd, value);
 	    xms = XmStringCreateLtoR (buffer, XmSTRING_DEFAULT_CHARSET);
 	    iserror = 1;
 	}
