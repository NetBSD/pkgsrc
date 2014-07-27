$NetBSD: patch-mozilla_xpcom_reflect_xptcall_src_md_unix_xptcstubs__gcc__x86__unix.cpp,v 1.1 2014/07/27 05:36:07 ryoon Exp $

--- mozilla/xpcom/reflect/xptcall/src/md/unix/xptcstubs_gcc_x86_unix.cpp.orig	2013-10-23 22:09:22.000000000 +0000
+++ mozilla/xpcom/reflect/xptcall/src/md/unix/xptcstubs_gcc_x86_unix.cpp
@@ -10,7 +10,7 @@
 #include "xptc_gcc_x86_unix.h"
 
 extern "C" {
-static nsresult ATTRIBUTE_USED
+nsresult ATTRIBUTE_USED
 __attribute__ ((regparm (3)))
 PrepareAndDispatch(uint32_t methodIndex, nsXPTCStubBase* self, uint32_t* args)
 {
