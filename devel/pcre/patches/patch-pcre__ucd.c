$NetBSD: patch-pcre__ucd.c,v 1.1 2017/06/10 18:02:13 spz Exp $

from
https://vcs.pcre.org/pcre/code/trunk/pcre_ucd.c?r1=1490&r2=1688
for CVE-2017-7186

--- pcre_ucd.c.orig	2014-06-20 11:26:05.000000000 +0000
+++ pcre_ucd.c
@@ -38,6 +38,20 @@ const pcre_uint16 PRIV(ucd_stage2)[] = {
 const pcre_uint32 PRIV(ucd_caseless_sets)[] = {0};
 #else
 
+/* If the 32-bit library is run in non-32-bit mode, character values
+greater than 0x10ffff may be encountered. For these we set up a
+special record. */
+
+#ifdef COMPILE_PCRE32
+const ucd_record PRIV(dummy_ucd_record)[] = {{
+  ucp_Common,    /* script */
+  ucp_Cn,        /* type unassigned */
+  ucp_gbOther,   /* grapheme break property */
+  0,             /* case set */
+  0,             /* other case */
+  }};
+#endif
+
 /* When recompiling tables with a new Unicode version, please check the
 types in this structure definition from pcre_internal.h (the actual
 field names will be different):
