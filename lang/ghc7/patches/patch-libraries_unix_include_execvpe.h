$NetBSD: patch-libraries_unix_include_execvpe.h,v 1.2 2019/12/29 16:59:09 pho Exp $

Don't conflict with builtin execvpe(3).

--- libraries/unix/include/execvpe.h.orig	2015-07-23 22:04:56.000000000 +0000
+++ libraries/unix/include/execvpe.h
@@ -16,8 +16,6 @@ __hsunix_execvpe(const char *name, char 
 #if HAVE_EXECVPE
 # define _GNU_SOURCE
 # include <unistd.h>
-extern int
-execvpe(const char *name, char *const argv[], char *const envp[]);
 #else
 # define execvpe(name,argv,envp) __hsunix_execvpe(name,argv,envp)
 #endif
