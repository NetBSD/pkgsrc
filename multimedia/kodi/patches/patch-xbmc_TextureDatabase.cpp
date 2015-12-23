$NetBSD: patch-xbmc_TextureDatabase.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/TextureDatabase.cpp.orig	2015-12-22 18:18:09.000000000 +0000
+++ xbmc/TextureDatabase.cpp
@@ -294,7 +294,7 @@ bool CTextureDatabase::GetTextures(CVari
     if (!CDatabase::BuildSQL("", filter, sqlFilter))
       return false;
 
-    sql = PrepareSQL(sql, !filter.fields.empty() ? filter.fields.c_str() : "*") + sqlFilter;
+    sql = PrepareSQL(sql.c_str(), !filter.fields.empty() ? filter.fields.c_str() : "*") + sqlFilter;
     if (!m_pDS->query(sql.c_str()))
       return false;
 
