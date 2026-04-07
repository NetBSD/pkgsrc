$NetBSD: patch-lib_sigsegv.c,v 1.3 2026/04/07 12:23:36 wiz Exp $

Use older regnames on MacOS X 10.4 "Tiger", taken from
<https://github.com/macports/macports-ports/blob/f9641f5f5cb7287e6787b566945fff460a80bc39/devel/m4/files/patch-m4-use-older-regnames-on-tiger.diff>

Sent to bug-m4 mailing list on 2026-04-07.

--- lib/sigsegv.c.orig	2026-02-03 19:04:18.000000000 +0000
+++ lib/sigsegv.c
@@ -35,6 +35,9 @@
 # include <sys/param.h> /* defines macro OpenBSD */
 #endif
 
+#ifdef __APPLE__
+# include <AvailabilityMacros.h>
+#endif
 
 /* Version number.  */
 int libsigsegv_version = LIBSIGSEGV_VERSION;
@@ -660,7 +663,11 @@ int libsigsegv_version = LIBSIGSEGV_VERSION;
      - 'ucontext_t' and 'struct __darwin_ucontext' in <sys/_types/_ucontext.h>,
      - 'struct __darwin_mcontext64' in <i386/_mcontext.h>, and
      - 'struct __darwin_x86_thread_state64' in <mach/i386/_structs.h>.  */
+# if __MAC_OS_X_VERSION_MAX_ALLOWED < 1050
+#  define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext->ss.rsp
+# else
 #  define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext->__ss.__rsp
+# endif
 
 # elif defined __i386__
 
@@ -668,7 +675,11 @@ int libsigsegv_version = LIBSIGSEGV_VERSION;
      - 'ucontext_t' and 'struct __darwin_ucontext' in <sys/_types/_ucontext.h>,
      - 'struct __darwin_mcontext32' in <i386/_mcontext.h>, and
      - 'struct __darwin_i386_thread_state' in <mach/i386/_structs.h>.  */
+# if __MAC_OS_X_VERSION_MAX_ALLOWED < 1050
+#  define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext->ss.esp
+# else
 #  define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext->__ss.__esp
+# endif
 
 # elif defined __arm64__
 
