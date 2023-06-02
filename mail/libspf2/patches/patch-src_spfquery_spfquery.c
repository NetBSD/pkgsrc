$NetBSD: patch-src_spfquery_spfquery.c,v 1.1 2023/06/02 15:57:58 schmonz Exp $

Avoid non-portable getopt_long_only (NetBSD lacks it).

--- src/spfquery/spfquery.c.orig	2021-06-09 05:43:12.000000000 +0000
+++ src/spfquery/spfquery.c
@@ -380,7 +380,7 @@ int main( int argc, char *argv[] )
 	for (;;) {
 		int option_index;	/* Largely unused */
 
-		c = getopt_long_only (argc, argv, "f:i:s:h:r:lt::gemcnd::kz:a:v",
+		c = getopt_long (argc, argv, "f:i:s:h:r:lt::gemcnd::kz:a:v",
 				  long_options, &option_index);
 
 		if (c == -1)
