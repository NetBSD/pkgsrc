$NetBSD: patch-src_libstatgrab_tools.h,v 1.2 2020/05/22 13:45:11 joerg Exp $

Add include for LOCK_SH
--- src/libstatgrab/tools.h.orig	2019-07-16 16:05:37.000000000 +0000
+++ src/libstatgrab/tools.h
@@ -36,6 +36,10 @@
 # include <sys/stat.h>
 #endif
 
+#if defined(__sun)
+#include <sys/file.h>
+#endif
+
 #include <stdio.h>
 #ifdef STDC_HEADERS
 # include <assert.h>
@@ -252,6 +256,9 @@ extern "C" strcasecmp(const char *s1, co
 #ifdef HAVE_UVM_UVM_H
 # include <uvm/uvm.h>
 #endif
+#ifdef HAVE_UVM_UVM_EXTERN_H
+# include <uvm/uvm_extern.h>
+#endif
 #ifdef HAVE_SYS_VMMETER_H
 #include <sys/vmmeter.h>
 #endif
