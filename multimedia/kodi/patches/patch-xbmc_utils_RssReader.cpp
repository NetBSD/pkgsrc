$NetBSD: patch-xbmc_utils_RssReader.cpp,v 1.1 2017/02/21 16:03:21 joerg Exp $

--- xbmc/utils/RssReader.cpp.orig	2017-02-19 13:57:42.233006487 +0000
+++ xbmc/utils/RssReader.cpp
@@ -267,11 +267,11 @@ void CRssReader::GetNewsItems(TiXmlEleme
   if (m_tagSet.empty())
     AddTag("title");
 
-  while (itemNode > 0)
+  while (itemNode)
   {
     TiXmlNode* childNode = itemNode->FirstChild();
     mTagElements.clear();
-    while (childNode > 0)
+    while (childNode)
     {
       std::string strName = childNode->ValueStr();
 
