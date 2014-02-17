$NetBSD: patch-eeschema_sch_sheet.cpp,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- eeschema/sch_sheet.cpp.orig	2014-02-15 15:39:08.000000000 +0100
+++ eeschema/sch_sheet.cpp	2014-02-15 15:40:13.000000000 +0100
@@ -53,8 +53,8 @@
     SetTimeStamp( GetNewTimeStamp() );
     m_sheetNameSize = m_fileNameSize = DEFAULT_TEXT_SIZE;
     m_screen = NULL;
-    m_name.Printf( wxT( "Sheet%8.8lX" ), m_TimeStamp );
-    m_fileName.Printf( wxT( "file%8.8lX.sch" ), m_TimeStamp );
+    m_name.Printf( wxT( "Sheet%8.8lX" ), (u_long)m_TimeStamp );
+    m_fileName.Printf( wxT( "file%8.8lX.sch" ), (u_long)m_TimeStamp );
 }
 
 
@@ -142,7 +142,7 @@
         return false;
 
     //save the unique timestamp, like other schematic parts.
-    if( fprintf( aFile, "U %8.8lX\n", m_TimeStamp ) == EOF )
+    if( fprintf( aFile, "U %8.8lX\n", (u_long)m_TimeStamp ) == EOF )
         return false;
 
     /* Save schematic sheetname and filename. */
@@ -219,7 +219,9 @@
 
         if( ((char*)aLine)[0] == 'U' )
         {
-            sscanf( ((char*)aLine) + 1, "%lX", &m_TimeStamp );
+	    u_long tmstp;
+            sscanf( ((char*)aLine) + 1, "%lX", &tmstp );
+	    m_TimeStamp = tmstp;
             if( m_TimeStamp == 0 )  // zero is not unique!
                 SetTimeStamp( GetNewTimeStamp() );
             continue;
@@ -828,7 +830,7 @@
 
 #if 0   // Set to 1 to display the sheet time stamp (mainly for test)
     wxString msg;
-    msg.Printf( wxT( "%.8X" ), m_TimeStamp );
+    msg.Printf( wxT( "%.8X" ), (u_long)m_TimeStamp );
     aList.push_back( MSG_PANEL_ITEM( _( "Time Stamp" ), msg, BLUE ) );
 #endif
 }
