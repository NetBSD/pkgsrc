$NetBSD: patch-libDeployPkg_linuxDeployment.c,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- libDeployPkg/linuxDeployment.c.orig	2016-02-16 20:06:47.000000000 +0000
+++ libDeployPkg/linuxDeployment.c
@@ -1058,7 +1058,7 @@ ExtractZipPackage(const char* pkgName,
 {
    ProcessHandle h;
    char* args[32];
-   const char* stderr;
+   const char* mystderr;
 
    int pkgFd, zipFd;
    char zipName[1024];
@@ -1106,9 +1106,9 @@ ExtractZipPackage(const char* pkgName,
    sLog(log_info, "unzip output: %s\n", Process_GetStdout(h));
 
    // Assume zip failed if it wrote to stderr
-   stderr = Process_GetStderr(h);
-   if (strlen(stderr) > 0) {
-      sLog(log_error, "Package unzip failed: %s\n", stderr);
+   mystderr = Process_GetStderr(h);
+   if (strlen(mystderr) > 0) {
+      sLog(log_error, "Package unzip failed: %s\n", mystderr);
       ret = FALSE;
    }
 
