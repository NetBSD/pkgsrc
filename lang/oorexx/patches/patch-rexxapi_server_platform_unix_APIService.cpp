$NetBSD: patch-rexxapi_server_platform_unix_APIService.cpp,v 1.2 2026/08/02 06:39:27 ryoon Exp $

A combination of changes to make it possible to terminate the rxapi process
which is auto-started:
- use the lock file as a pid-file,
- add a command line argument "stop" that sends SIGTERM to the pid from the
  pidfile,
- let the signal handler continue running so that cleanup code can run.
https://sourceforge.net/p/oorexx/bugs/1993/

--- rexxapi/server/platform/unix/APIService.cpp.orig	2025-05-03 09:08:48.000000000 +0000
+++ rexxapi/server/platform/unix/APIService.cpp
@@ -65,7 +65,8 @@ void Stop(int signo)
 {
     apiServer.terminateServer();     // shut everything down
 
-    exit(1);
+    /* Do not exit here, but let the main loop finish and the epilog code clean
+     * up the lock file. */
 }
 
 
@@ -123,11 +124,17 @@ int main(int argc, char *argv[])
  */
 int main(int argc, char *argv[])
 {
+    int stopflag = 0;
+
     bool dryrun = false; // handy (undocumented) test option
     if (argc > 1)
     {
-        dryrun = strcmp(argv[1], "--dryrun") == 0;
-        printf(dryrun ? "rxapi: dryrun\n" : "rxapi: no args allowed\n");
+        if (strcmp(argv[1], "stop") == 0) {
+            stopflag = 1;
+        } else {
+            dryrun = strcmp(argv[1], "--dryrun") == 0;
+            printf(dryrun ? "rxapi: dryrun\n" : "rxapi: no args allowed\n");
+        }
     }
 
     // neither our lock file nor our socket should give access to group or world
@@ -159,10 +166,30 @@ int main(int argc, char *argv[])
     int fd;
     if ((fd = acquireLock(lockFileName)) == -1)
     {
+	if (stopflag) {
+	    FILE *f = fopen(lockFileName, "r");
+	    long pid = 0;
+
+	    if (f && fscanf(f, "%ld", &pid) == 1 && (pid_t)pid > 1 &&
+		kill((pid_t)pid, SIGTERM) == 0) {
+		exit(0);
+	    }
+	    exit(1);
+	}
         printf("rxapi: lockfile is locked by another rxapi instance; exiting\n");
         return EACCES;
     }
+    if (stopflag) {
+	printf("rxapi: no server is running.\n");
+	releaseLock(lockFileName, fd);   // release the exclusive lock
+	exit(1);
+    }
     printf("rxapi: lockfile lock acquired\n");
+    {
+	char pidstring[32];
+	sprintf(pidstring, "%ld\n", (long)getpid());
+	write(fd, pidstring, strlen(pidstring));
+    }
 
     try
     {
