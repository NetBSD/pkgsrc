$NetBSD: patch-src_AddressSpace.hpp,v 1.1 2016/03/28 12:56:03 kamil Exp $

Fixed in 3.9.

--- src/AddressSpace.hpp.orig	2015-10-16 19:40:09.000000000 +0000
+++ src/AddressSpace.hpp
@@ -35,7 +35,7 @@ namespace libunwind {
 #include "Registers.hpp"
 
 #if _LIBUNWIND_ARM_EHABI
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 
 typedef void *_Unwind_Ptr;
 
@@ -61,7 +61,8 @@ extern EHTEntry __exidx_end;
 #endif // !defined(_LIBUNWIND_IS_BAREMETAL)
 #endif // _LIBUNWIND_ARM_EHABI
 
-#if defined(__CloudABI__) || defined(__FreeBSD__) || defined(__linux__)
+#if defined(__CloudABI__) || defined(__FreeBSD__) || defined(__linux__) ||    \
+    defined(__NetBSD__)
 #if _LIBUNWIND_SUPPORT_DWARF_UNWIND && _LIBUNWIND_SUPPORT_DWARF_INDEX
 #include <link.h>
 // Macro for machine-independent access to the ELF program headers. This
