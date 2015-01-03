$NetBSD: patch-src_sd2.c,v 1.1 2015/01/03 18:43:48 spz Exp $

patch for
http://secunia.com/advisories/61132
from
https://github.com/erikd/libsndfile/commit/dbe14f00030af5d3577f4cabbf9861db59e9c378
part 2 of 2

--- src/sd2.c.orig	2011-01-19 10:10:36.000000000 +0000
+++ src/sd2.c
@@ -496,6 +496,11 @@ sd2_parse_rsrc_fork (SF_PRIVATE *psf)
 
 	rsrc.type_offset = rsrc.map_offset + 30 ;
 
+	if (rsrc.map_offset + 28 > rsrc.rsrc_len)
+	{	psf_log_printf (psf, "Bad map offset.\n") ;
+		goto parse_rsrc_fork_cleanup ;
+		} ;
+
 	rsrc.type_count = read_short (rsrc.rsrc_data, rsrc.map_offset + 28) + 1 ;
 	if (rsrc.type_count < 1)
 	{	psf_log_printf (psf, "Bad type count.\n") ;
@@ -512,7 +517,12 @@ sd2_parse_rsrc_fork (SF_PRIVATE *psf)
 
 	rsrc.str_index = -1 ;
 	for (k = 0 ; k < rsrc.type_count ; k ++)
-	{	marker = read_marker (rsrc.rsrc_data, rsrc.type_offset + k * 8) ;
+	{	if (rsrc.type_offset + k * 8 > rsrc.rsrc_len)
+		{	psf_log_printf (psf, "Bad rsrc marker.\n") ;
+			goto parse_rsrc_fork_cleanup ;
+			} ;
+
+		marker = read_marker (rsrc.rsrc_data, rsrc.type_offset + k * 8) ;
 
 		if (marker == STR_MARKER)
 		{	rsrc.str_index = k ;
