$NetBSD: patch-as,v 1.5 2011/01/20 11:56:51 markd Exp $

--- kontact/plugins/korganizer/summarywidget.cpp.orig	2008-02-13 09:39:52.000000000 +0000
+++ kontact/plugins/korganizer/summarywidget.cpp
@@ -167,7 +167,7 @@ void SummaryWidget::updateView()
       QString datestr;
 
       // Modify event date for printing
-      QDate sD = QDate::QDate( dt.year(), dt.month(), dt.day() );
+      QDate sD = QDate( dt.year(), dt.month(), dt.day() );
       if ( ( sD.month() == currentDate.month() ) &&
            ( sD.day()   == currentDate.day() ) ) {
         datestr = i18n( "Today" );
@@ -227,10 +227,10 @@ void SummaryWidget::updateView()
         QTime sET = ev->dtEnd().time();
         if ( ev->isMultiDay() ) {
           if ( ev->dtStart().date() < dt ) {
-            sST = QTime::QTime( 0, 0 );
+            sST = QTime( 0, 0 );
           }
           if ( ev->dtEnd().date() > dt ) {
-            sET = QTime::QTime( 23, 59 );
+            sET = QTime( 23, 59 );
           }
         }
         datestr = i18n( "Time from - to", "%1 - %2" )
