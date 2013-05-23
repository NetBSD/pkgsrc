$NetBSD: patch-kmysqladmin_helpers_tfunctions.h,v 1.1 2013/05/23 18:38:36 joerg Exp $

--- kmysqladmin/helpers/tfunctions.h.orig	2013-05-23 17:28:38.000000000 +0000
+++ kmysqladmin/helpers/tfunctions.h
@@ -167,7 +167,7 @@ namespace tfunctions {
         Explode(){};
         stringlist operator()(const std::string&s,const std::string&delemiter,bool aTrimit)
         {
-            unsigned int pos;
+            std::string::size_type pos;
             stringlist l;
             std::string iLine = s;
             while ( (pos = iLine.find(delemiter))!=std::string::npos) {
