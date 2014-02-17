$NetBSD: patch-eeschema_netform.cpp,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- eeschema/netform.cpp.orig	2014-02-15 15:35:29.000000000 +0100
+++ eeschema/netform.cpp	2014-02-15 15:48:58.000000000 +0100
@@ -1046,7 +1046,7 @@
             xsheetpath->AddAttribute( sNames, path->PathHumanReadable() );
             xsheetpath->AddAttribute( sTStamps, path->Path() );
 
-            timeStamp.Printf( sTSFmt, comp->GetTimeStamp() );
+            timeStamp.Printf( sTSFmt, (u_long)comp->GetTimeStamp() );
             xcomp->AddChild( node( sTStamp, timeStamp ) );
         }
     }
@@ -1134,7 +1134,7 @@
             }
 
             ret |= fprintf( out, "\n$BeginComponent\n" );
-            ret |= fprintf( out, "TimeStamp=%8.8lX\n", comp->m_TimeStamp );
+            ret |= fprintf( out, "TimeStamp=%8.8lX\n", (u_long)comp->m_TimeStamp );
             ret |= fprintf( out, "Footprint=%s\n", TO_UTF8( footprint ) );
 
             field = wxT( "Reference=" ) + comp->GetRef( path ) + wxT( "\n" );
