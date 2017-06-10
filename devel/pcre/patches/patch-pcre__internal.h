$NetBSD: patch-pcre__internal.h,v 1.1 2017/06/10 18:02:13 spz Exp $

from
https://vcs.pcre.org/pcre/code/trunk/pcre_internal.h?r1=1649&r2=1688
for CVE-2017-7186

--- pcre_internal.h.orig	2016-05-21 13:33:24.000000000 +0000
+++ pcre_internal.h
@@ -2772,6 +2772,9 @@ extern const pcre_uint8  PRIV(ucd_stage1
 extern const pcre_uint16 PRIV(ucd_stage2)[];
 extern const pcre_uint32 PRIV(ucp_gentype)[];
 extern const pcre_uint32 PRIV(ucp_gbtable)[];
+#ifdef COMPILE_PCRE32
+extern const ucd_record  PRIV(dummy_ucd_record)[];
+#endif
 #ifdef SUPPORT_JIT
 extern const int         PRIV(ucp_typerange)[];
 #endif
@@ -2780,10 +2783,16 @@ extern const int         PRIV(ucp_typera
 /* UCD access macros */
 
 #define UCD_BLOCK_SIZE 128
-#define GET_UCD(ch) (PRIV(ucd_records) + \
+#define REAL_GET_UCD(ch) (PRIV(ucd_records) + \
         PRIV(ucd_stage2)[PRIV(ucd_stage1)[(int)(ch) / UCD_BLOCK_SIZE] * \
         UCD_BLOCK_SIZE + (int)(ch) % UCD_BLOCK_SIZE])
 
+#ifdef COMPILE_PCRE32
+#define GET_UCD(ch) ((ch > 0x10ffff)? PRIV(dummy_ucd_record) : REAL_GET_UCD(ch))
+#else
+#define GET_UCD(ch) REAL_GET_UCD(ch)
+#endif
+
 #define UCD_CHARTYPE(ch)    GET_UCD(ch)->chartype
 #define UCD_SCRIPT(ch)      GET_UCD(ch)->script
 #define UCD_CATEGORY(ch)    PRIV(ucp_gentype)[UCD_CHARTYPE(ch)]
