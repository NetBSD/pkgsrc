$NetBSD: patch-src_pal_src_configure.cmake,v 1.1 2016/06/30 12:16:24 kamil Exp $

Revert:                                                         

commit 5ac6af932fe2a3f4b285b6dcc79010caf807ea9d
Author: Mike McLaughlin <mikem@microsoft.com>
Date:   Fri May 27 20:03:32 2016 -0700

    Fix the named semaphore leak on OSX (and Linux) (#5269)

It broke NetBSD.

--- src/pal/src/configure.cmake.orig	2016-06-14 01:12:15.000000000 +0000
+++ src/pal/src/configure.cmake
@@ -665,85 +665,13 @@ int main(void) {
   char path[1024];
 #endif
 
-  sprintf(path, \"/proc/%u/ctl\", getpid());
-  fd = open(path, O_WRONLY);
+  sprintf(path, \"/proc/%u/$1\", getpid());
+  fd = open(path, $2);
   if (fd == -1) {
     exit(1);
   }
   exit(0);
 }" HAVE_PROCFS_CTL)
-set(CMAKE_REQUIRED_LIBRARIES)
-check_cxx_source_runs("
-#include <fcntl.h>
-#include <stdlib.h>
-#include <stdio.h>
-#include <unistd.h>
-
-int main(void) {
-  int fd;
-#ifdef PATH_MAX
-  char path[PATH_MAX];
-#elif defined(MAXPATHLEN)
-  char path[MAXPATHLEN];
-#else
-  char path[1024];
-#endif
-
-  sprintf(path, \"/proc/%u/maps\", getpid());
-  fd = open(path, O_RDONLY);
-  if (fd == -1) {
-    exit(1);
-  }
-  exit(0);
-}" HAVE_PROCFS_MAPS)
-set(CMAKE_REQUIRED_LIBRARIES)
-check_cxx_source_runs("
-#include <fcntl.h>
-#include <stdlib.h>
-#include <stdio.h>
-#include <unistd.h>
-
-int main(void) {
-  int fd;
-#ifdef PATH_MAX
-  char path[PATH_MAX];
-#elif defined(MAXPATHLEN)
-  char path[MAXPATHLEN];
-#else
-  char path[1024];
-#endif
-
-  sprintf(path, \"/proc/%u/stat\", getpid());
-  fd = open(path, O_RDONLY);
-  if (fd == -1) {
-    exit(1);
-  }
-  exit(0);
-}" HAVE_PROCFS_STAT)
-set(CMAKE_REQUIRED_LIBRARIES)
-check_cxx_source_runs("
-#include <fcntl.h>
-#include <stdlib.h>
-#include <stdio.h>
-#include <unistd.h>
-
-int main(void) {
-  int fd;
-#ifdef PATH_MAX
-  char path[PATH_MAX];
-#elif defined(MAXPATHLEN)
-  char path[MAXPATHLEN];
-#else
-  char path[1024];
-#endif
-
-  sprintf(path, \"/proc/%u/status\", getpid());
-  fd = open(path, O_RDONLY);
-  if (fd == -1) {
-    exit(1);
-  }
-  exit(0);
-}" HAVE_PROCFS_STATUS)
 set(CMAKE_REQUIRED_LIBRARIES m)
 check_cxx_source_runs("
 #include <math.h>
