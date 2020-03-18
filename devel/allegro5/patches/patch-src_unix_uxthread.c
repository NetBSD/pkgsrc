$NetBSD: patch-src_unix_uxthread.c,v 1.1 2020/03/18 01:23:01 nia Exp $

Not just absent in GNU (NetBSD, too...)

--- src/unix/uxthread.c.orig	2019-08-26 12:52:05.000000000 +0000
+++ src/unix/uxthread.c
@@ -72,9 +72,6 @@ void _al_thread_create(_AL_THREAD *threa
 
 void _al_thread_create_with_stacksize(_AL_THREAD* thread, void (*proc)(_AL_THREAD*, void*), void *arg, size_t stacksize) 
 {
-#ifndef __GNU__
-   ASSERT(stacksize >= PTHREAD_STACK_MIN);
-#endif
    ASSERT(thread);
    ASSERT(proc);
    {
