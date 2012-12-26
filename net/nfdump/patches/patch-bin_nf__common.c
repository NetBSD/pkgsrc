$NetBSD: patch-bin_nf__common.c,v 1.1 2012/12/26 21:41:52 dholland Exp $

Fix gcc inline.

--- bin/nf_common.c~	2012-02-19 10:42:43.000000000 +0000
+++ bin/nf_common.c
@@ -1440,7 +1440,7 @@ int	i, remaining;
 
 } // End of ParseOutputFormat
 
-#ifdef __SUNPRO_C
+#if !defined(__GNUC__) || !defined(__GNUC_STDC_INLINE__)
 extern
 #endif
 inline void format_number(uint64_t num, char *s, int fixed_width) {
