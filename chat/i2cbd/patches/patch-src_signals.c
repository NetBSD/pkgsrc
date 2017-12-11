$NetBSD: patch-src_signals.c,v 1.1 2017/12/11 07:54:42 spz Exp $

remember bricks
fix array overrun

--- src/signals.c.orig	2006-05-11 03:44:53.000000000 +0000
+++ src/signals.c
@@ -54,7 +54,7 @@ icbdump (int sig)
 
     fprintf (dump, "%d\n", highestfd);
 
-    for (i = 0; i <= MAX_REAL_USERS; i++)
+    for (i = 0; i < MAX_REAL_USERS; i++)
 	fprintf (dump, "%d\n", S_kill[i]);
 
     for (i = 0; i < MAX_USERS; i++)
@@ -168,6 +168,9 @@ icbdump (int sig)
 			fprintf(dump, "%sX\n", nlget(g_tab[i].nr_talk));
     }
 
+    for (i = 0; i < MAX_REAL_USERS; i++)
+	fprintf (dump, "%d\n", S_bricks[i]);
+
     fclose(dump);
 }
 
@@ -198,7 +201,7 @@ icbload (int sig)
     }
 
     fscanf (dump, "%d\n", &highestfd);
-    for (i = 0; i <= MAX_REAL_USERS; i++) {
+    for (i = 0; i < MAX_REAL_USERS; i++) {
 	fscanf (dump, "%ld\n", &k);
 	S_kill[i] = (int)k;
     }
@@ -368,5 +371,11 @@ icbload (int sig)
 	}
     }
 
+    for (i = 0; i < MAX_REAL_USERS; i++) {
+	fscanf (dump, "%ld\n", &k);
+	S_bricks[i] = (int)k;
+    }
+
+
     fclose(dump);
 }
