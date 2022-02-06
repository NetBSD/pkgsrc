$NetBSD: patch-libraries_unix_include_execvpe.h,v 1.1 2022/02/06 05:36:16 pho Exp $

Don't conflict with builtin execvpe(3).

Already fixed in the upstream (unix-2.8.0.0).

--- libraries/unix/include/execvpe.h.orig	2016-02-04 16:16:38.000000000 +0000
+++ libraries/unix/include/execvpe.h
@@ -15,8 +15,10 @@ __hsunix_execvpe(const char *name, char 
 #include "HsUnixConfig.h"
 #if HAVE_EXECVPE
 # include <unistd.h>
+# if !defined(execvpe) && !HAVE_DECL_EXECVPE
 extern int
 execvpe(const char *name, char *const argv[], char *const envp[]);
+# endif
 #else
 # define execvpe(name,argv,envp) __hsunix_execvpe(name,argv,envp)
 #endif
