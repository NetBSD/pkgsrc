$NetBSD: patch-kmail_editorwatcher.cpp,v 1.1 2011/02/17 09:37:13 markd Exp $

--- kmail/editorwatcher.cpp.orig	2008-02-13 09:39:37.000000000 +0000
+++ kmail/editorwatcher.cpp
@@ -37,25 +37,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/syscall.h>
-#include <linux/types.h>
-// Linux kernel headers are documented to not compile
-#define _S390_BITOPS_H
-#include <linux/inotify.h>
-
-static inline int inotify_init (void)
-{
-  return syscall (__NR_inotify_init);
-}
-
-static inline int inotify_add_watch (int fd, const char *name, __u32 mask)
-{
-  return syscall (__NR_inotify_add_watch, fd, name, mask);
-}
-
-static inline int inotify_rm_watch (int fd, __u32 wd)
-{
-  return syscall (__NR_inotify_rm_watch, fd, wd);
-}
+#include <sys/inotify.h>
 #endif
 
 using namespace KMail;
