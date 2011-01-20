$NetBSD: patch-ar,v 1.5 2011/01/20 11:56:51 markd Exp $

--- konsolekalendar/main.cpp.orig	2008-02-13 09:39:54.000000000 +0000
+++ konsolekalendar/main.cpp
@@ -799,13 +799,13 @@ int main( int argc, char *argv[] )
   if ( !args->isSet( "time" )     && !args->isSet( "epoch-start" ) &&
        !args->isSet( "end-time" ) && !args->isSet( "epoch-end" ) ) {
     // set default start date/time
-    startdatetime = QDateTime::QDateTime( startdate, starttime );
+    startdatetime = QDateTime( startdate, starttime );
     kdDebug() << "main | datetimestamp | "
               << "setting startdatetime from "
               << "default startdate (today) and starttime"
               << endl;
     // set default end date/time
-    enddatetime = QDateTime::QDateTime( enddate, endtime );
+    enddatetime = QDateTime( enddate, endtime );
     kdDebug() << "main | datetimestamp | "
               << "setting enddatetime from "
               << "default enddate (today) and endtime"
@@ -814,13 +814,13 @@ int main( int argc, char *argv[] )
 
   // Set startdatetime, enddatetime if still necessary
   if ( startdatetime.isNull() ) {
-    startdatetime = QDateTime::QDateTime( startdate, starttime );
+    startdatetime = QDateTime( startdate, starttime );
     kdDebug() << "main | datetimestamp | "
               << "setting startdatetime from startdate and starttime"
               << endl;
   }
   if ( enddatetime.isNull() ) {
-    enddatetime = QDateTime::QDateTime( enddate, endtime );
+    enddatetime = QDateTime( enddate, endtime );
     kdDebug() << "main | datetimestamp | "
               << "setting enddatetime from enddate and endtime"
               << endl;
