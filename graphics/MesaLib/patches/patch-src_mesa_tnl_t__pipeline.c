$NetBSD: patch-src_mesa_tnl_t__pipeline.c,v 1.1 2015/09/11 00:03:36 tnn Exp $

i386 FPU control word defaults.

--- src/mesa/tnl/t_pipeline.c.orig	2015-09-09 17:55:36.000000000 +0000
+++ src/mesa/tnl/t_pipeline.c
@@ -132,7 +132,13 @@ static GLuint check_output_changes( stru
 /* Hardware default: All exceptions masked, extended double precision,
  * round to nearest (IEEE compliant):
  */
+#if defined(__NetBSD__)
+#define DEFAULT_X86_FPU	0x127f  /* __NetBSD_NPXCW__ */
+#elif defined(__FreeBSD__)
+#define DEFAULT_X86_FPU	0x1272  /* __FreeBSD_NPXCW__ */
+#else
 #define DEFAULT_X86_FPU		0x037f
+#endif
 /* All exceptions masked, single precision, round to nearest:
  */
 #define FAST_X86_FPU		0x003f
