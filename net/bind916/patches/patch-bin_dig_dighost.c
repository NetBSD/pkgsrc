$NetBSD: patch-bin_dig_dighost.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- bin/dig/dighost.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ bin/dig/dighost.c
@@ -164,7 +164,7 @@ isc_mempool_t *commctx = NULL;
 bool debugging = false;
 bool debugtiming = false;
 bool memdebugging = false;
-char *progname = NULL;
+const char *progname = NULL;
 isc_mutex_t lookup_lock;
 dig_lookup_t *current_lookup = NULL;
 
