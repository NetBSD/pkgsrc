$NetBSD: patch-src_xmldomnode.cpp,v 1.2 2014/03/31 14:42:20 fhajny Exp $

Avoid infinite loop.

--- src/xmldomnode.cpp.orig	2013-11-04 04:50:03.000000000 +0000
+++ src/xmldomnode.cpp
@@ -872,7 +872,7 @@ stringbuffer *xmldomnode::getPath() cons
 	uint64_t	*indices=new uint64_t[ancestors];
 	int64_t		index;
 	node=this;
-	for (index=ancestors-1; index>=0; index--) {
+	for (index=ancestors; index-->0;) {
 
 		// get the name
 		names[index]=node->getName();
