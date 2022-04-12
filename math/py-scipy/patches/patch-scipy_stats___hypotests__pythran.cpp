$NetBSD: patch-scipy_stats___hypotests__pythran.cpp,v 1.1 2022/04/12 20:31:43 tnn Exp $

/usr/include/iso/ctype_iso.h on SunOS has this:
#define _P      0x00000010      /* Punctuation */

Kludge away this macro.

--- scipy/stats/_hypotests_pythran.cpp.orig	2022-02-04 14:45:39.615792300 +0000
+++ scipy/stats/_hypotests_pythran.cpp
@@ -253,6 +253,9 @@ namespace __pythran__hypotests_pythran
     typename type<argument_type0>::result_type operator()(argument_type0&& A) const
     ;
   }  ;
+#ifdef _P
+#undef _P
+#endif
   struct _P
   {
     typedef void callable;
