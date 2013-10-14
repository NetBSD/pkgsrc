$NetBSD: patch-src_ptlib_unix_svcproc.cxx,v 1.1 2013/10/14 14:36:12 joerg Exp $

--- src/ptlib/unix/svcproc.cxx.orig	2013-10-14 12:48:18.000000000 +0000
+++ src/ptlib/unix/svcproc.cxx
@@ -217,7 +217,8 @@ int PServiceProcess::InitialiseService()
     pid_t pid;
 
     {
-      ifstream pidfile(pidfilename);
+      const char *pidfilename2(pidfilename);
+      ifstream pidfile(pidfilename2);
       if (!pidfile.is_open()) {
         cout << "Could not open pid file: \"" << pidfilename << "\""
                 " - " << strerror(errno) << endl;
@@ -384,7 +385,8 @@ int PServiceProcess::InitialiseService()
   // Run as a daemon, ie fork
 
   if (!pidfilename) {
-    ifstream pidfile(pidfilename);
+    const char *pidfilename2(pidfilename);
+    ifstream pidfile(pidfilename2);
     if (pidfile.is_open()) {
       pid_t pid;
       pidfile >> pid;
@@ -412,7 +414,8 @@ int PServiceProcess::InitialiseService()
       cout << "Daemon started with pid " << pid << endl;
       if (!pidfilename) {
         // Write out the child pid to magic file in /var/run (at least for linux)
-        ofstream pidfile(pidfilename);
+        const char *pidfilename2(pidfilename);
+        ofstream pidfile(pidfilename2);
         if (pidfile.is_open())
           pidfile << pid;
         else
