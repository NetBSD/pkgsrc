$NetBSD: patch-snmplib_mib.c,v 1.1 2014/11/26 15:45:03 adam Exp $

Official patch for CVE-2014-3565:
Remote denial-of-service flaw was found in the way snmptrapd handled certain
SNMP traps when started with the "-OQ" option. If an attacker sent an SNMP trap
containing variable with a NULL type where an integer variable type was
expected, it would cause snmptrapd to crash.

--- snmplib/mib.c.orig	2014-02-20 00:36:42.000000000 +0000
+++ snmplib/mib.c
@@ -464,17 +464,16 @@ sprint_realloc_octet_string(u_char ** bu
     u_char         *cp;
     int             output_format, cnt;
 
-    if ((var->type != ASN_OCTET_STR) && 
-        (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        const char      str[] = "Wrong Type (should be OCTET STRING): ";
-        if (snmp_cstrcat
-            (buf, buf_len, out_len, allow_realloc, str)) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+    if (var->type != ASN_OCTET_STR) {
+        if (!netsnmp_ds_get_boolean(
+                    NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            const char      str[] = "Wrong Type (should be OCTET STRING): ";
+            if (!snmp_cstrcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
     }
 
 
@@ -742,16 +741,16 @@ sprint_realloc_float(u_char ** buf, size
                      const struct enum_list *enums,
                      const char *hint, const char *units)
 {
-    if ((var->type != ASN_OPAQUE_FLOAT) &&
-        (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        if (snmp_cstrcat(buf, buf_len, out_len, allow_realloc, 
-                         "Wrong Type (should be Float): ")) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+    if (var->type != ASN_OPAQUE_FLOAT) {
+        if (!netsnmp_ds_get_boolean(
+                NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            u_char          str[] = "Wrong Type (should be Float): ";
+            if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
     }
 
     if (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICK_PRINT)) {
@@ -812,17 +811,16 @@ sprint_realloc_double(u_char ** buf, siz
                       const struct enum_list *enums,
                       const char *hint, const char *units)
 {
-    if ((var->type != ASN_OPAQUE_DOUBLE) && 
-        (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        if (snmp_cstrcat
-            (buf, buf_len, out_len, allow_realloc, 
-             "Wrong Type (should be Double): ")) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+    if (var->type != ASN_OPAQUE_DOUBLE) {
+        if (!netsnmp_ds_get_boolean(
+                NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            u_char          str[] = "Wrong Type (should be Double): ";
+            if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
     }
 
     if (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICK_PRINT)) {
@@ -887,20 +885,21 @@ sprint_realloc_counter64(u_char ** buf, 
 {
     char            a64buf[I64CHARSZ + 1];
 
-    if ((var->type != ASN_COUNTER64
+    if (var->type != ASN_COUNTER64
 #ifdef NETSNMP_WITH_OPAQUE_SPECIAL_TYPES
         && var->type != ASN_OPAQUE_COUNTER64
         && var->type != ASN_OPAQUE_I64 && var->type != ASN_OPAQUE_U64
 #endif
-        ) && (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        if (snmp_cstrcat(buf, buf_len, out_len, allow_realloc, 
-                        "Wrong Type (should be Counter64): ")) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+        ) {
+        if (!netsnmp_ds_get_boolean(
+                NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            u_char          str[] = "Wrong Type (should be Counter64): ";
+            if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
     }
 
     if (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICK_PRINT)) {
@@ -988,23 +987,25 @@ sprint_realloc_opaque(u_char ** buf, siz
                       const struct enum_list *enums,
                       const char *hint, const char *units)
 {
-    if ((var->type != ASN_OPAQUE
+    if (var->type != ASN_OPAQUE
 #ifdef NETSNMP_WITH_OPAQUE_SPECIAL_TYPES
         && var->type != ASN_OPAQUE_COUNTER64
         && var->type != ASN_OPAQUE_U64
         && var->type != ASN_OPAQUE_I64
         && var->type != ASN_OPAQUE_FLOAT && var->type != ASN_OPAQUE_DOUBLE
 #endif                          /* NETSNMP_WITH_OPAQUE_SPECIAL_TYPES */
-        ) && (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        if (snmp_cstrcat(buf, buf_len, out_len, allow_realloc, 
-                         "Wrong Type (should be Opaque): ")) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+        ) {
+        if (!netsnmp_ds_get_boolean(
+                NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            u_char          str[] = "Wrong Type (should be Opaque): ";
+            if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
     }
+
 #ifdef NETSNMP_WITH_OPAQUE_SPECIAL_TYPES
     switch (var->type) {
     case ASN_OPAQUE_COUNTER64:
@@ -1080,17 +1081,16 @@ sprint_realloc_object_identifier(u_char 
 {
     int             buf_overflow = 0;
 
-    if ((var->type != ASN_OBJECT_ID) &&
-        (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        u_char          str[] =
-            "Wrong Type (should be OBJECT IDENTIFIER): ";
-        if (snmp_strcat(buf, buf_len, out_len, allow_realloc, str)) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+    if (var->type != ASN_OBJECT_ID) {
+        if (!netsnmp_ds_get_boolean(
+                NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            u_char          str[] = "Wrong Type (should be OBJECT IDENTIFIER): ";
+            if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
     }
 
     if (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICK_PRINT)) {
@@ -1150,16 +1150,16 @@ sprint_realloc_timeticks(u_char ** buf, 
 {
     char            timebuf[40];
 
-    if ((var->type != ASN_TIMETICKS) && 
-        (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        u_char          str[] = "Wrong Type (should be Timeticks): ";
-        if (snmp_strcat(buf, buf_len, out_len, allow_realloc, str)) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+    if (var->type != ASN_TIMETICKS) {
+        if (!netsnmp_ds_get_boolean(
+                NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            u_char          str[] = "Wrong Type (should be Timeticks): ";
+            if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
     }
 
     if (netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_NUMERIC_TIMETICKS)) {
@@ -1298,17 +1298,18 @@ sprint_realloc_integer(u_char ** buf, si
 {
     char           *enum_string = NULL;
 
-    if ((var->type != ASN_INTEGER) && 
-        (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        u_char          str[] = "Wrong Type (should be INTEGER): ";
-        if (snmp_strcat(buf, buf_len, out_len, allow_realloc, str)) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+    if (var->type != ASN_INTEGER) {
+        if (!netsnmp_ds_get_boolean(
+                NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            u_char          str[] = "Wrong Type (should be INTEGER): ";
+            if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
     }
+
     for (; enums; enums = enums->next) {
         if (enums->value == *var->val.integer) {
             enum_string = enums->label;
@@ -1401,16 +1402,16 @@ sprint_realloc_uinteger(u_char ** buf, s
 {
     char           *enum_string = NULL;
 
-    if ((var->type != ASN_UINTEGER) && 
-        (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        u_char          str[] = "Wrong Type (should be UInteger32): ";
-        if (snmp_strcat(buf, buf_len, out_len, allow_realloc, str)) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+    if (var->type != ASN_UINTEGER) {
+        if (!netsnmp_ds_get_boolean(
+                NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            u_char          str[] = "Wrong Type (should be UInteger32): ";
+            if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
     }
 
     for (; enums; enums = enums->next) {
@@ -1498,17 +1499,16 @@ sprint_realloc_gauge(u_char ** buf, size
 {
     char            tmp[32];
 
-    if ((var->type != ASN_GAUGE) && 
-        (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        u_char          str[] =
-            "Wrong Type (should be Gauge32 or Unsigned32): ";
-        if (snmp_strcat(buf, buf_len, out_len, allow_realloc, str)) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+    if (var->type != ASN_GAUGE) {
+        if (!netsnmp_ds_get_boolean(
+                NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            u_char          str[] = "Wrong Type (should be Gauge32 or Unsigned32): ";
+            if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
     }
 
     if (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICK_PRINT)) {
@@ -1571,16 +1571,16 @@ sprint_realloc_counter(u_char ** buf, si
 {
     char            tmp[32];
 
-    if ((var->type != ASN_COUNTER) && 
-        (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        u_char          str[] = "Wrong Type (should be Counter32): ";
-        if (snmp_strcat(buf, buf_len, out_len, allow_realloc, str)) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+    if (var->type != ASN_COUNTER) {
+        if (!netsnmp_ds_get_boolean(
+                NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            u_char          str[] = "Wrong Type (should be Counter32): ";
+            if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
     }
 
     if (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICK_PRINT)) {
@@ -1634,16 +1634,16 @@ sprint_realloc_networkaddress(u_char ** 
 {
     size_t          i;
 
-    if ((var->type != ASN_IPADDRESS) && 
-        (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        u_char          str[] = "Wrong Type (should be NetworkAddress): ";
-        if (snmp_strcat(buf, buf_len, out_len, allow_realloc, str)) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+    if (var->type != ASN_IPADDRESS) {
+        if (!netsnmp_ds_get_boolean(
+                NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            u_char          str[] = "Wrong Type (should be NetworkAddress): ";
+            if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
     }
 
     if (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICK_PRINT)) {
@@ -1700,16 +1700,16 @@ sprint_realloc_ipaddress(u_char ** buf, 
 {
     u_char         *ip = var->val.string;
 
-    if ((var->type != ASN_IPADDRESS) && 
-        (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        u_char          str[] = "Wrong Type (should be IpAddress): ";
-        if (snmp_strcat(buf, buf_len, out_len, allow_realloc, str)) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+    if (var->type != ASN_IPADDRESS) {
+        if (!netsnmp_ds_get_boolean(
+                NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            u_char          str[] = "Wrong Type (should be IpAddress): ";
+            if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
     }
 
     if (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICK_PRINT)) {
@@ -1758,20 +1758,20 @@ sprint_realloc_null(u_char ** buf, size_
                     const struct enum_list *enums,
                     const char *hint, const char *units)
 {
-    if ((var->type != ASN_NULL) && 
-        (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        u_char          str[] = "Wrong Type (should be NULL): ";
-        if (snmp_strcat(buf, buf_len, out_len, allow_realloc, str)) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+    if (var->type != ASN_NULL) {
+        if (!netsnmp_ds_get_boolean(
+                NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            u_char          str[] = "Wrong Type (should be NULL): ";
+            if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
-    } else {
-        u_char          str[] = "NULL";
-        return snmp_strcat(buf, buf_len, out_len, allow_realloc, str);
     }
+
+    u_char          str[] = "NULL";
+    return snmp_strcat(buf, buf_len, out_len, allow_realloc, str);
 }
 
 
@@ -1806,16 +1806,16 @@ sprint_realloc_bitstring(u_char ** buf, 
     u_char         *cp;
     char           *enum_string;
 
-    if ((var->type != ASN_BIT_STR && var->type != ASN_OCTET_STR) &&
-        (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        u_char          str[] = "Wrong Type (should be BITS): ";
-        if (snmp_strcat(buf, buf_len, out_len, allow_realloc, str)) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+    if (var->type != ASN_BIT_STR && var->type != ASN_OCTET_STR) {
+        if (!netsnmp_ds_get_boolean(
+                NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            u_char          str[] = "Wrong Type (should be BITS): ";
+            if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
     }
 
     if (netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICK_PRINT)) {
@@ -1890,16 +1890,16 @@ sprint_realloc_nsapaddress(u_char ** buf
                            const struct enum_list *enums, const char *hint,
                            const char *units)
 {
-    if ((var->type != ASN_NSAP) && 
-        (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT))) {
-        u_char          str[] = "Wrong Type (should be NsapAddress): ";
-        if (snmp_strcat(buf, buf_len, out_len, allow_realloc, str)) {
-            return sprint_realloc_by_type(buf, buf_len, out_len,
+    if (var->type != ASN_NSAP) {
+        if (!netsnmp_ds_get_boolean(
+                NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICKE_PRINT)) {
+            u_char          str[] = "Wrong Type (should be NsapAddress): ";
+            if (!snmp_strcat(buf, buf_len, out_len, allow_realloc, str))
+                return 0;
+        }
+        return sprint_realloc_by_type(buf, buf_len, out_len,
                                           allow_realloc, var, NULL, NULL,
                                           NULL);
-        } else {
-            return 0;
-        }
     }
 
     if (!netsnmp_ds_get_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_QUICK_PRINT)) {
