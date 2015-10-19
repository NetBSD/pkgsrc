$NetBSD: patch-qemu-xen_target-i386_op__helper.c,v 1.1 2015/10/19 16:40:41 joerg Exp $

--- qemu-xen/target-i386/op_helper.c.orig	2015-10-09 23:00:48.000000000 +0000
+++ qemu-xen/target-i386/op_helper.c
@@ -68,6 +68,10 @@ static inline target_long lshift(target_
 #define MANTD(fp)       (fp.l.lower)
 #define BIASEXPONENT(fp) fp.l.upper = (fp.l.upper & ~(0x7fff)) | EXPBIAS
 
+#if !defined(AREG0)
+CPUState *env;
+#endif
+
 static inline void fpush(void)
 {
     env->fpstt = (env->fpstt - 1) & 7;
