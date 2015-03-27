$NetBSD: patch-config_amanda_tape.m4,v 1.1 2015/03/27 23:45:29 gdt Exp $

This patch is from upstream.  It resolves a failure to compile in tape
support; without including sys/types.h and sys/time.h, sys/tape.h
generates an error on NetBSD.

--- config/amanda/tape.m4.orig	2012-02-21 11:36:49.000000000 +0000
+++ config/amanda/tape.m4
@@ -34,6 +34,10 @@ AC_DEFUN([AMANDA_TAPE_DEVICE], [
     # check for MTIOCTOP, an indicator of POSIX tape support
     AC_CACHE_CHECK([for MTIOCTOP], amanda_cv_HAVE_MTIOCTOP,[
 	AC_TRY_COMPILE([
+#include <sys/types.h>
+#ifdef HAVE_SYS_TIME_H
+# include <sys/time.h>
+# endif
 #ifdef HAVE_SYS_TAPE_H
 # include <sys/tape.h>
 #endif
@@ -66,6 +70,9 @@ AC_DEFUN([AMANDA_TAPE_DEVICE], [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
 #include <stdio.h>
 #include <sys/types.h>
+#ifdef HAVE_SYS_TIME_H
+# include <sys/time.h>
+#endif
 #include <sys/mtio.h>
 	]], [[
 	    struct mtget buf;
@@ -85,6 +92,9 @@ AC_DEFUN([AMANDA_TAPE_DEVICE], [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
 #include <stdio.h>
 #include <sys/types.h>
+#ifdef HAVE_SYS_TIME_H
+# include <sys/time.h>
+#endif
 #include <sys/mtio.h>
 	]], [[
 	    struct mtget buf;
@@ -139,6 +149,9 @@ AC_DEFUN([AMANDA_TAPE_DEVICE], [
     AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
 #include <stdio.h>
 #include <sys/types.h>
+#ifdef HAVE_SYS_TIME_H
+# include <sys/time.h>
+#endif
 #include <sys/mtio.h>
 	]], [[
 	    struct mtget buf;
