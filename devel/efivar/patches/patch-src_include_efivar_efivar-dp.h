$NetBSD: patch-src_include_efivar_efivar-dp.h,v 1.1 2024/08/20 15:29:32 bsiegert Exp $

/usr/include/net/if.h contains:

    #define   if_type         if_data.ifi_type

--- src/include/efivar/efivar-dp.h.orig	2022-09-30 16:35:57.395069283 +0000
+++ src/include/efivar/efivar-dp.h
@@ -425,6 +425,10 @@ typedef struct {
 	uint32_t	target;
 } EFIVAR_PACKED efidp_i2o;
 
+#ifdef if_type
+# undef if_type
+#endif
+
 #define EFIDP_MSG_MAC_ADDR	0x0b
 typedef struct {
 	efidp_header	header;
