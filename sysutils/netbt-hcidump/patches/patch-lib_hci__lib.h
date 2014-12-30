$NetBSD: patch-lib_hci__lib.h,v 1.1 2014/12/30 08:39:13 plunky Exp $

Not much of the original library is needed.

--- lib/hci_lib.h.orig	2014-12-26 17:54:42.000000000 +0000
+++ lib/hci_lib.h
@@ -30,6 +30,7 @@
 extern "C" {
 #endif
 
+#if 0
 struct hci_request {
 	uint16_t ogf;
 	uint16_t ocf;
@@ -149,11 +150,15 @@ char *hci_bustostr(int bus);
 char *hci_typetostr(int type);
 char *hci_dtypetostr(int type);
 char *hci_dflagstostr(uint32_t flags);
+#endif
 char *hci_ptypetostr(unsigned int ptype);
+#if 0
 int hci_strtoptype(char *str, unsigned int *val);
 char *hci_scoptypetostr(unsigned int ptype);
 int hci_strtoscoptype(char *str, unsigned int *val);
+#endif
 char *hci_lptostr(unsigned int ptype);
+#if 0
 int hci_strtolp(char *str, unsigned int *val);
 char *hci_lmtostr(unsigned int ptype);
 int hci_strtolm(char *str, unsigned int *val);
@@ -161,9 +166,13 @@ int hci_strtolm(char *str, unsigned int 
 char *hci_cmdtostr(unsigned int cmd);
 char *hci_commandstostr(uint8_t *commands, char *pref, int width);
 
+#endif
 char *hci_vertostr(unsigned int ver);
+#if 0
 int hci_strtover(char *str, unsigned int *ver);
+#endif
 char *lmp_vertostr(unsigned int ver);
+#if 0
 int lmp_strtover(char *str, unsigned int *ver);
 char *pal_vertostr(unsigned int ver);
 int pal_strtover(char *str, unsigned int *ver);
@@ -234,6 +243,7 @@ static inline int hci_filter_test_opcode
 {
 	return (f->opcode == opcode);
 }
+#endif
 
 #ifdef __cplusplus
 }
