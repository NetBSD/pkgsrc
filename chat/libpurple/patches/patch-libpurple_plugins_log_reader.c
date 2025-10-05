$NetBSD: patch-libpurple_plugins_log_reader.c,v 1.1 2025/10/05 16:01:15 wiz Exp $

Fix -Wchar-subscripts in ctype(3) functions

--- libpurple/plugins/log_reader.c~	2024-09-17 21:31:28.000000000 +0200
+++ libpurple/plugins/log_reader.c	2025-10-05 15:09:15.646785462 +0200
@@ -998,15 +998,15 @@
 				 * ^(friendly_name|alias)([^a-zA-Z0-9].*)?$
 				 */
 				from_name_matches = (purple_str_has_prefix(from_name, friendly_name) &&
-				                      !isalnum(*(from_name + friendly_name_length))) ||
+				                      !isalnum((unsigned char)*(from_name + friendly_name_length))) ||
 				                     (purple_str_has_prefix(from_name, alias) &&
-				                      !isalnum(*(from_name + alias_length)));
+				                      !isalnum((unsigned char)*(from_name + alias_length)));
 
 				to_name_matches = to_name != NULL && (
 				                   (purple_str_has_prefix(to_name, friendly_name) &&
-				                    !isalnum(*(to_name + friendly_name_length))) ||
+				                    !isalnum((unsigned char)*(to_name + friendly_name_length))) ||
 				                   (purple_str_has_prefix(to_name, alias) &&
-				                    !isalnum(*(to_name + alias_length))));
+				                    !isalnum((unsigned char)*(to_name + alias_length))));
 
 				if (from_name_matches) {
 					if (!to_name_matches) {
@@ -1024,7 +1024,7 @@
 						 * character. The idea is to relax the comparison.
 						 */
 						for (temp = alias; *temp ; temp++) {
-							if (!isalnum(*temp)) {
+							if (!isalnum((unsigned char)*temp)) {
 								*temp = '\0';
 								break;
 							}
@@ -1038,12 +1038,12 @@
 						 */
 						from_name_matches = (purple_str_has_prefix(
 								from_name, alias) &&
-								!isalnum(*(from_name +
+								!isalnum((unsigned char)*(from_name +
 								alias_length)));
 
 						to_name_matches = to_name && (purple_str_has_prefix(
 								to_name, alias) &&
-								!isalnum(*(to_name +
+								!isalnum((unsigned char)*(to_name +
 								alias_length)));
 
 						g_free(alias);
@@ -1067,13 +1067,14 @@
 							from_name_matches = (purple_str_has_prefix(
 									from_name,
 									server_alias) &&
-									!isalnum(*(from_name +
+									!isalnum((unsigned char)*(from_name +
 									friendly_name_length)));
 
 							to_name_matches = to_name && (
 									(purple_str_has_prefix(
 									to_name, server_alias) &&
-									!isalnum(*(to_name +
+                                                                                !isalnum((unsigned char)*(to_name
+                                                                                +
 									friendly_name_length))));
 
 							if (from_name_matches) {
