$NetBSD: patch-os.c,v 1.2 2025/02/15 23:06:05 wiz Exp $

Add missing header for ioctl().
Use path to help file.

--- os.c.orig	2025-02-15 23:03:15.290131323 +0000
+++ os.c
@@ -25,6 +25,8 @@
 
 #include "edt.h"
 
+#include <sys/ioctl.h>
+
 #define JOURNAL_FLUSH_INTERVAL (15)
 
 static int screenmode = 0;
@@ -265,6 +267,14 @@ void os_initialization (void)
     abort ();
   }
 
+#ifdef EDT_HELPFILE
+  help_name = malloc(strlen(EDT_HELPFILE) + 1);
+  if (help_name == NULL) {
+    fprintf (stderr, "out of memory\n");
+    exit (1); 
+  }
+  strcpy(help_name, EDT_HELPFILE);
+#else
   /* Try to find help file - same directory as executable */
 
   pathstring = NULL;						/* haven't allocated a string yet */
@@ -303,6 +313,7 @@ void os_initialization (void)
   strcat (help_name, ".hlp");					/* append .hlp for the help file name */
 
   if (pathstring != NULL) string_delete (pathstring);		/* free off string if we allocated one */
+#endif
 
 #endif
 
