$NetBSD: patch-src_libspf2_spf__compile.c,v 1.2 2026/10/15 19:51:20 tm Exp $

Apply upstream commit d14abff to fix integer underflow. Also handle BIG_MECH
errors correctly.

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
 
@@ -1411,7 +1415,7 @@ SPF_record_compile(SPF_server_t *spf_ser
 			err = SPF_c_mech_add(spf_server,
 							spf_record, spf_response,
 							mechtype, prefix, &val_start);
-			if (err == SPF_E_NO_MEMORY)
+			if (err == SPF_E_NO_MEMORY || err == SPF_E_BIG_MECH)
 				return err;
 			/* XXX Else do nothing. Continue for the next error. */
 			/* We shouldn't have to worry about the child function
