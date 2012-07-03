$NetBSD: patch-avidemux_ADM__core_include_ADM__mangle.h,v 1.1 2012/07/03 17:38:31 joerg Exp $

--- avidemux/ADM_core/include/ADM_mangle.h.orig	2012-07-03 11:47:37.000000000 +0000
+++ avidemux/ADM_core/include/ADM_mangle.h
@@ -31,12 +31,12 @@
 #else
 #    if defined(ADM_CPU_X86_64) && defined(PIC)
 #        define MANGLE(a) #a"(%%rip)"
-#        define FUNNY_MANGLE(x) x asm(#x)
-#        define FUNNY_MANGLE_ARRAY(x, y)  x[y] asm(#x)
+#        define FUNNY_MANGLE(x) x asm(#x) __attribute__((__used__))
+#        define FUNNY_MANGLE_ARRAY(x, y)  x[y] asm(#x) __attribute__((__used__))
 #    else
 #        define MANGLE(a) #a
-#        define FUNNY_MANGLE(x) x asm(MANGLE(x))
-#        define FUNNY_MANGLE_ARRAY(x, y) x[y] asm(MANGLE(x))
+#        define FUNNY_MANGLE(x) x asm(MANGLE(x)) __attribute__((__used__))
+#        define FUNNY_MANGLE_ARRAY(x, y) x[y] asm(MANGLE(x)) __attribute__((__used__))
 #    endif
 #endif
 
