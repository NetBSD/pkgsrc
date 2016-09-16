$NetBSD: patch-libr_debug_p_debug__native.c,v 1.1 2016/09/16 14:46:25 jperkin Exp $

Support SunOS.

--- libr/debug/p/debug_native.c.orig	2016-05-24 23:34:34.000000000 +0000
+++ libr/debug/p/debug_native.c
@@ -22,7 +22,7 @@ static int r_debug_native_reg_write (RDe
 
 #if __UNIX__ || __CYGWIN__
 # include <errno.h>
-# if !defined (__HAIKU__) && !defined (__CYGWIN__)
+# if !defined (__HAIKU__) && !defined (__CYGWIN__) && !defined (__sun)
 #  include <sys/ptrace.h>
 # endif
 # include <sys/wait.h>
