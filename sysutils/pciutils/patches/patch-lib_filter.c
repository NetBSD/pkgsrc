$NetBSD: patch-lib_filter.c,v 1.1 2022/05/13 11:41:57 wiz Exp $

/tmp//ccMwJMwZ.s: Assembler messages:
/tmp//ccMwJMwZ.s:976: Error: multiple versions [`pci_filter_init@@LIBPCI_3.8'|`pci_filter_init@LIBPCI_3.3'] for symbol `pci_filter_init_v38'
/tmp//ccMwJMwZ.s:978: Error: multiple versions [`pci_filter_parse_slot@@LIBPCI_3.8'|`pci_filter_parse_slot@LIBPCI_3.3'] for symbol `pci_filter_parse_slot_v38'
/tmp//ccMwJMwZ.s:980: Error: multiple versions [`pci_filter_parse_id@@LIBPCI_3.8'|`pci_filter_parse_id@LIBPCI_3.3'] for symbol `pci_filter_parse_id_v38'
/tmp//ccMwJMwZ.s:982: Error: multiple versions [`pci_filter_match@@LIBPCI_3.8'|`pci_filter_match@LIBPCI_3.3'] for symbol `pci_filter_match_v38'
# cc -Wall -W -Wno-parentheses -Wstrict-prototypes -Wmissing-prototypes   -c -o filter.o filter.c
/tmp//ccfA72Ke.s: Assembler messages:
/tmp//ccfA72Ke.s:976: Error: multiple versions [`pci_filter_init@@LIBPCI_3.8'|`pci_filter_init@LIBPCI_3.3'] for symbol `pci_filter_init_v38'
/tmp//ccfA72Ke.s:978: Error: multiple versions [`pci_filter_parse_slot@@LIBPCI_3.8'|`pci_filter_parse_slot@LIBPCI_3.3'] for symbol `pci_filter_parse_slot_v38'
/tmp//ccfA72Ke.s:980: Error: multiple versions [`pci_filter_parse_id@@LIBPCI_3.8'|`pci_filter_parse_id@LIBPCI_3.3'] for symbol `pci_filter_parse_id_v38'
/tmp//ccfA72Ke.s:982: Error: multiple versions [`pci_filter_match@@LIBPCI_3.8'|`pci_filter_match@LIBPCI_3.3'] for symbol `pci_filter_match_v38'


--- lib/filter.c.orig	2022-04-18 16:46:38.000000000 +0000
+++ lib/filter.c
@@ -304,20 +304,20 @@ pci_filter_match_v30(struct pci_filter_v
 
 STATIC_ALIAS(void pci_filter_init(struct pci_access *a, struct pci_filter *f), pci_filter_init_v38(a, f));
 SYMBOL_VERSION(pci_filter_init_v30, pci_filter_init@LIBPCI_3.0);
-SYMBOL_VERSION(pci_filter_init_v38, pci_filter_init@LIBPCI_3.3);
+//SYMBOL_VERSION(pci_filter_init_v38, pci_filter_init@LIBPCI_3.3);
 SYMBOL_VERSION(pci_filter_init_v38, pci_filter_init@@LIBPCI_3.8);
 
 STATIC_ALIAS(char *pci_filter_parse_slot(struct pci_filter *f, char *str), pci_filter_parse_slot_v38(f, str));
 SYMBOL_VERSION(pci_filter_parse_slot_v30, pci_filter_parse_slot@LIBPCI_3.0);
-SYMBOL_VERSION(pci_filter_parse_slot_v38, pci_filter_parse_slot@LIBPCI_3.3);
+//SYMBOL_VERSION(pci_filter_parse_slot_v38, pci_filter_parse_slot@LIBPCI_3.3);
 SYMBOL_VERSION(pci_filter_parse_slot_v38, pci_filter_parse_slot@@LIBPCI_3.8);
 
 STATIC_ALIAS(char *pci_filter_parse_id(struct pci_filter *f, char *str), pci_filter_parse_id_v38(f, str));
 SYMBOL_VERSION(pci_filter_parse_id_v30, pci_filter_parse_id@LIBPCI_3.0);
-SYMBOL_VERSION(pci_filter_parse_id_v38, pci_filter_parse_id@LIBPCI_3.3);
+//SYMBOL_VERSION(pci_filter_parse_id_v38, pci_filter_parse_id@LIBPCI_3.3);
 SYMBOL_VERSION(pci_filter_parse_id_v38, pci_filter_parse_id@@LIBPCI_3.8);
 
 STATIC_ALIAS(int pci_filter_match(struct pci_filter *f, struct pci_dev *d), pci_filter_match_v38(f, d));
 SYMBOL_VERSION(pci_filter_match_v30, pci_filter_match@LIBPCI_3.0);
-SYMBOL_VERSION(pci_filter_match_v38, pci_filter_match@LIBPCI_3.3);
+//SYMBOL_VERSION(pci_filter_match_v38, pci_filter_match@LIBPCI_3.3);
 SYMBOL_VERSION(pci_filter_match_v38, pci_filter_match@@LIBPCI_3.8);
