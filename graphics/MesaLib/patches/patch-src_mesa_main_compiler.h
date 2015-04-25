$NetBSD: patch-src_mesa_main_compiler.h,v 1.4 2015/04/25 11:19:18 tnn Exp $

i386 FPU control word defaults.

--- src/mesa/main/compiler.h.orig	2015-03-28 18:20:39.000000000 +0000
+++ src/mesa/main/compiler.h
@@ -285,7 +285,13 @@ static inline GLuint CPU_TO_LE32(GLuint 
 /* Hardware default: All exceptions masked, extended double precision,
  * round to nearest (IEEE compliant):
  */
+#if defined(__NetBSD__)
+#define DEFAULT_X86_FPU		0x127f	/* __NetBSD_NPXCW__ */
+#elif defined(__FreeBSD__)
+#define DEFAULT_X86_FPU		0x1272	/* __FreeBSD_NPXCW__ */
+#else
 #define DEFAULT_X86_FPU		0x037f
+#endif
 /* All exceptions masked, single precision, round to nearest:
  */
 #define FAST_X86_FPU		0x003f
