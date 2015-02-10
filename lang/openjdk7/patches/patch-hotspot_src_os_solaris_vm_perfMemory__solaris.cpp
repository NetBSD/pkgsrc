$NetBSD: patch-hotspot_src_os_solaris_vm_perfMemory__solaris.cpp,v 1.1 2015/02/10 14:57:35 tnn Exp $

dirent->dd_fd is legacy, dirent->d_fd is POSIX, dirfd(dirent) is better.

--- hotspot/src/os/solaris/vm/perfMemory_solaris.cpp.orig	2015-01-26 15:21:44.000000000 +0000
+++ hotspot/src/os/solaris/vm/perfMemory_solaris.cpp
@@ -334,7 +334,7 @@ static DIR *open_directory_secure(const 
   }
 
   // Check to make sure fd and dirp are referencing the same file system object.
-  if (!is_same_fsobject(fd, dirp->dd_fd)) {
+  if (!is_same_fsobject(fd, dirfd(dirp))) {
     // The directory is not secure.
     os::close(fd);
     os::closedir(dirp);
@@ -366,7 +366,7 @@ static DIR *open_directory_secure_cwd(co
     // Directory doesn't exist or is insecure, so there is nothing to cleanup.
     return dirp;
   }
-  int fd = dirp->dd_fd;
+  int fd = dirfd(dirp);
 
   // Open a fd to the cwd and save it off.
   int result;
