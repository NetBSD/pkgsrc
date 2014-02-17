$NetBSD: patch-eeschema_sch_component.cpp,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- eeschema/sch_component.cpp.orig	2014-02-15 15:23:19.000000000 +0100
+++ eeschema/sch_component.cpp	2014-02-15 15:38:12.000000000 +0100
@@ -392,7 +392,7 @@
 
     wxString str;
 
-    str.Printf( wxT( "%8.8lX" ), m_TimeStamp );
+    str.Printf( wxT( "%8.8lX" ), (u_long)m_TimeStamp );
     return sheet->Path() + str;
 }
 
@@ -527,8 +527,8 @@
 {
     wxString string_timestamp, string_oldtimestamp;
 
-    string_timestamp.Printf( wxT( "%08lX" ), aNewTimeStamp );
-    string_oldtimestamp.Printf( wxT( "%08lX" ), m_TimeStamp );
+    string_timestamp.Printf( wxT( "%08lX" ), (u_long)aNewTimeStamp );
+    string_oldtimestamp.Printf( wxT( "%08lX" ), (u_long)m_TimeStamp );
     EDA_ITEM::SetTimeStamp( aNewTimeStamp );
 
     for( unsigned ii = 0; ii < m_PathsAndReferences.GetCount(); ii++ )
@@ -1004,7 +1004,7 @@
         return false;
 
     /* Generate unit number, convert and time stamp*/
-    if( fprintf( f, "U %d %d %8.8lX\n", m_unit, m_convert, m_TimeStamp ) == EOF )
+    if( fprintf( f, "U %d %d %8.8lX\n", m_unit, m_convert, (u_long)m_TimeStamp ) == EOF )
         return false;
 
     /* Save the position */
@@ -1200,7 +1200,9 @@
 
         if( line[0] == 'U' )
         {
-            sscanf( line + 1, "%d %d %lX", &m_unit, &m_convert, &m_TimeStamp );
+	    u_long tmstp;
+            sscanf( line + 1, "%d %d %lX", &m_unit, &m_convert, &tmstp );
+	    m_TimeStamp = tmstp;
         }
         else if( line[0] == 'P' )
         {
