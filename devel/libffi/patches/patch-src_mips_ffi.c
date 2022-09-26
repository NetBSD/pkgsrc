$NetBSD: patch-src_mips_ffi.c,v 1.2 2022/09/26 18:43:48 adam Exp $

Fixes to support the various NetBSD mips ports.

--- src/mips/ffi.c.orig	2022-09-19 09:57:23.000000000 +0000
+++ src/mips/ffi.c
@@ -532,6 +532,7 @@ static ffi_status ffi_prep_cif_machdep_i
               cif->flags += t->type << (arg_reg * FFI_FLAG_BITS);
 	    arg_reg++;
 	    break;
+#ifdef __mips64
           case FFI_TYPE_LONGDOUBLE:
             /* Align it.  */
             arg_reg = FFI_ALIGN(arg_reg, 2);
@@ -605,6 +606,7 @@ static ffi_status ffi_prep_cif_machdep_i
 		break;
 	      }
 	    break;
+#endif
 
 	  case FFI_TYPE_STRUCT:
             loc = arg_reg * FFI_SIZEOF_ARG;
@@ -666,6 +668,7 @@ static ffi_status ffi_prep_cif_machdep_i
 	  cif->flags += cif->rtype->type << (FFI_FLAG_BITS * 8);
 	break;
 
+#ifdef __mips64
       case FFI_TYPE_LONGDOUBLE:
 	/* Long double is returned as if it were a struct containing
 	   two doubles.  */
@@ -715,6 +718,7 @@ static ffi_status ffi_prep_cif_machdep_i
 	    }
 	  break;
 	}
+#endif
       default:
 	cif->flags += FFI_TYPE_INT << (FFI_FLAG_BITS * 8);
 	break;
