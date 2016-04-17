$NetBSD: patch-mozilla_xpcom_reflect_xptcall_md_unix_xptcstubs__gcc__x86__unix.cpp,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/xpcom/reflect/xptcall/md/unix/xptcstubs_gcc_x86_unix.cpp.orig	2015-06-08 17:49:34.000000000 +0000
+++ mozilla/xpcom/reflect/xptcall/md/unix/xptcstubs_gcc_x86_unix.cpp
@@ -10,7 +10,7 @@
 #include "xptc_gcc_x86_unix.h"
 
 extern "C" {
-static nsresult ATTRIBUTE_USED
+nsresult ATTRIBUTE_USED
 __attribute__ ((regparm (3)))
 PrepareAndDispatch(uint32_t methodIndex, nsXPTCStubBase* self, uint32_t* args)
 {
