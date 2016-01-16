$NetBSD: patch-Foundation_src_pcre__internal.h,v 1.1 2016/01/16 12:15:12 ryoon Exp $

Fix build with unbundled PCRE
https://github.com/buildroot/buildroot/blob/master/package/poco/0004-fix-unbundled-pcre-usage.patch

--- Foundation/src/pcre_internal.h.orig	2015-08-04 05:20:56.000000000 +0000
+++ Foundation/src/pcre_internal.h
@@ -2635,6 +2635,16 @@ typedef struct {
   pcre_uint16 value;
 } ucp_type_table;
 
+/* renamed to avoid clashes with system pcre */
+#define _pcre_utf8_table1      _poco__pcre_utf8_table1
+#define _pcre_utf8_table1_size _poco__pcre_utf8_table1_size
+#define _pcre_utf8_table2      _poco__pcre_utf8_table2
+#define _pcre_utf8_table3      _poco__pcre_utf8_table3
+#define _pcre_utf8_table4      _poco__pcre_utf8_table4
+#define _pcre_utt              _poco__pcre_utt
+#define _pcre_utt_size         _poco__pcre_utt_size
+#define _pcre_utt_names        _poco__pcre_utt_names
+#define _pcre_OP_lengths       _poco__pcre_OP_lengths
 
 /* Internal shared data tables. These are tables that are used by more than one
 of the exported public functions. They have to be "external" in the C sense,
@@ -2749,6 +2759,12 @@ typedef struct {
   pcre_int32 other_case; /* offset to other case, or zero if none */
 } ucd_record;
 
+/* renamed to avoid clashes with system pcre */
+#define _pcre_ucd_records _poco__pcre_ucd_records
+#define _pcre_ucd_stage1 _poco__pcre_ucd_stage1
+#define _pcre_ucd_stage2 _poco__pcre_ucd_stage2
+#define _pcre_ucp_gentype _poco__pcre_ucp_gentype
+
 extern const pcre_uint32 PRIV(ucd_caseless_sets)[];
 extern const ucd_record  PRIV(ucd_records)[];
 extern const pcre_uint8  PRIV(ucd_stage1)[];
