$NetBSD: patch-lib_type1_objects.h,v 1.1 2022/06/08 19:00:13 chuck Exp $

Point LONGLONG macro at memcpy() rather than using t1lib custom code.
The t1lib version causes some versions of clang to produce incorrect
code when compiled with -O2.  Newer versions of clang (>= clang-12)
have fixed the issue.  see note in:
    https://mail-index.netbsd.org/tech-pkg/2022/06/08/msg026367.html

--- lib/type1/objects.h.orig	2022-06-08 13:28:14.000000000 -0400
+++ lib/type1/objects.h	2022-06-08 13:28:29.000000000 -0400
@@ -152,10 +152,14 @@
 /*END SHARED*/
 /*SHARED*/
  
+#if 0
 #define  LONGCOPY(dest,source,bytes) { \
     register LONG *p1 = (LONG *)dest;  register LONG *p2 = (LONG *)source; \
     register int count = (bytes) / sizeof(LONG); \
     while (--count >= 0) *p1++ = *p2++; }
+#else
+#define  LONGCOPY(dest,source,bytes) memcpy(dest,source,bytes)
+#endif
  
  
 /*END SHARED*/
