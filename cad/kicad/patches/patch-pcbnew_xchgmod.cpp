$NetBSD: patch-pcbnew_xchgmod.cpp,v 1.4 2019/06/08 11:04:28 rillig Exp $

64bit time_t fix
Reported upstream as bug id 1280901

--- pcbnew/xchgmod.cpp.orig	2015-12-11 18:20:54.000000000 +0100
+++ pcbnew/xchgmod.cpp	2015-12-11 18:21:01.000000000 +0100
@@ -542,7 +542,7 @@
     for( ; module != NULL; module = module->Next() )
     {
         fprintf( cmpFile, "\nBeginCmp\n" );
-        fprintf( cmpFile, "TimeStamp = %8.8lX\n", module->GetTimeStamp() );
+        fprintf( cmpFile, "TimeStamp = %8.8lX\n", (u_long)module->GetTimeStamp() );
         fprintf( cmpFile, "Path = %s\n", TO_UTF8( module->GetPath() ) );
         fprintf( cmpFile, "Reference = %s;\n",
                  !module->GetReference().IsEmpty() ?
