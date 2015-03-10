$NetBSD: patch-src_runtime_os__solaris.c,v 1.1 2015/03/10 13:11:36 jperkin Exp $

Support cgo on illumos.

--- src/runtime/os_solaris.c.orig	2014-12-11 01:18:12.000000000 +0000
+++ src/runtime/os_solaris.c
@@ -46,38 +46,40 @@
 #pragma dynimport libc·usleep usleep "libc.so"
 #pragma dynimport libc·write write "libc.so"
 
-extern uintptr libc·___errno;
-extern uintptr libc·clock_gettime;
-extern uintptr libc·close;
-extern uintptr libc·exit;
-extern uintptr libc·fstat;
-extern uintptr libc·getcontext;
-extern uintptr libc·getrlimit;
-extern uintptr libc·malloc;
-extern uintptr libc·mmap;
-extern uintptr libc·munmap;
-extern uintptr libc·open;
-extern uintptr libc·pthread_attr_destroy;
-extern uintptr libc·pthread_attr_getstack;
-extern uintptr libc·pthread_attr_init;
-extern uintptr libc·pthread_attr_setdetachstate;
-extern uintptr libc·pthread_attr_setstack;
-extern uintptr libc·pthread_create;
-extern uintptr libc·raise;
-extern uintptr libc·read;
-extern uintptr libc·sched_yield;
-extern uintptr libc·select;
-extern uintptr libc·sem_init;
-extern uintptr libc·sem_post;
-extern uintptr libc·sem_reltimedwait_np;
-extern uintptr libc·sem_wait;
-extern uintptr libc·setitimer;
-extern uintptr libc·sigaction;
-extern uintptr libc·sigaltstack;
-extern uintptr libc·sigprocmask;
-extern uintptr libc·sysconf;
-extern uintptr libc·usleep;
-extern uintptr libc·write;
+typedef uintptr (extf)();
+
+extern extf libc·___errno;
+extern extf libc·clock_gettime;
+extern extf libc·close;
+extern extf libc·exit;
+extern extf libc·fstat;
+extern extf libc·getcontext;
+extern extf libc·getrlimit;
+extern extf libc·malloc;
+extern extf libc·mmap;
+extern extf libc·munmap;
+extern extf libc·open;
+extern extf libc·pthread_attr_destroy;
+extern extf libc·pthread_attr_getstack;
+extern extf libc·pthread_attr_init;
+extern extf libc·pthread_attr_setdetachstate;
+extern extf libc·pthread_attr_setstack;
+extern extf libc·pthread_create;
+extern extf libc·raise;
+extern extf libc·read;
+extern extf libc·sched_yield;
+extern extf libc·select;
+extern extf libc·sem_init;
+extern extf libc·sem_post;
+extern extf libc·sem_reltimedwait_np;
+extern extf libc·sem_wait;
+extern extf libc·setitimer;
+extern extf libc·sigaction;
+extern extf libc·sigaltstack;
+extern extf libc·sigprocmask;
+extern extf libc·sysconf;
+extern extf libc·usleep;
+extern extf libc·write;
 
 void	runtime·getcontext(Ucontext *context);
 int32	runtime·pthread_attr_destroy(PthreadAttr* attr);
@@ -396,12 +398,13 @@ runtime·munmap(byte* addr, uintptr len)
 	runtime·sysvicall2(libc·munmap, (uintptr)addr, (uintptr)len);
 }
 
-extern int64 runtime·nanotime1(void);
+extern uintptr runtime·nanotime1(void);
+
 #pragma textflag NOSPLIT
 int64
 runtime·nanotime(void)
 {
-	return runtime·sysvicall0((uintptr)runtime·nanotime1);
+	return runtime·sysvicall0(runtime·nanotime1);
 }
 
 #pragma textflag NOSPLIT
