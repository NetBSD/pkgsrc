$NetBSD: manual-patch-avidemux_ADM__libraries_ffmpeg_libavcodec_x86_snowdsp__mmx.c,v 1.1 2012/07/03 17:38:31 joerg Exp $

--- avidemux/ADM_libraries/ffmpeg/libavcodec/x86/snowdsp_mmx.c.orig	2012-07-03 11:38:30.000000000 +0000
+++ avidemux/ADM_libraries/ffmpeg/libavcodec/x86/snowdsp_mmx.c
@@ -812,7 +812,7 @@ snow_inner_add_yblock_sse2_end_16
              "add %%"REG_c", "PTR_SIZE"*2(%%"REG_a");\n\t"\
              "add %%"REG_c", "PTR_SIZE"*1(%%"REG_a");\n\t"\
              "add %%"REG_c", (%%"REG_a")     \n\t"\
-             "add $"PTR_SIZE"*1, %1          \n\t"\
+             "addl $"PTR_SIZE"*1, %1          \n\t"\
              "add %%"REG_c", %0              \n\t"\
              "dec %2                         \n\t"\
              "jnz 1b                         \n\t"\
