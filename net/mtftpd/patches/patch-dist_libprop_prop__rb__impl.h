$NetBSD: patch-dist_libprop_prop__rb__impl.h,v 1.1 2012/03/07 11:39:40 hans Exp $

--- dist/libprop/prop_rb_impl.h.orig	2008-02-29 19:25:59.000000000 +0100
+++ dist/libprop/prop_rb_impl.h	2012-03-02 20:19:45.277472499 +0100
@@ -43,6 +43,8 @@
 #include <sys/queue.h>
 #ifdef __linux__
 #include <bits/endian.h>
+#elif defined(HAVE_NBCOMPAT_H)
+#include <nbcompat/endian.h>
 #else
 #include <machine/endian.h>
 #endif
