$NetBSD: patch-eeschema_sch_sheet.cpp,v 1.2 2016/02/03 19:34:33 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- eeschema/sch_sheet.cpp.orig	2015-12-11 17:53:27.000000000 +0100
+++ eeschema/sch_sheet.cpp	2015-12-11 17:54:26.000000000 +0100
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
