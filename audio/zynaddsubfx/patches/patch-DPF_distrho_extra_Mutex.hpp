$NetBSD: patch-DPF_distrho_extra_Mutex.hpp,v 1.1 2020/10/30 15:47:02 nia Exp $

NetBSD pthreads does not have pthread_condattr_setpshared.

--- DPF/distrho/extra/Mutex.hpp.orig	2016-11-18 18:08:20.000000000 +0000
+++ DPF/distrho/extra/Mutex.hpp
@@ -194,7 +194,9 @@ public:
     {
         pthread_condattr_t cattr;
         pthread_condattr_init(&cattr);
+#if defined(PTHREAD_PROCESS_PRIVATE) && !defined(__NetBSD__)
         pthread_condattr_setpshared(&cattr, PTHREAD_PROCESS_PRIVATE);
+#endif
         pthread_cond_init(&fCondition, &cattr);
         pthread_condattr_destroy(&cattr);
 
