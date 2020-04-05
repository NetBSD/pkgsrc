$NetBSD: patch-src_PageSpan.cxx,v 1.2 2020/04/05 13:13:02 nia Exp $

Fix -Wtautological-unsigned-enum-zero-compare

--- src/PageSpan.cxx.orig	2018-04-20 08:51:38.000000000 +0000
+++ src/PageSpan.cxx
@@ -185,7 +185,7 @@ librevenge::RVNGString PageSpan::protect
 
 void PageSpan::storeContent(ContentType type, const std::shared_ptr<libodfgen::DocumentElementVector> &pContent)
 {
-	if (type<0||type>=C_NumContentTypes)
+	if (type>=C_NumContentTypes)
 	{
 		ODFGEN_DEBUG_MSG(("PageSpan::storeContent: the type seems bad\n"));
 		// probably better to do not delete it
