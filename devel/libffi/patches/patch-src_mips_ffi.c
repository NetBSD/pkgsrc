$NetBSD: patch-src_mips_ffi.c,v 1.3 2024/02/18 20:55:51 adam Exp $

Fixes to support the various NetBSD mips ports.

--- src/mips/ffi.c.orig	2024-02-15 12:54:35.000000000 +0000
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
@@ -723,6 +726,7 @@ static ffi_status ffi_prep_cif_machdep_i
       case FFI_TYPE_SINT64:
 	cif->flags += FFI_TYPE_UINT64 << (FFI_FLAG_BITS * 8);
 	break;
+#endif
       default:
 	cif->flags += cif->rtype->type << (FFI_FLAG_BITS * 8);
 	break;
