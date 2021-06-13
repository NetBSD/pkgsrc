$NetBSD: patch-main_dns__naptr.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- main/dns_naptr.c.orig	2018-05-07 17:26:59.602834230 +0000
+++ main/dns_naptr.c
@@ -78,7 +78,7 @@ static enum flags_result interpret_flags
 				*flags == 'a' || *flags == 'A' ||
 				*flags == 'u' || *flags == 'U') {
 			return FLAGS_TERMINAL;
-		} else if (!isalnum(*flags)) {
+		} else if (!isalnum((unsigned char)*flags)) {
 			return FLAGS_INVALID;
 		} else {
 			return FLAGS_UNKNOWN;
@@ -90,7 +90,7 @@ static enum flags_result interpret_flags
 	 * S, A, U, and P flags together.
 	 */
 	for (i = 0; i < flags_size; ++i) {
-		if (!isalnum(flags[i])) {
+		if (!isalnum((unsigned char)flags[i])) {
 			return FLAGS_INVALID;
 		} else if (flags[i] == 's' || flags[i] == 'S') {
 			if (known_flag_found && known_flag_found != 's') {
@@ -146,7 +146,7 @@ static int services_invalid(const char *
 		uint8_t current_size = plus_pos ? plus_pos - current_pos : end_of_services - current_pos;
 		int i;
 
-		if (!isalpha(current_pos[0])) {
+		if (!isalpha((unsigned char)current_pos[0])) {
 			return -1;
 		}
 
@@ -155,7 +155,7 @@ static int services_invalid(const char *
 		}
 
 		for (i = 1; i < current_size; ++i) {
-			if (!isalnum(current_pos[i])) {
+			if (!isalnum((unsigned char)current_pos[i])) {
 				return -1;
 			}
 		}
