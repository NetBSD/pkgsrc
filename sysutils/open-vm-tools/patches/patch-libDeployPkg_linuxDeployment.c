$NetBSD: patch-libDeployPkg_linuxDeployment.c,v 1.2 2021/12/07 18:25:46 adam Exp $

--- libDeployPkg/linuxDeployment.c.orig	2021-08-31 09:03:13.000000000 +0000
+++ libDeployPkg/linuxDeployment.c
@@ -1583,7 +1583,7 @@ ExtractZipPackage(const char* pkgName,
 {
    ProcessHandle h;
    char* args[32];
-   const char* stderr;
+   const char* mystderr;
 
    int pkgFd, zipFd;
    char zipName[1024];
@@ -1644,9 +1644,9 @@ ExtractZipPackage(const char* pkgName,
    sLog(log_info, "unzip output: '%s'.", Process_GetStdout(h));
 
    // Assume zip failed if it wrote to stderr
-   stderr = Process_GetStderr(h);
-   if (strlen(stderr) > 0) {
-      sLog(log_error, "Package unzip failed: '%s'.", stderr);
+   mystderr = Process_GetStderr(h);
+   if (strlen(mystderr) > 0) {
+      sLog(log_error, "Package unzip failed: '%s'.", mystderr);
       ret = FALSE;
    }
 
