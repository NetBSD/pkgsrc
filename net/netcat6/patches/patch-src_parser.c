$NetBSD: patch-src_parser.c,v 1.1 2020/08/27 14:24:08 uwe Exp $

To recognize -t (as the short version of --idle-timeout) it should be
listed in the getopt's optstring too.

--- src/parser.c.orig	2006-01-19 22:46:23.000000000 +0000
+++ src/parser.c
@@ -160,7 +160,7 @@ void parse_arguments(int argc, char **ar
 	_verbosity_level = 0;
 
 	/* option recognition loop */
-	while ((c = getopt_long(argc, argv, "46be:hlnp:q:s:uvw:xX",
+	while ((c = getopt_long(argc, argv, "46be:hlnp:q:s:t:uvw:xX",
 	                        long_options, &option_index)) >= 0)
 	{
  		switch (c) {
