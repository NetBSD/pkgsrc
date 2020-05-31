$NetBSD: patch-core_rec-x64_rec__x64.cpp,v 1.1 2020/05/31 15:20:22 nia Exp $

Add support for NetBSD.

--- core/rec-x64/rec_x64.cpp.orig	2020-05-29 12:45:55.000000000 +0000
+++ core/rec-x64/rec_x64.cpp
@@ -112,6 +112,8 @@ WIN32_ONLY(     ".seh_pushreg %r14      
 #endif
 #if defined(__MACH__) || defined(_WIN32)
                         "call " _U "setjmp							\n\t"
+#elif defined(__NetBSD__)
+                        "call " _U "__setjmp14@PLT						\n\t"
 #else
                         "call " _U "setjmp@PLT						\n\t"
 #endif
