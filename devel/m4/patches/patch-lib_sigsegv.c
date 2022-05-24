$NetBSD: patch-lib_sigsegv.c,v 1.1 2022/05/24 14:43:03 hauke Exp $

Use older regnames on MacOS X 10.4 "Tiger", taken from
<https://github.com/macports/macports-ports/blob/f9641f5f5cb7287e6787b566945fff460a80bc39/devel/m4/files/patch-m4-use-older-regnames-on-tiger.diff>

--- lib/sigsegv.c.orig	2021-05-19 14:36:49.000000000 +0000
+++ lib/sigsegv.c
@@ -586,7 +586,7 @@ int libsigsegv_version = LIBSIGSEGV_VERS
      - 'ucontext_t' and 'struct __darwin_ucontext' in <sys/_structs.h>,
      - 'struct __darwin_mcontext' in <ppc/_structs.h>, and
      - 'struct __darwin_ppc_thread_state' in <mach/ppc/_structs.h>.  */
-#  define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext->__ss.__r1
+#  define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext->ss.r1
 
 # endif
 
