$NetBSD: patch-src_include_spf__record.h,v 1.1 2026/10/15 19:51:20 tm Exp $

Resize MAX_MECH_LEN for longer TXT/SPF records, especially multiple includes
and ip6 addresses.

diff --git a/src/include/spf_record.h b/src/include/spf_record.h
index 00c337a..f273cce 100644
--- src/include/spf_record.h.orig
+++ src/include/spf_record.h
@@ -74,7 +74,7 @@ typedef struct SPF_macro_struct SPF_macro_t;
 					/* SPF_mod_t.name_len and	*/
 				        /* SPF_mod_t.data_len		*/
 
-#define SPF_MAX_MECH_LEN	511
+#define SPF_MAX_MECH_LEN	8192
 #define SPF_MAX_MOD_LEN		511
