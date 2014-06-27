$NetBSD: patch-ffmpeg_libavutil_x86__cpu.h,v 1.1 2014/06/27 12:56:16 jperkin Exp $

Disable certain optimisations on SunOS.

--- ffmpeg/libavutil/x86_cpu.h.orig	2013-05-05 18:11:42.000000000 +0000
+++ ffmpeg/libavutil/x86_cpu.h
@@ -68,7 +68,11 @@ typedef int32_t x86_reg;
 typedef int x86_reg;
 #endif
 
+#ifdef __sun
+#define HAVE_7REGS 0
+#else
 #define HAVE_7REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE && HAVE_EBP_AVAILABLE))
+#endif
 #define HAVE_6REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE || HAVE_EBP_AVAILABLE))
 
 #if ARCH_X86_64 && defined(PIC)
