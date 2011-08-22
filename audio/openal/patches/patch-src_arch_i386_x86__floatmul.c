$NetBSD: patch-src_arch_i386_x86__floatmul.c,v 1.1 2011/08/22 13:36:31 wiz Exp $

Fix build with gcc-4.5.

--- src/arch/i386/x86_floatmul.c.orig	2005-12-21 19:06:35.000000000 +0000
+++ src/arch/i386/x86_floatmul.c
@@ -82,11 +82,19 @@ void _alFloatMul(ALshort *bpt, ALfloat s
 			v_sa.s[3] = v_sa.s[0];
 			
 			while (samples_main--) {
+				union {
+					short s[4];
+					v4hi v;
+				} ALIGN16(v_one);
+				v_one.s[0] = 1;
+				v_one.s[1] = 0;
+				v_one.s[2] = 0;
+				v_one.s[3] = 0;
 				temp = __builtin_ia32_pmulhw(*(v4hi*)bpt, v_sa.v);
-				*(v4hi*)bpt = __builtin_ia32_psllw(temp, 1LL);
+				*(v4hi*)bpt = __builtin_ia32_psllw(temp, v_one.v);
 				bpt += 4;
 				temp = __builtin_ia32_pmulhw(*(v4hi*)bpt, v_sa.v);
-				*(v4hi*)bpt = __builtin_ia32_psllw(temp, 1LL);
+				*(v4hi*)bpt = __builtin_ia32_psllw(temp, v_one.v);
 				bpt += 4;
 			}
 		}
