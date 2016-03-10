$NetBSD: patch-include_llvm_Support_Host.h,v 1.1 2016/03/10 15:01:52 tnn Exp $

Fix lack of machine/endian.h on solaris
http://permalink.gmane.org/gmane.comp.compilers.llvm.devel/63225

--- include/llvm/Support/Host.h.orig	2015-06-23 09:49:53.000000000 +0000
+++ include/llvm/Support/Host.h
@@ -18,6 +18,20 @@
 
 #if defined(__linux__) || defined(__GNU__)
 #include <endian.h>
+#elif defined(__sun) & defined(__SVR4)
+# ifndef BYTE_ORDER
+# define LITTLE_ENDIAN 1234
+# define BIG_ENDIAN 4321
+# if defined(__sun) & defined(__SVR4)
+# include <sys/isa_defs.h>
+# ifdef _LITTLE_ENDIAN
+# define BYTE_ORDER LITTLE_ENDIAN
+# endif
+# ifdef _BIG_ENDIAN
+# define BYTE_ORDER BIG_ENDIAN
+# endif
+# endif /* sun */
+# endif /* BYTE_ORDER */
 #else
 #if !defined(BYTE_ORDER) && !defined(LLVM_ON_WIN32)
 #include <machine/endian.h>
