$NetBSD: patch-mozilla_xpcom_reflect_xptcall_src_md_unix_xptcinvoke__gcc__x86__unix.cpp,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/xpcom/reflect/xptcall/src/md/unix/xptcinvoke_gcc_x86_unix.cpp.orig	2013-10-23 22:09:22.000000000 +0000
+++ mozilla/xpcom/reflect/xptcall/src/md/unix/xptcinvoke_gcc_x86_unix.cpp
@@ -9,7 +9,7 @@
 #include "xptc_gcc_x86_unix.h"
 
 extern "C" {
-static void ATTRIBUTE_USED __attribute__ ((regparm(3)))
+void ATTRIBUTE_USED __attribute__ ((regparm(3)))
 invoke_copy_to_stack(uint32_t paramCount, nsXPTCVariant* s, uint32_t* d)
 {
     for(uint32_t i = paramCount; i >0; i--, d++, s++)
