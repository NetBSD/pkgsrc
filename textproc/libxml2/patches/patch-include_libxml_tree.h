$NetBSD: patch-include_libxml_tree.h,v 1.1 2015/04/24 11:32:29 spz Exp $

patch for CVE-2015-1819 Enforce the reader to run in constant memory
from https://git.gnome.org/browse/libxml2/commit/?id=213f1fe0d76d30eaed6e5853057defc43e6df2c9
part 2

--- include/libxml/tree.h.orig	2014-10-13 08:20:09.000000000 +0000
+++ include/libxml/tree.h
@@ -76,7 +76,8 @@ typedef enum {
     XML_BUFFER_ALLOC_EXACT,	/* grow only to the minimal size */
     XML_BUFFER_ALLOC_IMMUTABLE, /* immutable buffer */
     XML_BUFFER_ALLOC_IO,	/* special allocation scheme used for I/O */
-    XML_BUFFER_ALLOC_HYBRID	/* exact up to a threshold, and doubleit thereafter */
+    XML_BUFFER_ALLOC_HYBRID,	/* exact up to a threshold, and doubleit thereafter */
+    XML_BUFFER_ALLOC_BOUNDED    /* limit the upper size of the buffer */
 } xmlBufferAllocationScheme;
 
 /**
