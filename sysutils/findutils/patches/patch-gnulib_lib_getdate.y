$NetBSD: patch-gnulib_lib_getdate.y,v 1.1.2.2 2015/09/27 08:14:35 bsiegert Exp $

Remove flagrantly wrong compile-time assertion.

--- gnulib/lib/getdate.y~	2009-05-10 21:23:57.000000000 +0000
+++ gnulib/lib/getdate.y
@@ -114,7 +114,9 @@
    wraps around, but there's no portable way to check for that at
    compile-time.  */
 verify (TYPE_IS_INTEGER (time_t));
+#if 0 /* not true */
 verify (LONG_MIN <= TYPE_MINIMUM (time_t) && TYPE_MAXIMUM (time_t) <= LONG_MAX);
+#endif
 
 /* An integer value, and the number of digits in its textual
    representation.  */
