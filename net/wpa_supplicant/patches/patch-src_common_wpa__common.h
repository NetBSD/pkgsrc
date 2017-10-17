$NetBSD: patch-src_common_wpa__common.h,v 1.1.2.2 2017/10/17 05:47:37 spz Exp $

--- src/common/wpa_common.h.orig	2016-10-02 18:51:11.000000000 +0000
+++ src/common/wpa_common.h
@@ -215,6 +215,7 @@ struct wpa_ptk {
 	size_t kck_len;
 	size_t kek_len;
 	size_t tk_len;
+	int installed; /* 1 if key has already been installed to driver */
 };
 
 
