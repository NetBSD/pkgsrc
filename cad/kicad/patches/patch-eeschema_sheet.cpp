$NetBSD: patch-eeschema_sheet.cpp,v 1.1.1.1 2014/02/17 20:38:59 bouyer Exp $
64bit time_t fix
Reported upstream as bug id 1280901

--- eeschema/sheet.cpp.orig	2014-02-15 15:49:44.000000000 +0100
+++ eeschema/sheet.cpp	2014-02-15 15:49:51.000000000 +0100
@@ -205,7 +205,7 @@
     aSheet->SetSheetNameSize( ReturnValueFromString( g_UserUnit, dlg.GetSheetNameTextSize() ) );
 
     if( aSheet->GetName().IsEmpty() )
-        aSheet->SetName( wxString::Format( wxT( "Sheet%8.8lX" ), aSheet->GetTimeStamp() ) );
+        aSheet->SetName( wxString::Format( wxT( "Sheet%8.8lX" ), (u_long)aSheet->GetTimeStamp() ) );
 
     m_canvas->MoveCursorToCrossHair();
     m_canvas->SetIgnoreMouseEvents( false );
