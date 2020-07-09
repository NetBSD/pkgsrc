$NetBSD: patch-src_powerpc_ffi__darwin.c,v 1.1 2020/07/09 09:42:58 hauke Exp $

There is no GO support for Darwin/powerpc, so we get undefined symbols.

--- src/powerpc/ffi_darwin.c.orig	2019-10-31 14:49:54.000000000 +0000
+++ src/powerpc/ffi_darwin.c
@@ -909,8 +909,10 @@ ffi_prep_cif_machdep (ffi_cif *cif)
 extern void ffi_call_AIX(extended_cif *, long, unsigned, unsigned *,
 			 void (*fn)(void), void (*fn2)(void));
 
+#if defined(FFI_GO_CLOSURES)
 extern void ffi_call_go_AIX(extended_cif *, long, unsigned, unsigned *,
 			    void (*fn)(void), void (*fn2)(void), void *closure);
+#endif /* FFI_GO_CLOSURES */
 
 extern void ffi_call_DARWIN(extended_cif *, long, unsigned, unsigned *,
 			    void (*fn)(void), void (*fn2)(void), ffi_type*);
@@ -950,6 +952,7 @@ ffi_call (ffi_cif *cif, void (*fn)(void)
     }
 }
 
+#if defined(FFI_GO_CLOSURES)
 void
 ffi_call_go (ffi_cif *cif, void (*fn) (void), void *rvalue, void **avalue,
 	     void *closure)
@@ -981,6 +984,7 @@ ffi_call_go (ffi_cif *cif, void (*fn) (v
       break;
     }
 }
+#endif /* FFI_GO_CLOSURES */
 
 static void flush_icache(char *);
 static void flush_range(char *, int);
@@ -1110,6 +1114,7 @@ ffi_prep_closure_loc (ffi_closure* closu
   return FFI_OK;
 }
 
+#if defined(FFI_GO_CLOSURES)
 ffi_status
 ffi_prep_go_closure (ffi_go_closure* closure,
 		     ffi_cif* cif,
@@ -1133,6 +1138,7 @@ ffi_prep_go_closure (ffi_go_closure* clo
     }
   return FFI_OK;
 }
+#endif /* FFI_GO_CLOSURES */
 
 static void
 flush_icache(char *addr)
@@ -1168,9 +1174,11 @@ ffi_type *
 ffi_closure_helper_DARWIN (ffi_closure *, void *,
 			   unsigned long *, ffi_dblfl *);
 
+#if defined(FFI_GO_CLOSURES)
 ffi_type *
 ffi_go_closure_helper_DARWIN (ffi_go_closure*, void *,
 			      unsigned long *, ffi_dblfl *);
+#endif /* FFI_GO_CLOSURES */
 
 /* Basically the trampoline invokes ffi_closure_ASM, and on
    entry, r11 holds the address of the closure.
@@ -1430,6 +1438,7 @@ ffi_closure_helper_DARWIN (ffi_closure *
 				    closure->user_data, rvalue, pgr, pfr);
 }
 
+#if defined(FFI_GO_CLOSURES)
 ffi_type *
 ffi_go_closure_helper_DARWIN (ffi_go_closure *closure, void *rvalue,
 			      unsigned long *pgr, ffi_dblfl *pfr)
@@ -1437,4 +1446,4 @@ ffi_go_closure_helper_DARWIN (ffi_go_clo
   return ffi_closure_helper_common (closure->cif, closure->fun,
 				    closure, rvalue, pgr, pfr);
 }
-
+#endif /* FFI_GO_CLOSURES */
