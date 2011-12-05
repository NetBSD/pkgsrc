$NetBSD: patch-gdb_gdbserver_gdbreplay.c,v 1.1 2011/12/05 19:34:41 sbd Exp $

alloca(3) is not avalible with glibc on linux if -fno-builtin is used.

--- gdb/gdbserver/gdbreplay.c.orig	2002-07-09 17:38:58.000000000 +0000
+++ gdb/gdbserver/gdbreplay.c
@@ -62,12 +62,19 @@ perror_with_name (char *string)
   char *combined;
 
   err = (errno < sys_nerr) ? sys_errlist[errno] : "unknown error";
+#ifdef __linux__
+  combined = (char *) malloc (strlen (err) + strlen (string) + 3);
+#else
   combined = (char *) alloca (strlen (err) + strlen (string) + 3);
+#endif
   strcpy (combined, string);
   strcat (combined, ": ");
   strcat (combined, err);
   fprintf (stderr, "\n%s.\n", combined);
   fflush (stderr);
+#ifdef __linux__
+  free(combined);
+#endif
   exit (1);
 }
 
