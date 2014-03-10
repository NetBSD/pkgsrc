$NetBSD: patch-generic_tclPosixStr.c,v 1.1 2014/03/10 14:20:44 taca Exp $

Carried over from TCL 8.4

--- generic/tclPosixStr.c.orig	2012-07-16 11:57:05.000000000 +0000
+++ generic/tclPosixStr.c
@@ -335,7 +335,7 @@ Tcl_ErrnoId(void)
 #if defined(EOPNOTSUPP) &&  (!defined(ENOTSUP) || (ENOTSUP != EOPNOTSUPP))
     case EOPNOTSUPP: return "EOPNOTSUPP";
 #endif
-#if defined(EOVERFLOW) && (!defined(EFBIG) || (EOVERFLOW != EFBIG)) && (!defined(EINVAL) || (EOVERFLOW != EINVAL))
+#if defined(EOVERFLOW) && (!defined(EFBIG) || (EOVERFLOW != EFBIG)) && (!defined(EINVAL) || (EOVERFLOW != EINVAL)) && (!defined(ERANGE) || (EOVERFLOW != ERANGE))
     case EOVERFLOW: return "EOVERFLOW";
 #endif
 #ifdef EPERM
@@ -783,7 +783,7 @@ Tcl_ErrnoMsg(
 #if defined(EOPNOTSUPP) &&  (!defined(ENOTSUP) || (ENOTSUP != EOPNOTSUPP))
     case EOPNOTSUPP: return "operation not supported on socket";
 #endif
-#if defined(EOVERFLOW) && (!defined(EFBIG) || (EOVERFLOW != EFBIG)) && (!defined(EINVAL) || (EOVERFLOW != EINVAL))
+#if defined(EOVERFLOW) && (!defined(EFBIG) || (EOVERFLOW != EFBIG)) && (!defined(EINVAL) || (EOVERFLOW != EINVAL)) && (!defined(ERANGE) || (EOVERFLOW != ERANGE))
     case EOVERFLOW: return "file too big";
 #endif
 #ifdef EPERM
