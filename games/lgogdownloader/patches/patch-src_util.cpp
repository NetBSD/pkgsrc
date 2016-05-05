$NetBSD: patch-src_util.cpp,v 1.1 2016/05/05 22:06:39 joerg Exp $

--- src/util.cpp.orig	2016-05-04 12:02:30.617950547 +0000
+++ src/util.cpp
@@ -388,11 +388,11 @@ int Util::getTerminalWidth()
 void Util::getDownloaderUrlsFromJSON(const Json::Value &root, std::vector<std::string> &urls)
 {
     if(root.size() > 0) {
-        for(Json::ValueIterator it = root.begin() ; it != root.end() ; ++it)
+        for(Json::ValueConstIterator it = root.begin() ; it != root.end() ; ++it)
         {
             if (it.key() == "downloaderUrl")
             {
-                Json::Value& url = *it;
+                const Json::Value& url = *it;
                 urls.push_back(url.asString());
             }
             else
