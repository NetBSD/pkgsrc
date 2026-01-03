$NetBSD: patch-src_content_import__service.cc,v 1.1 2026/01/03 10:28:11 wiz Exp $

Fix build with fmtlib 12.

--- src/content/import_service.cc.orig	2026-01-03 10:18:38.817729876 +0000
+++ src/content/import_service.cc
@@ -763,7 +763,7 @@ void ImportService::parseMetafile(const 
 void ImportService::updateItemData(const std::shared_ptr<CdsItem>& item, const std::string& mimetype)
 {
     if (hasDefaultDate && item->getMetaData(MetadataFields::M_DATE).empty())
-        item->addMetaData(MetadataFields::M_DATE, fmt::format("{:%FT%T%z}", fmt::localtime(item->getMTime().count())));
+        item->addMetaData(MetadataFields::M_DATE, grbLocaltime("{:%FT%T%z}", item->getMTime()));
     for (auto&& upnpPattern : upnpMap) {
         if (upnpPattern.isMatch(item, mimetype)) {
             item->setClass(upnpPattern.upnpClass);
