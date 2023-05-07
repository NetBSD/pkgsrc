$NetBSD: patch-lib_internal.h,v 1.3 2023/05/07 10:20:44 wiz Exp $

no symbol versioning available on SunOS

--- lib/internal.h.orig	2023-03-05 13:45:24.000000000 +0000
+++ lib/internal.h
@@ -18,6 +18,17 @@
 #define STATIC_ALIAS(_decl, _for) _decl VERSIONED_ABI { return _for; }
 #define DEFINE_ALIAS(_decl, _for)
 #define SYMBOL_VERSION(_int, _ext)
+#elif defined(__sun__)
+#define STATIC_ALIAS(_decl, _for)
+#define DEFINE_ALIAS(_decl, _for)
+#define SYMBOL_VERSION(_int, _ext)
+#define pci_fill_info_v35 pci_fill_info
+#define pci_filter_init_v38 pci_filter_init
+#define pci_fill_info_v38 pci_fill_info
+#define pci_init_v35 pci_init
+#define pci_filter_parse_slot_v38 pci_filter_parse_slot
+#define pci_filter_parse_id_v38 pci_filter_parse_id
+#define pci_filter_match_v38 pci_filter_match
 #else
 #define STATIC_ALIAS(_decl, _for)
 #define DEFINE_ALIAS(_decl, _for) extern _decl __attribute__((alias(#_for))) VERSIONED_ABI
