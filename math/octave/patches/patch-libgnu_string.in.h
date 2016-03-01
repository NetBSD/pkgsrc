$NetBSD: patch-libgnu_string.in.h,v 1.3 2016/03/01 20:13:19 joerg Exp $

The "split" include guards fails miserable on NetBSD since by default
string.h will include strings.h, which goes back to string.h. Now due to
the lovely magic here, the rest of the file will be processed before the
real header.

--- libgnu/string.in.h.orig	2015-05-23 14:36:17.000000000 +0000
+++ libgnu/string.in.h
@@ -22,11 +22,8 @@
 #endif
 @PRAGMA_COLUMNS@
 
-/* The include_next requires a split double-inclusion guard.  */
-#@INCLUDE_NEXT@ @NEXT_STRING_H@
-
-#ifndef _@GUARD_PREFIX@_STRING_H
 #define _@GUARD_PREFIX@_STRING_H
+#@INCLUDE_NEXT@ @NEXT_STRING_H@
 
 /* NetBSD 5.0 mis-defines NULL.  */
 #include <stddef.h>
@@ -184,6 +181,12 @@ _GL_WARN_ON_USE (mempcpy, "mempcpy is un
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
@@ -210,6 +213,7 @@ _GL_WARN_ON_USE (memrchr, "memrchr is un
                  "use gnulib module memrchr for portability");
 # endif
 #endif
+#endif
 
 /* Find the first occurrence of C in S.  More efficient than
    memchr(S,C,N), at the expense of undefined behavior if C does not
@@ -1026,4 +1030,3 @@ _GL_WARN_ON_USE (strverscmp, "strverscmp
 
 
 #endif /* _@GUARD_PREFIX@_STRING_H */
-#endif /* _@GUARD_PREFIX@_STRING_H */
