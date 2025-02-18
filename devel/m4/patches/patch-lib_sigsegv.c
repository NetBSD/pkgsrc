$NetBSD: patch-lib_sigsegv.c,v 1.2 2025/02/18 15:07:14 wiz Exp $

Use older regnames on MacOS X 10.4 "Tiger", taken from
<https://github.com/macports/macports-ports/blob/f9641f5f5cb7287e6787b566945fff460a80bc39/devel/m4/files/patch-m4-use-older-regnames-on-tiger.diff>

--- lib/sigsegv.c.orig	2021-05-19 14:36:49.000000000 +0000
+++ lib/sigsegv.c
@@ -33,6 +33,9 @@
 # include <sys/param.h> /* defines macro OpenBSD */
 #endif
 
+#ifdef __APPLE__
+# include <AvailabilityMacros.h>
+#endif
 
 /* Version number.  */
 int libsigsegv_version = LIBSIGSEGV_VERSION;
@@ -562,7 +565,11 @@ int libsigsegv_version = LIBSIGSEGV_VERS
      - 'ucontext_t' and 'struct __darwin_ucontext' in <sys/_types/_ucontext.h>,
      - 'struct __darwin_mcontext64' in <i386/_mcontext.h>, and
      - 'struct __darwin_x86_thread_state64' in <mach/i386/_structs.h>.  */
+# if __MAC_OS_X_VERSION_MAX_ALLOWED < 1050
+#  define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext->ss.rsp
+# else
 #  define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext->__ss.__rsp
+# endif
 
 # elif defined __i386__
 
@@ -570,7 +577,11 @@ int libsigsegv_version = LIBSIGSEGV_VERS
      - 'ucontext_t' and 'struct __darwin_ucontext' in <sys/_types/_ucontext.h>,
      - 'struct __darwin_mcontext32' in <i386/_mcontext.h>, and
      - 'struct __darwin_i386_thread_state' in <mach/i386/_structs.h>.  */
+# if __MAC_OS_X_VERSION_MAX_ALLOWED < 1050
+#  define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext->ss.esp
+# else
 #  define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext->__ss.__esp
+# endif
 
 # elif defined __arm64__
 
@@ -586,7 +597,11 @@ int libsigsegv_version = LIBSIGSEGV_VERS
      - 'ucontext_t' and 'struct __darwin_ucontext' in <sys/_structs.h>,
      - 'struct __darwin_mcontext' in <ppc/_structs.h>, and
      - 'struct __darwin_ppc_thread_state' in <mach/ppc/_structs.h>.  */
+# if __MAC_OS_X_VERSION_MAX_ALLOWED < 1050
+#  define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext->ss.r1
+# else
 #  define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext->__ss.__r1
+#endif
 
 # endif
 
