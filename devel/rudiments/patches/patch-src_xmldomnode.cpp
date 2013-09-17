$NetBSD: patch-src_xmldomnode.cpp,v 1.1 2013/09/17 21:09:50 joerg Exp $

Avoid infinite loop.

--- src/xmldomnode.cpp.orig	2013-09-17 20:33:44.000000000 +0000
+++ src/xmldomnode.cpp
@@ -707,7 +707,7 @@ stringbuffer *xmldomnode::getPath() cons
 	const char	**names=new const char *[ancestors];
 	uint64_t	*indices=new uint64_t[ancestors];
 	node=this;
-	for (uint64_t index=ancestors-1; index>=0; index--) {
+	for (uint64_t index=ancestors; index-->0;) {
 
 		// get the name
 		names[index]=node->getName();
