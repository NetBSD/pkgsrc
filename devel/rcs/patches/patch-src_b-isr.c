$NetBSD: patch-src_b-isr.c,v 1.1 2023/05/18 14:46:04 schmonz Exp $

Avoid 'error: missing binary operator before token "("'.

--- src/b-isr.c.orig	2015-01-21 11:51:02.000000000 +0000
+++ src/b-isr.c
@@ -197,8 +197,6 @@ setup_catchsig (size_t count, int const
 
 #if defined HAVE_SIGALTSTACK && defined SIGSTKSZ
 #define ISR_STACK_SIZE  (10 * SIGSTKSZ)
-#else
-#define ISR_STACK_SIZE  0
 #endif
 
 struct isr_scratch *
@@ -206,7 +204,7 @@ isr_init (bool *be_quiet)
 {
   struct isr_scratch *scratch = ZLLOC (1, struct isr_scratch);
 
-#if ISR_STACK_SIZE
+#if defined ISR_STACK_SIZE
   stack_t ss =
     {
       .ss_sp = alloc (PLEXUS, "sigaltstack", ISR_STACK_SIZE),
