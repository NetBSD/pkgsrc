$NetBSD: patch-src_PageSpan.cxx,v 1.1 2018/02/07 17:03:28 jperkin Exp $

Fix -Wtautological-unsigned-enum-zero-compare

--- src/PageSpan.cxx.orig	2015-12-26 09:22:22.000000000 +0000
+++ src/PageSpan.cxx
@@ -186,7 +186,7 @@ librevenge::RVNGString PageSpan::protect
 
 void PageSpan::storeContent(ContentType type, libodfgen::DocumentElementVector *pContent)
 {
-	if (type<0||type>=C_NumContentTypes)
+	if (type>=C_NumContentTypes)
 	{
 		ODFGEN_DEBUG_MSG(("PageSpan::storeContent: the type seems bad\n"));
 		// probably better to do not delete it
