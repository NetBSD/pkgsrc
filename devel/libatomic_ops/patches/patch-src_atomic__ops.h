$NetBSD: patch-src_atomic__ops.h,v 1.1 2019/03/02 14:51:54 adam Exp $

Sun Studio x86 implementation isn't quite good enough yet for e.g.
pulseaudio, so instead use the generic pthread implementation for now.

--- src/atomic_ops.h.orig	2019-03-01 16:59:46.000000000 +0000
+++ src/atomic_ops.h
@@ -400,7 +400,10 @@
 # endif
 #endif
 
-#if !defined(__GNUC__) && (defined(sparc) || defined(__sparc)) \
+#if defined(__SUNPRO_C) && defined(__i386)
+#   include "atomic_ops/sysdeps/generic_pthread.h"
+#   define AO_CAN_EMUL_CAS
+#elif !defined(__GNUC__) && (defined(sparc) || defined(__sparc)) \
     && !defined(AO_USE_PTHREAD_DEFS)
 # include "atomic_ops/sysdeps/sunc/sparc.h"
 # define AO_CAN_EMUL_CAS
