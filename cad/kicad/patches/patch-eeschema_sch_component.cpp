$NetBSD: patch-eeschema_sch_component.cpp,v 1.5 2019/06/08 11:04:28 rillig Exp $

64bit time_t fix
Reported upstream as bug id 1280901

--- eeschema/sch_component.cpp.orig	2015-12-11 17:52:09.000000000 +0100
+++ eeschema/sch_component.cpp	2015-12-11 17:52:12.000000000 +0100
@@ -1240,7 +1240,9 @@
 
         if( line[0] == 'U' )
         {
-            sscanf( line + 1, "%d %d %lX", &m_unit, &m_convert, &m_TimeStamp );
+	    u_long tmstp;
+            sscanf( line + 1, "%d %d %lX", &m_unit, &m_convert, &tmstp );
+	    m_TimeStamp = tmstp;
         }
         else if( line[0] == 'P' )
         {
