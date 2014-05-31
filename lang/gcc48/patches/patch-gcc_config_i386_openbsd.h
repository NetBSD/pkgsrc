$NetBSD: patch-gcc_config_i386_openbsd.h,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- gcc/config/i386/openbsd.h.orig	2013-01-10 20:38:27.000000000 +0000
+++ gcc/config/i386/openbsd.h
@@ -38,10 +38,10 @@ along with GCC; see the file COPYING3.  
 
 /* This must agree with <machine/ansi.h> */
 #undef SIZE_TYPE
-#define SIZE_TYPE "unsigned int"
+#define SIZE_TYPE "long unsigned int"
 
 #undef PTRDIFF_TYPE
-#define PTRDIFF_TYPE "int"
+#define PTRDIFF_TYPE "long int"
 
 #undef WCHAR_TYPE
 #define WCHAR_TYPE "int"
@@ -49,6 +49,9 @@ along with GCC; see the file COPYING3.  
 #undef WCHAR_TYPE_SIZE
 #define WCHAR_TYPE_SIZE 32
 
+#undef WINT_TYPE
+#define WINT_TYPE "int"
+
 /* Assembler format: overall framework.  */
 
 #undef ASM_APP_ON
