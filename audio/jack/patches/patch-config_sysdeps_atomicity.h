$NetBSD: patch-config_sysdeps_atomicity.h,v 1.1 2019/06/15 08:21:32 adam Exp $

--- config/sysdeps/atomicity.h.orig	2008-11-11 17:36:35.000000000 -0500
+++ config/sysdeps/atomicity.h
@@ -1,7 +1,11 @@
 #ifndef _jack_sysdep_atomicity_h_
 #define _jack_sysdep_atomicity_h_
 
-#if defined(__i386__)
+#if defined(HAVE_NETBSD_ATOMIC_OPS)
+
+#include <config/os/netbsd/atomicity.h>
+
+#elif defined(__i386__)
 
 #include <config/cpu/i386/atomicity.h>
 
@@ -15,6 +19,10 @@
 
 #include <config/cpu/powerpc/atomicity.h>
 
+#elif defined(__mips__) || defined(__mips64__)
+
+#include <config/cpu/mips/atomicity.h>
+
 #else
 
 #include <config/cpu/generic/atomicity.h>
