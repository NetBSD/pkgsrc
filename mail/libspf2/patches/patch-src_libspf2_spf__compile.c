$NetBSD: patch-src_libspf2_spf__compile.c,v 1.1 2023/10/07 20:12:08 schmonz Exp $

Apply upstream commit d14abff to fix integer underflow.

--- src/libspf2/spf_compile.c.orig	2021-06-09 05:43:12.000000000 +0000
+++ src/libspf2/spf_compile.c
@@ -455,7 +455,11 @@ SPF_c_parse_var(SPF_response_t *spf_resp
 			/* Magic numbers for x/Nc in gdb. */					\
 			data->ds.__unused0 = 0xba; data->ds.__unused1 = 0xbe;	\
 			dst = SPF_data_str( data );								\
-			ds_avail = _avail - sizeof(SPF_data_t);					\
+			if ((_avail) < sizeof(SPF_data_t))						\
+				return SPF_response_add_error_ptr(spf_response,		\
+									SPF_E_BIG_STRING, NULL, src,	\
+								"Out of memory for string literal");\
+			ds_avail = (_avail) - sizeof(SPF_data_t);				\
 			ds_len = 0;												\
 		} while(0)
 
