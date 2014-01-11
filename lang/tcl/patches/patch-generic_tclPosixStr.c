$NetBSD: patch-generic_tclPosixStr.c,v 1.3 2014/01/11 14:41:05 adam Exp $

Carried over from TCL 8.4

--- generic/tclPosixStr.c.orig	2013-09-19 19:04:14.000000000 +0000
+++ generic/tclPosixStr.c
@@ -344,7 +344,7 @@ Tcl_ErrnoId(void)
 #ifdef EOTHER
     case EOTHER: return "EOTHER";
 #endif
-#if defined(EOVERFLOW) && (!defined(EFBIG) || (EOVERFLOW != EFBIG)) && (!defined(EINVAL) || (EOVERFLOW != EINVAL))
+#if defined(EOVERFLOW) && (!defined(EFBIG) || (EOVERFLOW != EFBIG)) && (!defined(EINVAL) || (EOVERFLOW != EINVAL)) && (!defined(ERANGE) || (EOVERFLOW != ERANGE))
     case EOVERFLOW: return "EOVERFLOW";
 #endif
 #ifdef EOWNERDEAD
@@ -804,7 +804,7 @@ Tcl_ErrnoMsg(
 #ifdef EOTHER
     case EOTHER: return "other error";
 #endif
-#if defined(EOVERFLOW) && (!defined(EFBIG) || (EOVERFLOW != EFBIG)) && (!defined(EINVAL) || (EOVERFLOW != EINVAL))
+#if defined(EOVERFLOW) && (!defined(EFBIG) || (EOVERFLOW != EFBIG)) && (!defined(EINVAL) || (EOVERFLOW != EINVAL)) && (!defined(ERANGE) || (EOVERFLOW != ERANGE))
     case EOVERFLOW: return "file too big";
 #endif
 #ifdef EOWNERDEAD
