$NetBSD: patch-kex.h,v 1.1 2023/12/20 17:09:36 wiz Exp $

Terrapin fix
https://github.com/mkj/dropbear/commit/6e43be5c7b99dbee49dc72b6f989f29fdd7e9356

--- kex.h.orig	2022-11-14 14:30:00.000000000 +0000
+++ kex.h
@@ -83,6 +83,9 @@ struct KEXState {
 
 	unsigned our_first_follows_matches : 1;
 
+	/* Boolean indicating that strict kex mode is in use */
+	unsigned int strict_kex;
+
 	time_t lastkextime; /* time of the last kex */
 	unsigned int datatrans; /* data transmitted since last kex */
 	unsigned int datarecv; /* data received since last kex */
