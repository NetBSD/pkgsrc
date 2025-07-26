$NetBSD: patch-vm__core.h,v 1.1 2025/07/26 06:21:36 taca Exp $

Enable sigaltstack(2) again on NetBSD.  This has not been relevant for
a very long time, probably since NetBSD 6.

--- vm_core.h.orig	2025-07-24 08:27:18.000000000 +0000
+++ vm_core.h
@@ -148,7 +148,7 @@ extern int ruby_assert_critical_section_
 /* define to 0 to test old code path */
 #define WAITPID_USE_SIGCHLD (RUBY_SIGCHLD || SIGCHLD_LOSSY)
 
-#if defined(SIGSEGV) && defined(HAVE_SIGALTSTACK) && defined(SA_SIGINFO) && !defined(__NetBSD__)
+#if defined(SIGSEGV) && defined(HAVE_SIGALTSTACK) && defined(SA_SIGINFO)
 #  define USE_SIGALTSTACK
 void *rb_allocate_sigaltstack(void);
 void *rb_register_sigaltstack(void *);
