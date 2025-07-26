$NetBSD: patch-vm__core.h,v 1.1 2025/07/26 06:25:23 taca Exp $

Enable sigaltstack(2) again on NetBSD.  This has not been relevant for
a very long time, probably since NetBSD 6.

--- vm_core.h.orig	2025-07-24 10:04:28.000000000 +0000
+++ vm_core.h
@@ -137,7 +137,7 @@ extern int ruby_assert_critical_section_
 #  define RUBY_SIGCHLD (SIGCHLD)
 #endif
 
-#if defined(SIGSEGV) && defined(HAVE_SIGALTSTACK) && defined(SA_SIGINFO) && !defined(__NetBSD__)
+#if defined(SIGSEGV) && defined(HAVE_SIGALTSTACK) && defined(SA_SIGINFO)
 #  define USE_SIGALTSTACK
 void *rb_allocate_sigaltstack(void);
 void *rb_register_sigaltstack(void *);
