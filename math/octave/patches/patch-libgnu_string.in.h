$NetBSD: patch-libgnu_string.in.h,v 1.1 2011/12/24 23:46:02 asau Exp $

--- libgnu/string.in.h.orig	2011-08-04 03:59:53.000000000 +0000
+++ libgnu/string.in.h
@@ -187,6 +187,12 @@ _GL_WARN_ON_USE (mempcpy, "mempcpy is un
 #endif
 
 /* Search backwards through a block for a byte (specified as an int).  */
+#if defined(__NetBSD__)
+#if defined(__cplusplus)
+extern "C"
+#endif
+void * memrchr(const void *b, int c, size_t len);
+#else
 #if @GNULIB_MEMRCHR@
 # if ! @HAVE_DECL_MEMRCHR@
 _GL_FUNCDECL_SYS (memrchr, void *, (void const *, int, size_t)
@@ -213,6 +219,7 @@ _GL_WARN_ON_USE (memrchr, "memrchr is un
                  "use gnulib module memrchr for portability");
 # endif
 #endif
+#endif
 
 /* Find the first occurrence of C in S.  More efficient than
    memchr(S,C,N), at the expense of undefined behavior if C does not
