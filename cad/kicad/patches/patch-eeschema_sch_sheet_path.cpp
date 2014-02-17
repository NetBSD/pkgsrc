$NetBSD: patch-eeschema_sch_sheet_path.cpp,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- eeschema/sch_sheet_path.cpp.orig	2014-02-15 15:50:43.000000000 +0100
+++ eeschema/sch_sheet_path.cpp	2014-02-15 15:50:45.000000000 +0100
@@ -200,7 +200,7 @@
     // it's timestamp changes anyway.
     for( unsigned i = 1; i < m_numSheets; i++ )
     {
-        t.Printf( _( "%8.8lX/" ), m_sheets[i]->GetTimeStamp() );
+        t.Printf( _( "%8.8lX/" ), (u_long)m_sheets[i]->GetTimeStamp() );
         s = s + t;
     }
 
