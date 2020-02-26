$NetBSD: patch-src_mips_ffi.c,v 1.1 2020/02/26 19:15:44 adam Exp $

Fixes to support the various NetBSD mips ports.

--- src/mips/ffi.c.orig	2019-10-31 14:49:54.000000000 +0000
+++ src/mips/ffi.c
@@ -476,6 +476,7 @@ static ffi_status ffi_prep_cif_machdep_i
               ((cif->arg_types)[index]->type << (arg_reg * FFI_FLAG_BITS));
 	    arg_reg++;
 	    break;
+#ifdef __mips64
           case FFI_TYPE_LONGDOUBLE:
             /* Align it.  */
             arg_reg = FFI_ALIGN(arg_reg, 2);
@@ -494,7 +495,7 @@ static ffi_status ffi_prep_cif_machdep_i
 		arg_reg++;
 	      }
             break;
-
+#endif
 	  case FFI_TYPE_STRUCT:
             loc = arg_reg * FFI_SIZEOF_ARG;
 	    cif->flags += calc_n32_struct_flags(soft_float || index >= nfixedargs,
@@ -556,6 +557,7 @@ static ffi_status ffi_prep_cif_machdep_i
 	  cif->flags += cif->rtype->type << (FFI_FLAG_BITS * 8);
 	break;
 
+#ifdef __mips64
       case FFI_TYPE_LONGDOUBLE:
 	/* Long double is returned as if it were a struct containing
 	   two doubles.  */
@@ -572,6 +574,7 @@ static ffi_status ffi_prep_cif_machdep_i
 					      << (4 + (FFI_FLAG_BITS * 8));
 	  }
 	break;
+#endif
       default:
 	cif->flags += FFI_TYPE_INT << (FFI_FLAG_BITS * 8);
 	break;
