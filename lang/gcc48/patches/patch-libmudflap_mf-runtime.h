$NetBSD: patch-libmudflap_mf-runtime.h,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- libmudflap/mf-runtime.h.orig	2013-02-03 17:48:05.000000000 +0000
+++ libmudflap/mf-runtime.h
@@ -31,7 +31,11 @@ see the files COPYING3 and COPYING.RUNTI
 #define MF_RUNTIME_H
 
 typedef void *__mf_ptr_t;
+#if defined(__OpenBSD__)
+typedef unsigned long __mf_uintptr_t __attribute__ ((__mode__ (__pointer__)));
+#else
 typedef unsigned int __mf_uintptr_t __attribute__ ((__mode__ (__pointer__)));
+#endif
 typedef __SIZE_TYPE__ __mf_size_t;
 
 /* Global declarations used by instrumentation.  When _MUDFLAP is
