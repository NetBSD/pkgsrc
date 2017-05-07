$NetBSD: patch-xen_include_xen_init.h,v 1.1 2017/05/07 21:21:01 joerg Exp $

--- xen/include/xen/init.h.orig	2016-09-20 05:59:24.000000000 +0000
+++ xen/include/xen/init.h
@@ -11,6 +11,7 @@
 #define __exit            __text_section(".exit.text")
 #define __initdata        __section(".init.data")
 #define __initconst       __section(".init.rodata")
+#define __initconstrel    __section(".init.rodata.rel")
 #define __exitdata        __used_section(".exit.data")
 #define __initsetup       __used_section(".init.setup")
 #define __init_call(lvl)  __used_section(".initcall" lvl ".init")
