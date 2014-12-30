$NetBSD: patch-lib_hci.c,v 1.1 2014/12/30 08:39:13 plunky Exp $

Not much of the original library is needed.

--- lib/hci.c.orig	2014-12-26 17:54:42.000000000 +0000
+++ lib/hci.c
@@ -71,6 +71,7 @@ static char *hci_bit2str(hci_map *m, uns
 	return str;
 }
 
+#if 0
 static int hci_str2bit(hci_map *map, char *str, unsigned int *val)
 {
 	char *t, *ptr;
@@ -94,6 +95,7 @@ static int hci_str2bit(hci_map *map, cha
 
 	return set;
 }
+#endif
 
 static char *hci_uint2str(hci_map *m, unsigned int val)
 {
@@ -114,6 +116,7 @@ static char *hci_uint2str(hci_map *m, un
 	return str;
 }
 
+#if 0
 static int hci_str2uint(hci_map *map, char *str, unsigned int *val)
 {
 	char *t, *ptr;
@@ -213,6 +216,7 @@ char *hci_dflagstostr(uint32_t flags)
 	}
 	return str;
 }
+#endif
 
 /* HCI packet type mapping */
 static hci_map pkt_type_map[] = {
@@ -234,6 +238,7 @@ static hci_map pkt_type_map[] = {
 	{ NULL }
 };
 
+#if 0
 static hci_map sco_ptype_map[] = {
 	{ "HV1",   0x0001   },
 	{ "HV2",   0x0002   },
@@ -247,12 +252,15 @@ static hci_map sco_ptype_map[] = {
 	{ "3-EV5", HCI_3EV5 },
 	{ NULL }
 };
+#endif
 
 char *hci_ptypetostr(unsigned int ptype)
 {
+	ptype ^= (HCI_2DH1|HCI_2DH3|HCI_2DH5|HCI_3DH1|HCI_3DH3|HCI_3DH5);
 	return hci_bit2str(pkt_type_map, ptype);
 }
 
+#if 0
 int hci_strtoptype(char *str, unsigned int *val)
 {
 	return hci_str2bit(pkt_type_map, str, val);
@@ -267,6 +275,7 @@ int hci_strtoscoptype(char *str, unsigne
 {
 	return hci_str2bit(sco_ptype_map, str, val);
 }
+#endif
 
 /* Link policy mapping */
 static hci_map link_policy_map[] = {
@@ -283,6 +292,7 @@ char *hci_lptostr(unsigned int lp)
 	return hci_bit2str(link_policy_map, lp);
 }
 
+#if 0
 int hci_strtolp(char *str, unsigned int *val)
 {
 	return hci_str2bit(link_policy_map, str, val);
@@ -639,6 +649,7 @@ char *hci_commandstostr(uint8_t *command
 
 	return str;
 }
+#endif
 
 /* Version mapping */
 static hci_map ver_map[] = {
@@ -659,16 +670,19 @@ char *hci_vertostr(unsigned int ver)
 	return hci_uint2str(ver_map, ver);
 }
 
+#if 0
 int hci_strtover(char *str, unsigned int *ver)
 {
 	return hci_str2uint(ver_map, str, ver);
 }
+#endif
 
 char *lmp_vertostr(unsigned int ver)
 {
 	return hci_uint2str(ver_map, ver);
 }
 
+#if 0
 int lmp_strtover(char *str, unsigned int *ver)
 {
 	return hci_str2uint(ver_map, str, ver);
@@ -3113,3 +3127,4 @@ int hci_le_read_remote_features(int dd, 
 
 	return 0;
 }
+#endif
