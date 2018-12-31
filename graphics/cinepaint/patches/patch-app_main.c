$NetBSD: patch-app_main.c,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- app/main.c.orig	2008-02-28 09:50:15.000000000 +0000
+++ app/main.c
@@ -55,7 +55,6 @@ extern int _fmode;
 
 #ifdef HAVE_OY
 #include <oyranos/oyranos.h>
-#include <oyranos/oyranos_config.h>
 #include <oyranos/oyranos_version.h>
 char *oyranos_temp_path = NULL;
 void *myAlloc(size_t n) { return calloc(sizeof(char), n); }
@@ -448,7 +447,8 @@ int main (int argc, char **argv)
 #ifdef WIN32
 
 #else
-# ifndef DEBUG_
+  if (use_debug_handler)
+  {
   /* Handle some signals */
   signal (SIGHUP, on_signal);
   signal (SIGINT, on_signal);
@@ -466,7 +466,7 @@ int main (int argc, char **argv)
   /* Handle shmem reload */
   signal( SIGUSR2, on_sig_refresh);
 # endif
-# endif /* DEBUG */
+  }
 #endif
   /* Keep the command line arguments--for use in gimp_init */
   gimp_argc = argc - 1;
