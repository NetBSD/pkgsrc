$NetBSD: patch-generic_tclPosixStr.c,v 1.1 2011/11/01 20:08:12 bsiegert Exp $

--- generic/tclPosixStr.c.orig	Mon May 27 10:13:59 2002
+++ generic/tclPosixStr.c
@@ -339,7 +339,7 @@ Tcl_ErrnoId()
 #if defined(EOPNOTSUPP) &&  (!defined(ENOTSUP) || (ENOTSUP != EOPNOTSUPP))
 	case EOPNOTSUPP: return "EOPNOTSUPP";
 #endif
-#if defined(EOVERFLOW) && ( !defined(EFBIG) || (EOVERFLOW != EFBIG) ) && ( !defined(EINVAL) || (EOVERFLOW != EINVAL) )
+#if defined(EOVERFLOW) && ( !defined(EFBIG) || (EOVERFLOW != EFBIG) ) && ( !defined(EINVAL) || (EOVERFLOW != EINVAL) ) && ( !defined(ERANGE) || (EOVERFLOW != ERANGE) )
         case EOVERFLOW: return "EOVERFLOW";
 #endif
 #ifdef EPERM
@@ -789,7 +789,7 @@ Tcl_ErrnoMsg(err)
 #if defined(EOPNOTSUPP) &&  (!defined(ENOTSUP) || (ENOTSUP != EOPNOTSUPP))
 	case EOPNOTSUPP: return "operation not supported on socket";
 #endif
-#if defined(EOVERFLOW) && ( !defined(EFBIG) || (EOVERFLOW != EFBIG) ) && ( !defined(EINVAL) || (EOVERFLOW != EINVAL) )
+#if defined(EOVERFLOW) && ( !defined(EFBIG) || (EOVERFLOW != EFBIG) ) && ( !defined(EINVAL) || (EOVERFLOW != EINVAL) ) && ( !defined(ERANGE) || (EOVERFLOW != ERANGE) )
         case EOVERFLOW: return "file too big";
 #endif
 #ifdef EPERM
