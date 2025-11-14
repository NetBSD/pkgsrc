$NetBSD: patch-src_internal_fy-b3sum.c,v 1.1 2025/11/14 09:45:24 adam Exp $

getopt_long_only is not very portable; use getopt_long instead

--- src/internal/fy-b3sum.c.orig	2025-10-30 16:35:16.908068086 +0000
+++ src/internal/fy-b3sum.c
@@ -316,7 +316,7 @@ int main(int argc, char *argv[])
 	uint8_t key[BLAKE3_OUT_LEN];
 	ssize_t rdn;
 
-	while ((opt = getopt_long_only(argc, argv, "cl:b:dh", lopts, &lidx)) != -1) {
+	while ((opt = getopt_long(argc, argv, "cl:b:dh", lopts, &lidx)) != -1) {
 		switch (opt) {
 
 		case OPT_DERIVE_KEY:
