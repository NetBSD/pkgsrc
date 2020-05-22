$NetBSD: patch-dlls_ntdll_thread.c,v 1.1 2020/05/22 17:44:42 nia Exp $

Fix Unhandled page fault on write access owing to pthread_attr_setstack(3)
setting guard on NetBSD 8.0 and newer. This patch has been submitted to Wine
and can be removed to once upstreamed.

--- dlls/ntdll/thread.c.orig	2019-03-15 20:18:31.000000000 +0000
+++ dlls/ntdll/thread.c
@@ -526,6 +526,7 @@ NTSTATUS WINAPI RtlCreateUserThread( HAN
     pthread_attr_init( &attr );
     pthread_attr_setstack( &attr, teb->DeallocationStack,
                          (char *)teb->Tib.StackBase + extra_stack - (char *)teb->DeallocationStack );
+    pthread_attr_setguardsize(&attr, 0);
     pthread_attr_setscope( &attr, PTHREAD_SCOPE_SYSTEM ); /* force creating a kernel thread */
     interlocked_xchg_add( &nb_threads, 1 );
     if (pthread_create( &pthread_id, &attr, (void * (*)(void *))start_thread, info ))
