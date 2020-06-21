$NetBSD: patch-include_refclock__atom.h,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- include/refclock_atom.h.orig	2011-10-09 05:08:20.000000000 +0000
+++ include/refclock_atom.h
@@ -1,8 +1,10 @@
 /*
  * Definitions for the atom driver and its friends
  */
-#undef NANOSECOND	/* some systems define it differently */
+#ifndef NANOSECOND
 #define NANOSECOND	1000000000 /* one second (ns) */
+#endif
+#define RANGEGATE	500000  /* range gate (ns) */
 
 struct refclock_atom {
 	pps_handle_t handle;
