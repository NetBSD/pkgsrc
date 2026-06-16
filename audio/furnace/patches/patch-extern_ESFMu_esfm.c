$NetBSD: patch-extern_ESFMu_esfm.c,v 1.1 2026/06/16 17:19:32 nia Exp $

The NetBSD toolchain does not accept this as valid i386 assembler,
so remove it, and use the portable C fallback.

esfm.c:1854:25: error: 'asm' operand has impossible constraints

--- extern/ESFMu/esfm.c.orig	2026-06-16 17:16:26.438749656 +0000
+++ extern/ESFMu/esfm.c
@@ -1850,72 +1850,6 @@ ESFM_process_feedback(esfm_chip *chip)
 				  [exprom] "m"   (exprom)
 				: "cc", "ax", "bx", "cx", "dx", "r8", "r9", "r10", "r11"
 			);
-#elif defined(__GNUC__) && defined(__i386__)
-			asm (
-				"movzbl  %b[wave], %%eax             \n\t"
-				"shll    $11, %%eax                  \n\t"
-				"leal    %[sinrom], %%edi            \n\t"
-				"addl    %%eax, %%edi                \n\t"
-				"shlw    $3, %[eg_out]               \n\t"
-				"xorl    %[out], %[out]              \n\t"
-				"movl    %[out], %[last]             \n\t"
-				"movl    $29, %[i]                   \n"
-				"1:                                  \n\t"
-				// phase_feedback = (wave_out + wave_last) >> 2;
-				"movl    %[out], %%eax               \n\t"
-				"addl    %[last], %%eax              \n\t"
-				"sarl    $2, %%eax                   \n\t"
-				"movl    %%eax, %[p_fb]              \n\t"
-				// wave_last = wave_out
-				"movl    %[out], %[last]             \n\t"
-				// phase = phase_feedback >> mod_in_shift;
-				"movb    %[mod_in], %%cl             \n\t"
-				"sarl    %%cl, %%eax                 \n\t"
-				// phase += phase_acc >> 9;
-				"movl    %[p_acc], %%ebx             \n\t"
-				"shrl    $9, %%ebx                   \n\t"
-				"addl    %%ebx, %%eax                \n\t"
-				// lookup = logsinrom[(waveform << 10) | (phase & 0x3ff)];
-				"andl    $0x3ff, %%eax               \n\t"
-				"movzwl  (%%edi, %%eax, 2), %%ebx    \n\t"
-				"movl    %%ebx, %%eax                \n\t"
-				// level = (lookup & 0x1fff) + (envelope << 3);
-				"movl    $0x1fff, %%ecx              \n\t"
-				"andl    %%ecx, %%eax                \n\t"
-				"addw    %[eg_out], %%ax             \n\t"
-				// if (level > 0x1fff) level = 0x1fff;
-				"cmpl    %%ecx, %%eax                \n\t"
-				"cmoval  %%ecx, %%eax                \n\t"
-				// wave_out = exprom[level & 0xff] >> (level >> 8);
-				"movb    %%ah, %%cl                  \n\t"
-				"movzbl  %%al, %%eax                 \n\t"
-				"leal    %[exprom], %[out]           \n\t"
-				"movzwl  (%[out], %%eax, 2), %[out]  \n\t"
-				"shrl    %%cl, %[out]                \n\t"
-				// if (lookup & 0x8000) wave_out = -wave_out;
-				// in other words, lookup is negative
-				"movl    %[out], %%ecx               \n\t"
-				"negl    %%ecx                       \n\t"
-				"testw   %%bx, %%bx                  \n\t"
-				"cmovsl  %%ecx, %[out]               \n\t"
-				// phase_acc += phase_offset
-				"addl    %[p_off], %[p_acc]          \n\t"
-				// loop
-				"decl    %[i]                        \n\t"
-				"jne     1b                          \n\t"
-				: [p_fb]   "=&m" (phase_feedback),
-				  [p_acc]  "+r"  (phase_acc),
-				  [out]    "=&r" (wave_out),
-				  [last]   "=&m" (wave_last),
-				  [eg_out] "+m"  (eg_output)
-				: [p_off]  "m"   (phase_offset),
-				  [mod_in] "m"   (mod_in_shift),
-				  [wave]   "m"   (waveform),
-				  [sinrom] "m"   (logsinrom),
-				  [exprom] "m"   (exprom),
-				  [i]      "m"   (iter_counter)
-				: "cc", "ax", "bx", "cx", "di"
-			);
 #elif defined(__GNUC__) && defined(__arm__)
 			asm (
 				"movs    r3, #0                     \n\t"
