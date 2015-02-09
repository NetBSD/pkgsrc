$NetBSD: patch-src_thread_pthread_SDL__systhread.c,v 1.1 2015/02/09 08:27:07 snj Exp $

Handle NetBSD's pthread_setname_np.

--- src/thread/pthread/SDL_systhread.c.orig	2014-03-15 19:31:44.000000000 -0700
+++ src/thread/pthread/SDL_systhread.c	2015-02-09 00:17:52.000000000 -0800
@@ -129,7 +129,11 @@ SDL_SYS_SetupThread(const char *name)
             #endif
         }
         #elif HAVE_PTHREAD_SETNAME_NP
+            #if defined(__NETBSD__)
+            pthread_setname_np(pthread_self(), "%s", name);        
+            #else
             pthread_setname_np(pthread_self(), name);
+            #endif
         #elif HAVE_PTHREAD_SET_NAME_NP
             pthread_set_name_np(pthread_self(), name);
         #elif defined(__HAIKU__)
