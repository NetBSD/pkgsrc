$NetBSD: patch-src_mesa_tnl_t__pipeline.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

i386 FPU control word defaults.

Neither FreeBSD ports nor DragonFly dports graphics/mesa-dri
mentions any concern with DEFAULT_X86_FPUs value.

--- src/mesa/tnl/t_pipeline.c.orig	2018-01-09 16:03:44.000000000 +0000
+++ src/mesa/tnl/t_pipeline.c
@@ -132,7 +132,11 @@ static GLuint check_output_changes( stru
 /* Hardware default: All exceptions masked, extended double precision,
  * round to nearest (IEEE compliant):
  */
+#if defined(__NetBSD__)
+#define DEFAULT_X86_FPU	0x127f  /* __NetBSD_NPXCW__ */
+#else
 #define DEFAULT_X86_FPU		0x037f
+#endif
 /* All exceptions masked, single precision, round to nearest:
  */
 #define FAST_X86_FPU		0x003f
