$NetBSD: patch-src_include_efivar_efivar-types.h,v 1.1 2024/08/20 15:29:32 bsiegert Exp $

--- src/include/efivar/efivar-types.h.orig	2022-10-05 17:03:05.000000000 +0000
+++ src/include/efivar/efivar-types.h
@@ -90,6 +90,37 @@ typedef struct {
 #define EFI_UNSPECIFIED_TIMEZONE        ((uint16_t)0x07ff)
 #endif /* !defined(EFIVAR_NO_EFI_TIME_T) || EFIVAR_NO_EFI_TIME_T */
 
+/*
+ * /usr/include/sys/efiio.h provides the same definitions but of `int` type,
+ * prefer definitions from this header as somewhat more correct.  This is
+ * unlikely to have a real difference and is mostly to avoid warnings on
+ * redefining macros.
+ */
+#ifdef EFI_VARIABLE_NON_VOLATILE
+#undef EFI_VARIABLE_NON_VOLATILE
+#endif
+#ifdef EFI_VARIABLE_BOOTSERVICE_ACCESS
+#undef EFI_VARIABLE_BOOTSERVICE_ACCESS
+#endif
+#ifdef EFI_VARIABLE_RUNTIME_ACCESS
+#undef EFI_VARIABLE_RUNTIME_ACCESS
+#endif
+#ifdef EFI_VARIABLE_HARDWARE_ERROR_RECORD
+#undef EFI_VARIABLE_HARDWARE_ERROR_RECORD
+#endif
+#ifdef EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS
+#undef EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS
+#endif
+#ifdef EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS
+#undef EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS
+#endif
+#ifdef EFI_VARIABLE_APPEND_WRITE
+#undef EFI_VARIABLE_APPEND_WRITE
+#endif
+#ifdef EFI_VARIABLE_ENHANCED_AUTHENTICATED_ACCESS
+#undef EFI_VARIABLE_ENHANCED_AUTHENTICATED_ACCESS
+#endif
+
 #define EFI_VARIABLE_NON_VOLATILE				((uint64_t)0x0000000000000001)
 #define EFI_VARIABLE_BOOTSERVICE_ACCESS				((uint64_t)0x0000000000000002)
 #define EFI_VARIABLE_RUNTIME_ACCESS				((uint64_t)0x0000000000000004)
