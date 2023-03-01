$NetBSD: patch-misc.c,v 1.1 2023/03/01 23:48:00 vins Exp $

Pull patches from Debian.

--- misc.c.orig	1994-05-19 02:01:19.000000000 +0000
+++ misc.c
@@ -1,9 +1,10 @@
-#ifndef lint
-static char rcsid[] = "misc.c,v 2.0 1994/05/19 02:01:19 dan Exp";
+#if 0
+static char rcsid[] __attribute__((unused)) = "misc.c,v 2.0 1994/05/19 02:01:19 dan Exp";
 #endif
 
 /*
  * Copyright (c) 1994    Daniel Williams
+ * Copyright (c) 2003    Erik de Castro Lopo
  * 
  * The X Consortium, and any party obtaining a copy of these files from
  * the X Consortium, directly or indirectly, is granted, free of charge,
@@ -33,6 +34,8 @@ static char rcsid[] = "misc.c,v 2.0 1994
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
+#include <errno.h>
 
 #include <Xm/Xm.h>
 #include <X11/cursorfont.h>
@@ -40,6 +43,7 @@ static char rcsid[] = "misc.c,v 2.0 1994
 #include <Xm/SashP.h>
 
 #include "mgdiff.h"
+#include "externs.h"
 
 int max (int i, int j)
 {
@@ -52,14 +56,49 @@ int min (int i, int j)
 }
 
 /* 
- * copy a stream up to the EOF to a file
+ * Create a temporary file and write all text from the input stream (up to 
+ * the EOF) to the file.
+ * The name of the temp file is returned to the user in *name.
  */
-int copy_to_file (FILE *fin, char *name)
+int copy_to_tempfile (FILE *fin, char *name, size_t name_len)
 {
-    FILE *fout;
-
-    if ((fout = fopen (name, "a")) == NULL)
-	return (0);
+    FILE *fout ;
+    int fd ;
+#if !(defined __GLIBC__ && __GLIBC__ >= 2)
+    /*
+    **	Seed the random() generator. This does not need to be super
+    **	randomised as the while loop below will be run until a file
+    **	is opened.
+    */
+    srandom (getpid () + getppid () + time (NULL)) ;
+
+    while (1) {
+	snprintf (name, name_len, "/tmp/mgdiff-%#lx", random()) ;
+	if ((fd = open (name, O_CREAT | O_EXCL | O_RDWR, 0600)) < 0) {
+	    if (errno == EEXIST)
+		continue ;
+	    return 1 ;
+	}
+
+	if ((fout = fdopen (fd, "r+")) == NULL) {
+	    close (fd) ;
+	    return 1 ;
+	}
+	
+	break ;
+    }
+#else
+    snprintf (name, name_len, "/tmp/mgdif-XXXXXX");
+    if ((fd = mkstemp(name)) < 0) {
+	perror("mkstemp");
+	exit(1);
+    }
+    if ((fout = fdopen (fd, "r+")) == NULL) {
+	close (fd);
+	perror("fdopen");
+	exit(1);
+    }
+#endif
     while (!feof (fin)) {
 	char buffer[BUFSIZ];
 	int nitems;
@@ -68,10 +107,12 @@ int copy_to_file (FILE *fin, char *name)
 	if (fwrite (buffer, 1, nitems, fout) != nitems)
 	    break;
     }
+
     if (ferror (fin) || ferror (fout)) {
 	(void) fclose (fout);
 	return (1);
     }
+
     return ((fclose (fout) == 0));
 }
 
