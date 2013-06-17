$NetBSD: patch-mono_utils_mono-compiler.h,v 1.1 2013/06/17 12:43:28 wiz Exp $

Make sure that TLS variables are actually emitted, since the compiler
doesn't see all references.

--- mono/utils/mono-compiler.h.orig	2012-04-27 22:30:53.000000000 +0000
+++ mono/utils/mono-compiler.h
@@ -29,7 +29,7 @@
 #if defined(PIC)
 
 #ifdef PIC_INITIAL_EXEC
-#define MONO_TLS_FAST __attribute__((tls_model("initial-exec")))
+#define MONO_TLS_FAST __attribute__((tls_model("initial-exec"), used))
 #else
 #if defined (__powerpc__)
 /* local dynamic requires a call to __tls_get_addr to look up the
@@ -41,18 +41,18 @@
    For now we will disable this. */
 #define MONO_TLS_FAST
 #else
-#define MONO_TLS_FAST __attribute__((tls_model("local-dynamic")))
+#define MONO_TLS_FAST __attribute__((tls_model("local-dynamic"), used))
 #endif
 #endif
 
 #else
 
-#define MONO_TLS_FAST __attribute__((tls_model("local-exec")))
+#define MONO_TLS_FAST __attribute__((tls_model("local-exec"), used))
 
 #endif
 
 #else
-#define MONO_TLS_FAST 
+#define MONO_TLS_FAST
 #endif
 
 #if defined(__GNUC__) && defined(__i386__)
