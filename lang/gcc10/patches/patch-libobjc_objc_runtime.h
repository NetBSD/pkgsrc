$NetBSD: patch-libobjc_objc_runtime.h,v 1.1 2024/04/01 14:33:58 js Exp $

This is weird. For some reason, those are not defined on QNX even when not
including <stddef.h> first. This might be a side effect of not using
fixincludes on QNX (as that breaks headers even more).

This is obviously a nasty hack and a proper solution needs to be found, but for
now, this makes libobjc compile.

--- libobjc/objc/runtime.h.orig	2024-04-01 12:21:17.000000000 +0000
+++ libobjc/objc/runtime.h
@@ -42,6 +42,11 @@ see the files COPYING3 and COPYING.RUNTI
 extern "C" {
 #endif /* __cplusplus */
 
+#ifdef __QNX__
+typedef __SIZE_TYPE__ size_t;
+typedef __PTRDIFF_TYPE__ ptrdiff_t;
+#endif
+
 /* An 'Ivar' represents an instance variable.  It holds information
    about the name, type and offset of the instance variable.  */
 typedef struct objc_ivar *Ivar;
