$NetBSD: patch-lib_erl__interface_src_connect_ei__resolve.c,v 1.2 2026/01/02 13:23:41 ryoon Exp $

* Port undef HAVE_GETHOSTBYNAME_R from erlang-27 to fix build under NetBSD.

--- lib/erl_interface/src/connect/ei_resolve.c.orig	2019-04-17 14:14:50.000000000 +0000
+++ lib/erl_interface/src/connect/ei_resolve.c
@@ -55,6 +55,10 @@
 #include "ei_resolve.h"
 #include "ei_locking.h"
 
+#if defined(_AIX) || defined(__NetBSD__) || (defined(__ANDROID__) && (__ANDROID_API__ < 23))
+#undef HAVE_GETHOSTBYNAME_R
+#endif
+
 #ifdef HAVE_GETHOSTBYNAME_R
 
 int ei_init_resolve(void)
