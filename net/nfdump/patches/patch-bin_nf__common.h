$NetBSD: patch-bin_nf__common.h,v 1.1 2013/01/11 13:33:59 joerg Exp $

--- bin/nf_common.h.orig	2013-01-11 01:23:53.000000000 +0000
+++ bin/nf_common.h
@@ -99,17 +99,17 @@ char *Get_fwd_status_name(uint32_t id);
 #ifdef __SUNPRO_C
 extern 
 #endif
-inline void Proto_string(uint8_t protonum, char *protostr);
+void Proto_string(uint8_t protonum, char *protostr);
 
 #ifdef __SUNPRO_C
 extern 
 #endif
-inline void format_number(uint64_t num, char *s, int fixed_width);
+void format_number(uint64_t num, char *s, int fixed_width);
 
 #ifdef __SUNPRO_C
 extern 
 #endif
-inline void condense_v6(char *s);
+void condense_v6(char *s);
 
 #define TAG_CHAR ''
 
