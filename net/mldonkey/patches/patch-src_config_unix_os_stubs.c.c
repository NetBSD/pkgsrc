$NetBSD: patch-src_config_unix_os_stubs.c.c,v 1.1 2016/08/15 15:48:19 jaapb Exp $

Compile with OCaml 4.03
--- src/config/unix/os_stubs_c.c.orig	2010-07-16 13:56:35.000000000 +0000
+++ src/config/unix/os_stubs_c.c
@@ -66,7 +66,7 @@ ssize_t os_read(OS_FD fd, char *buf, siz
 
 void os_ftruncate(OS_FD fd, OFF_T len, /* bool */ int sparse)
 {
-  int64 cursize;
+  int64_t cursize;
   if(!fd) failwith("ftruncate32: file is closed");
   
   cursize = os_getfdsize(fd);
@@ -109,7 +109,7 @@ int os_getdtablesize()
 
 *******************************************************************/
 
-int64 os_getfdsize(OS_FD fd)
+int64_t os_getfdsize(OS_FD fd)
 {
   struct stat buf;
 
@@ -127,7 +127,7 @@ int64 os_getfdsize(OS_FD fd)
 
 *******************************************************************/
 
-int64 os_getfilesize(char *path)
+int64_t os_getfilesize(char *path)
 {
   struct stat buf;
 
