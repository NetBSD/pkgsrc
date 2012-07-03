$NetBSD: patch-bible.c,v 1.1 2012/07/03 17:39:53 joerg Exp $

--- bible.c.orig	1994-12-12 19:30:47.000000000 +0000
+++ bible.c
@@ -136,2 +136,3 @@
 
+#include <string.h>
 #include <ctype.h>
@@ -153,2 +154,3 @@ static char rcs_ident[]="@(#)$Header: bi
 
+void cmd_list(void);
 
@@ -195,3 +197,4 @@ char help_text[]="\n\
 
-
+tsl_scan_concordance( char *target, ref_t *sbuf, ref_t range_start, ref_t range_end );
+brl_init( char *dfname, char *dfpath, int memlimit );
 
@@ -248,3 +251,3 @@ ref_t *buf;
 
-
+void
 cmd_ANDconcordance( word )
@@ -305,3 +308,3 @@ char *word;
 
-
+void
 cmd_ORconcordance( word )
@@ -369,3 +372,3 @@ char *word;
 
-
+void
 cmd_concordance( word )
@@ -424,3 +427,3 @@ cmd_help()
 
-
+void
 cmd_inrange( range )
@@ -493,3 +496,3 @@ char *range;
 
-
+void
 cmd_list()
@@ -594,3 +597,3 @@ int verbose;
 
-
+void
 cmd_view()
