$NetBSD: patch-lib_erl__interface_src_connect_ei__resolve.c,v 1.1 2026/01/02 13:11:02 ryoon Exp $

* Port undef HAVE_GETHOSTBYNAME_R from erlang-27 to fix build under NetBSD.

--- lib/erl_interface/src/connect/ei_resolve.c.orig	2026-01-02 13:04:03.328523871 +0000
+++ lib/erl_interface/src/connect/ei_resolve.c
@@ -55,6 +55,11 @@
 #include "ei_resolve.h"
 #include "ei_locking.h"
 
+#if defined(_AIX) || defined(__NetBSD__) || (defined(__ANDROID__) && (__ANDROID_
+API__ < 23))
+#undef HAVE_GETHOSTBYNAME_R
+#endif
+
 #ifdef HAVE_GETHOSTBYNAME_R
 
 int ei_init_resolve(void)
