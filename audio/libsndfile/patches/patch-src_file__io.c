$NetBSD: patch-src_file__io.c,v 1.1 2015/01/03 18:43:48 spz Exp $

patch for
http://secunia.com/advisories/61132
from
https://github.com/erikd/libsndfile/commit/725c7dbb95bfaf8b4bb7b04820e3a00cceea9ce6
part 1 of 2

--- src/file_io.c.orig	2011-01-19 10:12:28.000000000 +0000
+++ src/file_io.c
@@ -1,5 +1,5 @@
 /*
-** Copyright (C) 2002-2011 Erik de Castro Lopo <erikd@mega-nerd.com>
+** Copyright (C) 2002-2014 Erik de Castro Lopo <erikd@mega-nerd.com>
 ** Copyright (C) 2003 Ross Bencina <rbencina@iprimus.com.au>
 **
 ** This program is free software; you can redistribute it and/or modify
@@ -358,6 +358,9 @@ psf_fwrite (const void *ptr, sf_count_t 
 {	sf_count_t total = 0 ;
 	ssize_t	count ;
 
+	if (bytes == 0 || items == 0)
+		return 0 ;
+
 	if (psf->virtual_io)
 		return psf->vio.write (ptr, bytes*items, psf->vio_user_data) / bytes ;
 
