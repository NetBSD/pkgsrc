$NetBSD: patch-panel-plugin_cmdspawn.c,v 1.5 2023/04/19 23:53:15 gutteridge Exp $

Fix SunOS build.

--- panel-plugin/cmdspawn.c.orig	2023-04-16 22:44:15.000000000 +0000
+++ panel-plugin/cmdspawn.c
@@ -24,6 +24,7 @@
 /* Posix-compliance to make sure that only the calling thread is
    duplicated, not the whole process (e.g Solaris) */
 
+#if !defined(__sun) || (!defined(_XOPEN_SOURCE) && (__STDC_VERSION__-0 < 199901L))
 #ifndef _POSIX_C_SOURCE
 #define _POSIX_C_SOURCE 199506L
 #endif
@@ -31,6 +32,7 @@
 #ifndef _XOPEN_SOURCE
 #define _XOPEN_SOURCE 500
 #endif
+#endif
 
 #ifdef HAVE_CONFIG_H
 #include <config.h>
@@ -58,12 +60,12 @@ char *genmon_Spawn (char **argv, int wai
  /* Spawn a command and capture its output from stdout or stderr */
  /* Return allocated string on success, otherwise NULL */
 {
-    enum { OUT, ERR, OUT_ERR };
+    enum { GENMON_OUT, GENMON_ERR, GENMON_OUT_ERR };
     enum { RD, WR, RD_WR };
 
-    int             aaiPipe[OUT_ERR][RD_WR];
+    int             aaiPipe[GENMON_OUT_ERR][RD_WR];
     pid_t           pid;
-    struct pollfd   aoPoll[OUT_ERR];
+    struct pollfd   aoPoll[GENMON_OUT_ERR];
     int             status;
     int             i, j, k;
     char           *str = NULL;
@@ -73,20 +75,20 @@ char *genmon_Spawn (char **argv, int wai
         fprintf (stderr, "Spawn() error: No parameters passed!\n");
         return (NULL);
     }
-    for (i = 0; i < OUT_ERR; i++)
+    for (i = 0; i < GENMON_OUT_ERR; i++)
         pipe (aaiPipe[i]);
 
     switch (pid = fork ()) 
     {
         case -1:
             perror ("fork()");
-            for (i = 0; i < OUT_ERR; i++)
+            for (i = 0; i < GENMON_OUT_ERR; i++)
                 for (j = 0; j < RD_WR; j++)
                     close (aaiPipe[i][j]);
             return (NULL);
         case 0:
             /* Redirect stdout/stderr to associated pipe's write-ends */
-            for (i = 0; i < OUT_ERR; i++) 
+            for (i = 0; i < GENMON_OUT_ERR; i++) 
             {
                 j = i + 1; // stdout/stderr file descriptor
                 k = dup2 (aaiPipe[i][WR], j);
@@ -102,7 +104,7 @@ char *genmon_Spawn (char **argv, int wai
         exit (-1);
     }
 
-    for (i = 0; i < OUT_ERR; i++)
+    for (i = 0; i < GENMON_OUT_ERR; i++)
         close (aaiPipe[i][WR]); /* close write end of pipes in parent */
 
     /* Wait for child completion */
@@ -116,17 +118,17 @@ char *genmon_Spawn (char **argv, int wai
         }
 
         /* Read stdout/stderr pipes' read-ends */
-        for (i = 0; i < OUT_ERR; i++) 
+        for (i = 0; i < GENMON_OUT_ERR; i++) 
         {
             aoPoll[i].fd = aaiPipe[i][RD];
             aoPoll[i].events = POLLIN;
             aoPoll[i].revents = 0;
         }
-        poll (aoPoll, OUT_ERR, ~0);
-        for (i = 0; i < OUT_ERR; i++)
+        poll (aoPoll, GENMON_OUT_ERR, ~0);
+        for (i = 0; i < GENMON_OUT_ERR; i++)
             if (aoPoll[i].revents & POLLIN)
                 break;
-        if (i == OUT_ERR)
+        if (i == GENMON_OUT_ERR)
             goto End;
 
         j = 0;
@@ -148,7 +150,7 @@ char *genmon_Spawn (char **argv, int wai
 
     End:
     /* Close read end of pipes */
-    for (i = 0; i < OUT_ERR; i++)
+    for (i = 0; i < GENMON_OUT_ERR; i++)
         close (aaiPipe[i][RD]);
 
     return (str);
