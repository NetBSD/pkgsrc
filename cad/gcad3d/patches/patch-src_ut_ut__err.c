$NetBSD: patch-src_ut_ut__err.c,v 1.1 2022/05/23 19:10:03 plunky Exp $

do not use obsolete non-standard definitions

--- src/ut/ut_err.c.orig	2021-07-18 06:38:57.000000000 +0000
+++ src/ut/ut_err.c
@@ -150,7 +150,7 @@ static jmp_buf       err_buf;
   ssa.sa_handler = ERR_cb1;
   sigemptyset (&ssa.sa_mask);
   // ssa.sa_flags   = SA_RESTART | SA_NOMASK | SA_NOCLDSTOP;
-  ssa.sa_flags   = SA_ONESHOT | SA_NOMASK;
+  ssa.sa_flags   = SA_RESETHAND | SA_NODEFER;
 
   sigaction (SIGSEGV, &ssa, NULL);      // 11
   // sigaction (SIGSEGV, &ssa, &err_sDfl);      // 11
