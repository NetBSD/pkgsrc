$NetBSD: patch-xbmc_music_MusicDatabase.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/music/MusicDatabase.cpp.orig	2015-12-22 18:03:08.000000000 +0000
+++ xbmc/music/MusicDatabase.cpp
@@ -1414,7 +1414,7 @@ bool CMusicDatabase::GetAlbumsByArtist(i
     if (includeFeatured == false)
       strPrepSQL += " AND boolFeatured = 0";
     
-    strSQL=PrepareSQL(strPrepSQL, idArtist);
+    strSQL=PrepareSQL(strPrepSQL.c_str(), idArtist);
     if (!m_pDS->query(strSQL.c_str())) 
       return false;
     if (m_pDS->num_rows() == 0)
@@ -1448,7 +1448,7 @@ bool CMusicDatabase::GetArtistsByAlbum(i
     if (includeFeatured == false)
       strPrepSQL += " AND boolFeatured = 0";
 
-    strSQL=PrepareSQL(strPrepSQL, idAlbum);
+    strSQL=PrepareSQL(strPrepSQL.c_str(), idAlbum);
     if (!m_pDS->query(strSQL.c_str())) 
       return false;
     if (m_pDS->num_rows() == 0)
@@ -1482,7 +1482,7 @@ bool CMusicDatabase::GetSongsByArtist(in
     if (includeFeatured == false)
       strPrepSQL += " AND boolFeatured = 0";
 
-    strSQL=PrepareSQL(strPrepSQL, idArtist);
+    strSQL=PrepareSQL(strPrepSQL.c_str(), idArtist);
     if (!m_pDS->query(strSQL.c_str())) 
       return false;
     if (m_pDS->num_rows() == 0)
@@ -1516,7 +1516,7 @@ bool CMusicDatabase::GetArtistsBySong(in
     if (includeFeatured == false)
       strPrepSQL += " AND boolFeatured = 0";
     
-    strSQL=PrepareSQL(strPrepSQL, idSong);
+    strSQL=PrepareSQL(strPrepSQL.c_str(), idSong);
     if (!m_pDS->query(strSQL.c_str())) 
       return false;
     if (m_pDS->num_rows() == 0)
@@ -3159,7 +3159,7 @@ bool CMusicDatabase::GetCommonNav(const 
     if (!BuildSQL(strBaseDir, strSQL, extFilter, strSQL, musicUrl))
       return false;
     
-    strSQL = PrepareSQL(strSQL, !extFilter.fields.empty() ? extFilter.fields.c_str() : labelField.c_str());
+    strSQL = PrepareSQL(strSQL.c_str(), !extFilter.fields.empty() ? extFilter.fields.c_str() : labelField.c_str());
     
     // run query
     CLog::Log(LOGDEBUG, "%s query: %s", __FUNCTION__, strSQL.c_str());
@@ -3311,7 +3311,7 @@ bool CMusicDatabase::GetArtistsByWhere(c
         sortDescription.sortBy == SortByNone &&
        (sortDescription.limitStart > 0 || sortDescription.limitEnd > 0))
     {
-      total = (int)strtol(GetSingleValue(PrepareSQL(strSQL, "COUNT(1)") + strSQLExtra, m_pDS).c_str(), NULL, 10);
+      total = (int)strtol(GetSingleValue(PrepareSQL(strSQL.c_str(), "COUNT(1)") + strSQLExtra, m_pDS).c_str(), NULL, 10);
       strSQLExtra += DatabaseUtils::BuildLimitClause(sortDescription.limitEnd, sortDescription.limitStart);
     }
 
@@ -3470,11 +3470,11 @@ bool CMusicDatabase::GetAlbumsByWhere(co
         sortDescription.sortBy == SortByNone &&
        (sortDescription.limitStart > 0 || sortDescription.limitEnd > 0))
     {
-      total = (int)strtol(GetSingleValue(PrepareSQL(strSQL, "COUNT(1)") + strSQLExtra, m_pDS).c_str(), NULL, 10);
+      total = (int)strtol(GetSingleValue(PrepareSQL(strSQL.c_str(), "COUNT(1)") + strSQLExtra, m_pDS).c_str(), NULL, 10);
       strSQLExtra += DatabaseUtils::BuildLimitClause(sortDescription.limitEnd, sortDescription.limitStart);
     }
 
-    strSQL = PrepareSQL(strSQL, !filter.fields.empty() && filter.fields.compare("*") != 0 ? filter.fields.c_str() : "albumview.*") + strSQLExtra;
+    strSQL = PrepareSQL(strSQL.c_str(), !filter.fields.empty() && filter.fields.compare("*") != 0 ? filter.fields.c_str() : "albumview.*") + strSQLExtra;
 
     CLog::Log(LOGDEBUG, "%s query: %s", __FUNCTION__, strSQL.c_str());
     // run query
@@ -3583,11 +3583,11 @@ bool CMusicDatabase::GetSongsByWhere(con
         sortDescription.sortBy == SortByNone &&
        (sortDescription.limitStart > 0 || sortDescription.limitEnd > 0))
     {
-      total = (int)strtol(GetSingleValue(PrepareSQL(strSQL, "COUNT(1)") + strSQLExtra, m_pDS).c_str(), NULL, 10);
+      total = (int)strtol(GetSingleValue(PrepareSQL(strSQL.c_str(), "COUNT(1)") + strSQLExtra, m_pDS).c_str(), NULL, 10);
       strSQLExtra += DatabaseUtils::BuildLimitClause(sortDescription.limitEnd, sortDescription.limitStart);
     }
 
-    strSQL = PrepareSQL(strSQL, !filter.fields.empty() && filter.fields.compare("*") != 0 ? filter.fields.c_str() : "songview.*") + strSQLExtra;
+    strSQL = PrepareSQL(strSQL.c_str(), !filter.fields.empty() && filter.fields.compare("*") != 0 ? filter.fields.c_str() : "songview.*") + strSQLExtra;
 
     CLog::Log(LOGDEBUG, "%s query = %s", __FUNCTION__, strSQL.c_str());
     // run query
