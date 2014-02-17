$NetBSD: patch-pcbnew_xchgmod.cpp,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- pcbnew/xchgmod.cpp.orig	2014-02-15 15:52:55.000000000 +0100
+++ pcbnew/xchgmod.cpp	2014-02-15 15:53:05.000000000 +0100
@@ -649,7 +649,7 @@
     for( ; Module != NULL; Module = Module->Next() )
     {
         fprintf( FichCmp, "\nBeginCmp\n" );
-        fprintf( FichCmp, "TimeStamp = %8.8lX\n", Module->GetTimeStamp() );
+        fprintf( FichCmp, "TimeStamp = %8.8lX\n", (u_long)Module->GetTimeStamp() );
         fprintf( FichCmp, "Path = %s\n", TO_UTF8( Module->m_Path ) );
         fprintf( FichCmp, "Reference = %s;\n",
                  !Module->m_Reference->m_Text.IsEmpty() ?
