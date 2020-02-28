$NetBSD: patch-include_ffi__common.h,v 1.1 2020/02/28 15:44:36 tnn Exp $

Declaring ffi_data_to_code_pointer as FFI_HIDDEN is redundant because an
ld script is used. It also breaks the build on aarch64:

/usr/bin/ld: src/aarch64/.libs/ffi.o: in function `ffi_prep_closure_loc':
ffi.c:(.text+0x6ac): undefined reference to `ffi_data_to_code_pointer'
/usr/bin/ld: .libs/libffi.so.7.1.0: hidden symbol `ffi_data_to_code_pointer' isn't defined
/usr/bin/ld: final link failed: bad value

--- include/ffi_common.h.orig	2019-10-31 14:49:54.000000000 +0000
+++ include/ffi_common.h
@@ -101,7 +101,7 @@ ffi_status ffi_prep_cif_core(ffi_cif *ci
 
 /* Translate a data pointer to a code pointer.  Needed for closures on
    some targets.  */
-void *ffi_data_to_code_pointer (void *data) FFI_HIDDEN;
+void *ffi_data_to_code_pointer (void *data);
 
 /* Extended cif, used in callback from assembly routine */
 typedef struct
