$NetBSD: patch-Wnn_jutil_atof.c,v 1.2 2026/07/10 23:32:37 tsutsui Exp $

- Appease -Wincompatible-pointer-types that are fatal on gcc14 and later
- Remove unnecessary old style function declarations
- Use proper variadic arguments to print error messages

--- Wnn/jutil/atof.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/jutil/atof.c
@@ -121,6 +121,7 @@ static char *rcs_id = "$Id: atof.c,v 1.8
 #    include <strings.h>
 #  endif
 #endif /* STDC_HEADERS */
+#include <stdarg.h>
 #if HAVE_UNISTD_H
 #  include <unistd.h>
 #endif
@@ -289,15 +290,17 @@ static void set_id FRWNN_PARAMS((int, in
 static void pre_clear_jiritugo_v FRWNN_PARAMS((int));
 static void init FRWNN_PARAMS((int, char **));
 
-extern int wnn_loadhinsi (), create_file_header ();
-
 static void
-error_format (s, d1, d2, d3, d4, d5)
-     char *s;
-     int d1, d2, d3, d4, d5;
+error_format (const char *fmt, ...)
 {
+  va_list ap;
+
   fprintf (stderr, "Bad format near line %d \"%s\".\n", line_no, buf);
-  fprintf (stderr, s, d1, d2, d3, d4, d5);
+
+  va_start (ap, fmt);
+  vfprintf (stderr, fmt, ap);
+  va_end (ap);
+
   exit (1);
 }
 
@@ -522,8 +525,6 @@ read_attr ()
     }
 }
 
-extern char *wnn_get_hinsi_name ();
-
 static void
 read_id ()
 {
@@ -596,15 +597,18 @@ read_id ()
 
 static int
 sort_func_id (a, b)
-     char *a, *b;
+     const void *a, *b;
 {
-  return (strcmp (((struct id_struct *) a)->str, ((struct id_struct *) b)->str));
+  const struct id_struct *ia = a;
+  const struct id_struct *ib = b;
+
+  return (strcmp (ia->str, ib->str));
 }
 
 static void
 sort_id ()
 {
-  qsort ((char *) &id[0], id_num, sizeof (struct id_struct), sort_func_id);
+  qsort (&id[0], id_num, sizeof (struct id_struct), sort_func_id);
 }
 
 #ifdef nodef
@@ -741,17 +745,20 @@ bsch (c, st, end)
 #ifndef NO_FZK
 static int
 sort_func_fz (a, b)
-     char *a, *b;
+     const void *a, *b;
 {
   int c;
+  /* XXX may cause -Wcast-qual but wnn_Strcmp() should be fixed to take const */
+  struct fuzokugo *fa = (struct fuzokugo *)a;
+  struct fuzokugo *fb = (struct fuzokugo *)b;
 
-  if ((c = wnn_Strcmp (((struct fuzokugo *) a)->y, ((struct fuzokugo *) b)->y)) == 0)
+  if ((c = wnn_Strcmp (fa->y, fb->y)) == 0)
     {
-      if (((struct fuzokugo *) a)->hinsi > ((struct fuzokugo *) b)->hinsi)
+      if (fa->hinsi > fb->hinsi)
         {
           return (1);
         }
-      else if (((struct fuzokugo *) a)->hinsi < ((struct fuzokugo *) b)->hinsi)
+      else if (fa->hinsi < fb->hinsi)
         {
           return (-1);
         }
@@ -763,7 +770,7 @@ sort_func_fz (a, b)
 static void
 sort ()
 {
-  qsort ((char *) &fz[0], fz_num, sizeof (struct fuzokugo), sort_func_fz);
+  qsort (&fz[0], fz_num, sizeof (struct fuzokugo), sort_func_fz);
 }
 #endif /* NO_FZK */
 
