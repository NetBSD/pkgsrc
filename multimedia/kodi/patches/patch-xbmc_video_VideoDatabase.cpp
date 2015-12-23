$NetBSD: patch-xbmc_video_VideoDatabase.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/video/VideoDatabase.cpp.orig	2015-12-22 18:22:01.000000000 +0000
+++ xbmc/video/VideoDatabase.cpp
@@ -6194,11 +6194,11 @@ bool CVideoDatabase::GetMoviesByWhere(co
         sorting.sortBy == SortByNone &&
        (sorting.limitStart > 0 || sorting.limitEnd > 0))
     {
-      total = (int)strtol(GetSingleValue(PrepareSQL(strSQL, "COUNT(1)") + strSQLExtra, m_pDS).c_str(), NULL, 10);
+      total = (int)strtol(GetSingleValue(PrepareSQL(strSQL.c_str(), "COUNT(1)") + strSQLExtra, m_pDS).c_str(), NULL, 10);
       strSQLExtra += DatabaseUtils::BuildLimitClause(sorting.limitEnd, sorting.limitStart);
     }
 
-    strSQL = PrepareSQL(strSQL, !extFilter.fields.empty() ? extFilter.fields.c_str() : "*") + strSQLExtra;
+    strSQL = PrepareSQL(strSQL.c_str(), !extFilter.fields.empty() ? extFilter.fields.c_str() : "*") + strSQLExtra;
 
     int iRowsFound = RunQuery(strSQL);
     if (iRowsFound <= 0)
@@ -6300,11 +6300,11 @@ bool CVideoDatabase::GetTvShowsByWhere(c
         sorting.sortBy == SortByNone &&
         (sorting.limitStart > 0 || sorting.limitEnd > 0))
     {
-      total = (int)strtol(GetSingleValue(PrepareSQL(strSQL, "COUNT(1)") + strSQLExtra, m_pDS).c_str(), NULL, 10);
+      total = (int)strtol(GetSingleValue(PrepareSQL(strSQL.c_str(), "COUNT(1)") + strSQLExtra, m_pDS).c_str(), NULL, 10);
       strSQLExtra += DatabaseUtils::BuildLimitClause(sorting.limitEnd, sorting.limitStart);
     }
 
-    strSQL = PrepareSQL(strSQL, !extFilter.fields.empty() ? extFilter.fields.c_str() : "*") + strSQLExtra;
+    strSQL = PrepareSQL(strSQL.c_str(), !extFilter.fields.empty() ? extFilter.fields.c_str() : "*") + strSQLExtra;
 
     int iRowsFound = RunQuery(strSQL);
     if (iRowsFound <= 0)
@@ -6427,11 +6427,11 @@ bool CVideoDatabase::GetEpisodesByWhere(
       sorting.sortBy == SortByNone &&
       (sorting.limitStart > 0 || sorting.limitEnd > 0))
     {
-      total = (int)strtol(GetSingleValue(PrepareSQL(strSQL, "COUNT(1)") + strSQLExtra, m_pDS).c_str(), NULL, 10);
+      total = (int)strtol(GetSingleValue(PrepareSQL(strSQL.c_str(), "COUNT(1)") + strSQLExtra, m_pDS).c_str(), NULL, 10);
       strSQLExtra += DatabaseUtils::BuildLimitClause(sorting.limitEnd, sorting.limitStart);
     }
 
-    strSQL = PrepareSQL(strSQL, !extFilter.fields.empty() ? extFilter.fields.c_str() : "*") + strSQLExtra;
+    strSQL = PrepareSQL(strSQL.c_str(), !extFilter.fields.empty() ? extFilter.fields.c_str() : "*") + strSQLExtra;
 
     int iRowsFound = RunQuery(strSQL);
     if (iRowsFound <= 0)
@@ -7074,10 +7074,13 @@ void CVideoDatabase::GetMusicVideoArtist
     std::string strLike;
     if (!strSearch.empty())
       strLike = "and actor.name like '%%%s%%'";
-    if (CProfilesManager::Get().GetMasterProfile().getLockMode() != LOCK_MODE_EVERYONE && !g_passwordManager.bMasterUser)
-      strSQL=PrepareSQL("SELECT actor.actor_id, actor.name, path.strPath FROM actor INNER JOIN actor_link ON actor_link.actor_id=actor.actor_id INNER JOIN musicvideo ON actor_link.media_id=musicvideo.idMVideo INNER JOIN files ON files.idFile=musicvideo.idFile INNER JOIN path ON path.idPath=files.idPath WHERE actor_link.media_type='musicvideo' "+strLike, strSearch.c_str());
-    else
-      strSQL=PrepareSQL("SELECT DISTINCT actor.actor_id, actor.name from actor INNER JOIN actor_link ON actor_link.actor_id=actor.actor_id WHERE actor_link.media_type='musicvideo' "+strLike,strSearch.c_str());
+    if (CProfilesManager::Get().GetMasterProfile().getLockMode() != LOCK_MODE_EVERYONE && !g_passwordManager.bMasterUser) {
+      std::string full_query = "SELECT actor.actor_id, actor.name, path.strPath FROM actor INNER JOIN actor_link ON actor_link.actor_id=actor.actor_id INNER JOIN musicvideo ON actor_link.media_id=musicvideo.idMVideo INNER JOIN files ON files.idFile=musicvideo.idFile INNER JOIN path ON path.idPath=files.idPath WHERE actor_link.media_type='musicvideo' "+strLike;
+      strSQL=PrepareSQL(full_query.c_str(), strSearch.c_str());
+    } else {
+      std::string full_query = "SELECT DISTINCT actor.actor_id, actor.name from actor INNER JOIN actor_link ON actor_link.actor_id=actor.actor_id WHERE actor_link.media_type='musicvideo' "+strLike;
+      strSQL=PrepareSQL(full_query.c_str(),strSearch.c_str());
+    }
     m_pDS->query( strSQL.c_str() );
 
     while (!m_pDS->eof())
@@ -7262,11 +7265,11 @@ bool CVideoDatabase::GetMusicVideosByWhe
       sorting.sortBy == SortByNone &&
       (sorting.limitStart > 0 || sorting.limitEnd > 0))
     {
-      total = (int)strtol(GetSingleValue(PrepareSQL(strSQL, "COUNT(1)") + strSQLExtra, m_pDS).c_str(), NULL, 10);
+      total = (int)strtol(GetSingleValue(PrepareSQL(strSQL.c_str(), "COUNT(1)") + strSQLExtra, m_pDS).c_str(), NULL, 10);
       strSQLExtra += DatabaseUtils::BuildLimitClause(sorting.limitEnd, sorting.limitStart);
     }
 
-    strSQL = PrepareSQL(strSQL, !extFilter.fields.empty() ? extFilter.fields.c_str() : "*") + strSQLExtra;
+    strSQL = PrepareSQL(strSQL.c_str(), !extFilter.fields.empty() ? extFilter.fields.c_str() : "*") + strSQLExtra;
 
     int iRowsFound = RunQuery(strSQL);
     if (iRowsFound <= 0)
