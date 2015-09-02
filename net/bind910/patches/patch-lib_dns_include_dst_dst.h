$NetBSD: patch-lib_dns_include_dst_dst.h,v 1.1 2015/09/02 19:46:44 sevan Exp $

CVE-2015-5722 - Parsing malformed keys may cause BIND to exit due to a failed
assertion in buffer.c

--- lib/dns/include/dst/dst.h.orig	2015-09-02 00:43:20.000000000 +0000
+++ lib/dns/include/dst/dst.h
@@ -71,6 +71,7 @@ typedef struct dst_context 	dst_context_
 #define DST_ALG_HMACSHA256	163	/* XXXMPA */
 #define DST_ALG_HMACSHA384	164	/* XXXMPA */
 #define DST_ALG_HMACSHA512	165	/* XXXMPA */
+#define DST_ALG_INDIRECT	252
 #define DST_ALG_PRIVATE		254
 #define DST_ALG_EXPAND		255
 #define DST_MAX_ALGS		255
