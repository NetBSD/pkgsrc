$NetBSD: patch-g95spec.c,v 1.1 2013/09/20 23:06:07 joerg Exp $

Add rpath to libf95.

--- g95spec.c.orig	2008-10-15 14:41:42.000000000 +0000
+++ g95spec.c
@@ -527,6 +527,8 @@ For more information about these matters
 	case 1:
 	    if (need_math)
 		append_arg (MATH_LIBRARY);
+	case 2:
+	    append_arg (FORTRAN_LIBRARY_RPATH);
 	default:
 	    break;
 	}
