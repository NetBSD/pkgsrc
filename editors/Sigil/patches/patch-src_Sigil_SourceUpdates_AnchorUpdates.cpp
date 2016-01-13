$NetBSD: patch-src_Sigil_SourceUpdates_AnchorUpdates.cpp,v 1.1 2016/01/13 23:55:42 joerg Exp $

--- src/Sigil/SourceUpdates/AnchorUpdates.cpp.orig	2016-01-12 20:10:20.000000000 +0000
+++ src/Sigil/SourceUpdates/AnchorUpdates.cpp
@@ -40,6 +40,7 @@ using boost::make_tuple;
 using boost::shared_ptr;
 using boost::tie;
 using boost::tuple;
+using namespace boost::placeholders;
 
 void AnchorUpdates::UpdateAllAnchorsWithIDs(const QList<HTMLResource *> &html_resources)
 {
