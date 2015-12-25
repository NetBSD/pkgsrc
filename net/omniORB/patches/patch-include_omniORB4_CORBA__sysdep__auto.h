$NetBSD: patch-include_omniORB4_CORBA__sysdep__auto.h,v 1.1 2015/12/25 02:55:16 dholland Exp $

Use "long" as "LONGLONG" only if native long long doesn't exist or isn't
64 bits. Fixes the build of omniNotify, which has code that reasonably
assumes that "long" and "LONGLONG" aren't the same type.

--- include/omniORB4/CORBA_sysdep_auto.h~	2010-11-22 23:00:44.000000000 +0000
+++ include/omniORB4/CORBA_sysdep_auto.h
@@ -68,17 +68,17 @@
 
 #define SIZEOF_PTR SIZEOF_VOIDP
 
-#if defined(SIZEOF_LONG) && (SIZEOF_LONG == 8)
-#  define HAS_LongLong
-#  define _CORBA_LONGLONG_DECL     long
-#  define _CORBA_ULONGLONG_DECL    unsigned long
-#  define _CORBA_LONGLONG_CONST(x) (x)
-
-#elif defined(SIZEOF_LONG_LONG) && (SIZEOF_LONG_LONG == 8)
+#if defined(SIZEOF_LONG_LONG) && (SIZEOF_LONG_LONG == 8)
 #  define HAS_LongLong
 #  define _CORBA_LONGLONG_DECL     long long
 #  define _CORBA_ULONGLONG_DECL    unsigned long long
 #  define _CORBA_LONGLONG_CONST(x) (x##LL)
+
+#elif defined(SIZEOF_LONG) && (SIZEOF_LONG == 8)
+#  define HAS_LongLong
+#  define _CORBA_LONGLONG_DECL     long
+#  define _CORBA_ULONGLONG_DECL    unsigned long
+#  define _CORBA_LONGLONG_CONST(x) (x)
 #endif
 
 
