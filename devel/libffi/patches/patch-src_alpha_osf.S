$NetBSD: patch-src_alpha_osf.S,v 1.2 2016/01/25 17:56:39 jperkin Exp $

Band-aid update of the alpha asm code to make it compile past the addition
of type complex. Someone with clue on the alpha ELF ABI should provide
real support for complex arguments.

--- src/alpha/osf.S.orig	2014-11-08 12:47:24.000000000 +0000
+++ src/alpha/osf.S
@@ -279,6 +279,7 @@ $load_table:
 	.gprel32 $load_64	# FFI_TYPE_SINT64
 	.gprel32 $load_none	# FFI_TYPE_STRUCT
 	.gprel32 $load_64	# FFI_TYPE_POINTER
+	.gprel32 $load_none	# FFI_TYPE_COMPLEX
 
 /* Assert that the table above is in sync with ffi.h.  */
 
@@ -294,7 +295,8 @@ $load_table:
 	|| FFI_TYPE_SINT64 != 12	\
 	|| FFI_TYPE_STRUCT != 13	\
 	|| FFI_TYPE_POINTER != 14	\
-	|| FFI_TYPE_LAST != 14
+	|| FFI_TYPE_COMPLEX != 15	\
+	|| FFI_TYPE_LAST != 15
 #error "osf.S out of sync with ffi.h"
 #endif
 
