$NetBSD: patch-libguile_syscalls.h,v 1.1 2025/10/06 19:45:07 wiz Exp $

commit 0f2125e66f3ad9df386e7887c87abea1b5e880e9
Author: Michael Gran <spk121@yahoo.com>
Date:   Tue Jun 20 15:22:21 2023 -0700

    Add missing #include in syscalls.h

    SCM_SYSCALL uses scm_async_tick.

    * libguile/syscalls.h: include async.h

--- libguile/syscalls.h.orig	2025-10-06 19:28:49.944137862 +0000
+++ libguile/syscalls.h
@@ -24,6 +24,8 @@
 
 /* ASYNC_TICK after finding EINTR in order to handle pending signals, if
    any. See comment in scm_syserror. */
+#include "async.h"
+
 #define SCM_SYSCALL(line)			\
   do						\
     {						\
