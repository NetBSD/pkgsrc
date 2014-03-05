$NetBSD: patch-tnm_snmp_tnmMibQuery.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/snmp/tnmMibQuery.c~	1999-12-09 16:17:00.000000000 +0100
+++ tnm/snmp/tnmMibQuery.c	2014-03-04 23:18:46.000000000 +0100
@@ -57,29 +57,29 @@
  * Forward declarations for procedures defined later in this file:
  */
 
-static char *
-FormatOctetTC		_ANSI_ARGS_((char *val, char *fmt));
+static const char *
+FormatOctetTC		_ANSI_ARGS_((const char *val, char *fmt));
 
-static char *
-FormatIntTC		_ANSI_ARGS_((char *val, char *fmt));
+static const char *
+FormatIntTC		_ANSI_ARGS_((const char *val, char *fmt));
 
-static char *
-FormatTimeTicks		_ANSI_ARGS_((char *val));
+static const char *
+FormatTimeTicks		_ANSI_ARGS_((const char *val));
 
-static char *
-FormatOID		_ANSI_ARGS_((char *val));
+static const char *
+FormatOID		_ANSI_ARGS_((const char *val));
 
-static char *
-ScanOctetTC		_ANSI_ARGS_((char *val, char *fmt));
+static const char *
+ScanOctetTC		_ANSI_ARGS_((const char *val, char *fmt));
 
-static char *
-ScanIntTC		_ANSI_ARGS_((char *val, char *fmt));
+static const char *
+ScanIntTC		_ANSI_ARGS_((const char *val, char *fmt));
 
-static char *
-ScanTimeTicks		_ANSI_ARGS_((char *val));
+static const char *
+ScanTimeTicks		_ANSI_ARGS_((const char *val));
 
 static void
-GetMibPath		_ANSI_ARGS_((Tnm_MibNode *nodePtr, char *soid));
+GetMibPath		_ANSI_ARGS_((const Tnm_MibNode *nodePtr, char *soid));
 
 static void
 FormatUnsigned		_ANSI_ARGS_((unsigned u, char *s));
@@ -141,7 +141,7 @@
 
 static void
 GetMibPath(nodePtr, s) 
-    Tnm_MibNode *nodePtr;
+    const Tnm_MibNode *nodePtr;
     char *s;
 {
     if (! nodePtr) return;
@@ -173,7 +173,7 @@
 
 static void
 GetMibPath2(nodePtr, oid, oidLen) 
-    Tnm_MibNode *nodePtr;
+    const Tnm_MibNode *nodePtr;
     Tnm_Oid *oid;
     int *oidLen;
 {
@@ -203,7 +203,7 @@
 
 int
 Tnm_MibNodeGetOid(nodePtr, oid)
-    Tnm_MibNode *nodePtr;
+    const Tnm_MibNode *nodePtr;
     Tnm_Oid *oid;
 {
     int len = 0;
@@ -230,9 +230,9 @@
  *----------------------------------------------------------------------
  */
 
-char*
+const char*
 Tnm_MibGetOid(label, exact)
-    char *label;
+    const char *label;
     int exact;
 {
     char *expanded = Tnm_HexToOid(label);
@@ -275,7 +275,7 @@
 
 char*
 Tnm_MibGetName(label, exact)
-    char *label;
+    const char *label;
     int exact;
 {
     char *expanded = Tnm_HexToOid(label);
@@ -321,7 +321,7 @@
 
 char*
 Tnm_MibGetDescription(name, exact)
-    char *name;
+    const char *name;
     int exact;
 {
     FILE *fp;
@@ -407,7 +407,7 @@
 
 char*
 Tnm_MibGetSucc(name)
-    char *name;
+    const char *name;
 {
     Tnm_MibNode *nodePtr;
     int retoid;
@@ -467,7 +467,7 @@
 
 char*
 Tnm_MibGetSyntax(name, exact)
-    char *name;
+    const char *name;
     int exact;
 {
     Tnm_MibNode *nodePtr = Tnm_MibFindNode(name, NULL, exact);
@@ -517,7 +517,7 @@
 
 int
 Tnm_MibGetBaseSyntax(name, exact)
-    char *name;
+    const char *name;
     int exact;
 {
     int syntax = ASN1_OTHER;
@@ -561,7 +561,7 @@
 
 char*
 Tnm_MibGetAccess(name, exact)
-    char *name;
+    const char *name;
     int exact;
 {
     Tnm_MibNode *nodePtr = Tnm_MibFindNode(name, NULL, exact);
@@ -594,7 +594,7 @@
 
 char*
 Tnm_MibGetMacro(name, exact)
-    char *name;
+    const char *name;
     int exact;
 {
     Tnm_MibNode *nodePtr = Tnm_MibFindNode(name, NULL, exact);
@@ -627,7 +627,7 @@
 
 char*
 Tnm_MibGetModule(name, exact)
-    char *name;
+    const char *name;
     int exact;
 {
     Tnm_MibNode *nodePtr = Tnm_MibFindNode(name, NULL, exact);
@@ -657,9 +657,9 @@
  *----------------------------------------------------------------------
  */
 
-static char *
+static const char *
 FormatOctetTC(val, fmt)
-    char *val;
+    const char *val;
     char *fmt;
 {
     int pfx, have_pfx;			/* counter prefix */
@@ -850,9 +850,9 @@
  *----------------------------------------------------------------------
  */
 
-static char *
+static const char *
 FormatIntTC(val, fmt)
-    char *val;
+    const char *val;
     char *fmt;
 {
     static char *ret = NULL;
@@ -988,9 +988,9 @@
  *----------------------------------------------------------------------
  */
 
-static char *
+static const char *
 FormatTimeTicks(value)
-    char *value;
+    const char *value;
 {
     u_int d, h, m, s, f;
     static char buf[80];
@@ -1026,9 +1026,9 @@
  *----------------------------------------------------------------------
  */
 
-static char *
+static const char *
 FormatOID(value)
-    char *value;
+    const char *value;
 {
     Tnm_MibNode *nodePtr = Tnm_MibFindNode(value, NULL, 1);
     static char *buffer = NULL;
@@ -1069,9 +1069,9 @@
  *----------------------------------------------------------------------
  */
 
-static char *
+static const char *
 ScanOctetTC(val, fmt)
-    char *val;
+    const char *val;
     char *fmt;
 {
     int pfx, have_pfx;			/* counter prefix */
@@ -1261,9 +1261,9 @@
  *----------------------------------------------------------------------
  */
 
-static char *
+static const char *
 ScanIntTC(val, fmt)
-    char *val;
+    const char *val;
     char *fmt;
 {
     static char ret [100];
@@ -1367,9 +1367,9 @@
  *----------------------------------------------------------------------
  */
 
-static char *
+static const char *
 ScanTimeTicks(value)
-    char *value;
+    const char *value;
 {
     u_int u, d, h, m, s, f, n;
     static char str[20];
@@ -1419,11 +1419,11 @@
  *----------------------------------------------------------------------
  */
 
-char *
+const char *
 Tnm_MibFormat(name, exact, value)
-    char *name;
+    const char *name;
     int exact;
-    char *value;
+    const char *value;
 {
     Tnm_MibNode *nodePtr = Tnm_MibFindNode(name, NULL, exact);
    
@@ -1447,7 +1447,7 @@
 	     */
 
 	    if (nodePtr->tc->displayHint) {
-		char *ret = NULL;
+		const char *ret = NULL;
 		if (nodePtr->syntax == ASN1_OCTET_STRING) {
 		    ret = FormatOctetTC(value, nodePtr->tc->displayHint);
 		} else if (nodePtr->syntax == ASN1_INTEGER) {
@@ -1489,11 +1489,11 @@
  *----------------------------------------------------------------------
  */
 
-char*
+const char*
 Tnm_MibScan(name, exact, value)
-    char *name;
+    const char *name;
     int exact;
-    char *value;
+    const char *value;
 {
     Tnm_MibNode *nodePtr = Tnm_MibFindNode(name, NULL, exact);
     
@@ -1518,7 +1518,7 @@
 	     */
 
             if (nodePtr->tc->displayHint) {
-		char *ret = NULL;
+	        const char *ret = NULL;
 		if (nodePtr->syntax == ASN1_OCTET_STRING) {
 		    ret = ScanOctetTC(value, nodePtr->tc->displayHint);
 		} else if (nodePtr->syntax == ASN1_INTEGER) {
@@ -1563,7 +1563,7 @@
 
 char*
 Tnm_MibGetTC(name, exact)
-    char *name;
+    const char *name;
     int exact;
 {
     Tnm_MibNode *nodePtr = Tnm_MibFindNode(name, NULL, exact);
@@ -1635,7 +1635,7 @@
 
 char*
 Tnm_MibGetFile(name, exact)
-    char *name;
+    const char *name;
     int exact;
 {
     Tnm_MibNode *nodePtr = Tnm_MibFindNode(name, NULL, exact);
@@ -1669,7 +1669,7 @@
 
 char*
 Tnm_MibGetIndex(name, exact)
-    char *name;
+    const char *name;
     int exact;
 {
     Tnm_MibNode *nodePtr;
@@ -1712,7 +1712,7 @@
 
 char*
 Tnm_MibGetParent(name, exact)
-    char *name;
+    const char *name;
     int exact;
 {
     Tnm_MibNode *nodePtr;
@@ -1755,7 +1755,7 @@
 
 char*
 Tnm_MibGetDefault(name, exact)
-    char *name;
+    const char *name;
     int exact;
 {
     Tnm_MibNode *nodePtr = Tnm_MibFindNode(name, NULL, exact);
