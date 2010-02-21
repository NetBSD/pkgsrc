$NetBSD: patch-cf,v 1.2 2010/02/21 12:26:47 wiz Exp $

When running terminfo but compiled for termcap, we cannot assume
that we actually have anything useable in termcap_term_buffer so just
use the terminfo fixed size defined ealier.

--- src/term.c	2010-01-14 21:25:59.000000000 +0000
+++ src/term.c	2010-01-14 21:26:27.000000000 +0000
@@ -1647,11 +1647,7 @@
 	     terminal_type);
 #endif
     }
-#ifdef TERMINFO
   area = (char *) xmalloc (2044);
-#else
-  area = (char *) xmalloc (strlen (buffer));
-#endif /* not TERMINFO */
   if (area == 0)
     abort ();
 
