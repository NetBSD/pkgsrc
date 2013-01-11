$NetBSD: patch-bin_nf__common.c,v 1.2 2013/01/11 13:33:59 joerg Exp $

Fix gcc inline.

--- bin/nf_common.c.orig	2012-02-19 10:42:43.000000000 +0000
+++ bin/nf_common.c
@@ -487,7 +487,7 @@ int Getv6Mode(void) {
 #ifdef __SUNPRO_C
 extern
 #endif
-inline void Proto_string(uint8_t protonum, char *protostr) {
+void Proto_string(uint8_t protonum, char *protostr) {
 
 	if ( protonum >= NumProtos || no_scale ) {
 		snprintf(protostr,16,"%-5i", protonum );
@@ -1440,10 +1440,10 @@ int	i, remaining;
 
 } // End of ParseOutputFormat
 
-#ifdef __SUNPRO_C
+#if !defined(__GNUC__) || !defined(__GNUC_STDC_INLINE__)
 extern
 #endif
-inline void format_number(uint64_t num, char *s, int fixed_width) {
+void format_number(uint64_t num, char *s, int fixed_width) {
 double f = num;
 
 	if ( no_scale ) {
@@ -1475,7 +1475,7 @@ double f = num;
 
 } // End of format_number
 
-inline void condense_v6(char *s) {
+void condense_v6(char *s) {
 size_t len = strlen(s);
 char	*p, *q;
 
