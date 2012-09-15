$NetBSD: patch-src_racket_sconfig.h,v 1.3 2012/09/15 13:33:59 marino Exp $

Add DragonFly support.

--- src/racket/sconfig.h.orig	2012-08-06 22:51:46.000000000 +0000
+++ src/racket/sconfig.h
@@ -989,6 +989,58 @@
 
 #endif /* end not OSKit */
 
+
+#if defined(__DragonFly__)
+ 
+# if defined(__i386__)
+#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "i386-dragonfly"
+#  define REGISTER_POOR_MACHINE
+#  define MZ_USE_JIT_I386
+#  ifndef MZ_JIT_X86_SSE
+#     define ASM_DBLPREC_CONTROL_87
+#  endif
+# elif defined(__amd64__)
+#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "amd64-dragonfly"
+#  define REGISTER_POOR_MACHINE
+#  define MZ_USE_JIT_X86_64
+#  ifdef MZ_NO_JIT_SSE
+#     define ASM_DBLPREC_CONTROL_87
+#  endif
+# else
+#  error Unported platform.
+# endif
+
+/* pthreads always enabled via configure', and
+   initial pthread's stack size doesn't use rlimit: */
+# define ASSUME_FIXED_STACK_SIZE
+# define FIXED_STACK_SIZE 1048576
+
+# include "uconfig.h"
+# undef HAS_STANDARD_IOB
+
+# define HAS_BSD_IOB
+
+# define USE_UNDERSCORE_SETJMP
+
+# define USE_IEEE_FP_PREDS
+# ifndef ASM_DBLPREC_CONTROL_87
+#  define POW_HANDLES_INF_CORRECTLY
+# endif
+
+# define USE_DYNAMIC_FDSET_SIZE
+
+# define SIGSET_IS_SIGNAL
+
+# define USE_TM_GMTOFF_FIELD
+# define USE_TM_ZONE_FIELD
+
+# define MZ_JIT_USE_MPROTECT
+
+# define FLAGS_ALREADY_SET
+
+#endif /* end DragonFly */
+
+
 /************** (END KNOWN ARCHITECTURE/SYSTEMS) ****************/
 
 
