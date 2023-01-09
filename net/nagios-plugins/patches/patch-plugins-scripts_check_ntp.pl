$NetBSD: patch-plugins-scripts_check_ntp.pl,v 1.1 2023/01/09 00:28:41 sekiya Exp $

Unknown patch, please document.

--- plugins-scripts/check_ntp.pl.orig	2019-12-05 06:53:08.000000000 +0900
+++ plugins-scripts/check_ntp.pl	2023-01-09 08:50:43.177526601 +0900
@@ -312,6 +312,7 @@
 				} else {
 					$jitter_error = $ERRORS{'OK'};
 				}
+				last;
 			} else {
 				print "No match!\n" if $verbose;
 				$jitter = '(not parsed)';
