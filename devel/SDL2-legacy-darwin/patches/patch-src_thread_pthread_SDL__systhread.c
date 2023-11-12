$NetBSD: patch-src_thread_pthread_SDL__systhread.c,v 1.1 2023/11/12 21:28:04 nia Exp $

NetBSD support. This was upstreamed ages ago.

--- src/thread/pthread/SDL_systhread.c.orig	2014-03-16 02:31:44.000000000 +0000
+++ src/thread/pthread/SDL_systhread.c
@@ -128,6 +128,8 @@ SDL_SYS_SetupThread(const char *name)
             ppthread_setname_np(pthread_self(), name);
             #endif
         }
+        #elif defined(__NetBSD__)
+            pthread_setname_np(pthread_self(), "%s", name);
         #elif HAVE_PTHREAD_SETNAME_NP
             pthread_setname_np(pthread_self(), name);
         #elif HAVE_PTHREAD_SET_NAME_NP
