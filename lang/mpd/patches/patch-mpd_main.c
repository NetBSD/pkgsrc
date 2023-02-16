$NetBSD: patch-mpd_main.c,v 1.1 2023/02/16 17:59:49 he Exp $

--- mpd/main.c.orig	2000-10-31 22:53:42.000000000 +0000
+++ mpd/main.c
@@ -11,7 +11,7 @@ static void dofile	PARAMS ((char *filena
 static int  concrete	PARAMS ((Nodeptr e));
 static void genmake	PARAMS ((Nodeptr e));
 static void gmake	PARAMS ((Nodeptr e, char *rtype, char *half));
-static void link	PARAMS ((char *files[]));
+static void my_link	PARAMS ((char *files[]));
 
 
 
@@ -42,6 +42,7 @@ static char *oname;			/* output file nam
 
 /*  main program  */
 
+int
 main (argc, argv)
 int  argc;
 char *argv[];
@@ -101,7 +102,7 @@ char *argv[];
     } else {
 	if (!option_q)
 	    fprintf (stderr, "linking:\n");
-	link (argv + optind);		/* exec mpdl to build executable file */
+	my_link (argv[optind]);		/* exec mpdl to build executable file */
 	/*NOTREACHED*/
     }
 }
@@ -348,13 +349,13 @@ char *dir, *fname;
 
 
 
-/*  link (files) -- run mpdl to link the components we have compiled
+/*  my_link (files) -- run mpdl to link the components we have compiled
  *
  *  "files" is portion of orig argv containing file names (including MPD files).
  */
 
 static void
-link (files)
+my_link (files)
 char *files[];
 {
     char path [MAX_PATH];
