$NetBSD: patch-panel-plugin_cmdspawn.c,v 1.1 2015/04/21 08:56:40 jperkin Exp $

Fix SunOS build.
--- panel-plugin/cmdspawn.c.orig	2012-05-10 02:09:21.000000000 +0000
+++ panel-plugin/cmdspawn.c
@@ -12,7 +12,7 @@
  *  version 2.1 of the License, or (at your option) any later version.
 
  *  This library is distributed in the hope that it will be useful,
- *  but WITHOUT ANY WARRANTY; without even the implied warranty of
+ *  but WITHGENMON_OUT ANY WARRANTY; without even the implied warranty of
  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  *  Lesser General Public License for more details.
 
@@ -59,12 +59,12 @@ char *genmon_Spawn (char **argv, int wai
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
@@ -73,19 +73,19 @@ char *genmon_Spawn (char **argv, int wai
         fprintf (stderr, "Spawn() error: No parameters passed!\n");
         return (NULL);
     }
-    for (i = 0; i < OUT_ERR; i++)
+    for (i = 0; i < GENMON_OUT_ERR; i++)
         pipe (aaiPipe[i]);
     switch (pid = fork ()) {
         case -1:
             perror ("fork()");
-            for (i = 0; i < OUT_ERR; i++)
+            for (i = 0; i < GENMON_OUT_ERR; i++)
                 for (j = 0; j < RD_WR; j++)
                     close (aaiPipe[i][j]);
             return (NULL);
         case 0:
             close(0); /* stdin is not used in child */
             /* Redirect stdout/stderr to associated pipe's write-ends */
-            for (i = 0; i < OUT_ERR; i++) {
+            for (i = 0; i < GENMON_OUT_ERR; i++) {
                 j = i + 1; // stdout/stderr file descriptor
                 close (j);
                 k = dup2 (aaiPipe[i][WR], j);
@@ -100,7 +100,7 @@ char *genmon_Spawn (char **argv, int wai
         exit (-1);
     }
 
-    for (i = 0; i < OUT_ERR; i++)
+    for (i = 0; i < GENMON_OUT_ERR; i++)
         close (aaiPipe[i][WR]); /* close write end of pipes in parent */
 
     /* Wait for child completion */
@@ -113,16 +113,16 @@ char *genmon_Spawn (char **argv, int wai
         }
 
         /* Read stdout/stderr pipes' read-ends */
-        for (i = 0; i < OUT_ERR; i++) {
+        for (i = 0; i < GENMON_OUT_ERR; i++) {
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
@@ -143,7 +143,7 @@ char *genmon_Spawn (char **argv, int wai
 
     End:
     /* Close read end of pipes */
-    for (i = 0; i < OUT_ERR; i++)
+    for (i = 0; i < GENMON_OUT_ERR; i++)
         close (aaiPipe[i][RD]);
 
     return (str);
