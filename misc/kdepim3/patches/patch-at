$NetBSD: patch-at,v 1.5 2011/01/20 11:56:51 markd Exp $

--- kontact/plugins/specialdates/sdsummarywidget.cpp.orig	2006-10-01 17:30:38.000000000 +0000
+++ kontact/plugins/specialdates/sdsummarywidget.cpp
@@ -438,7 +438,7 @@ void SDSummaryWidget::updateView()
 
       //Muck with the year -- change to the year 'daysTo' days away
       int year = currentDate.addDays( (*addrIt).daysTo ).year();
-      QDate sD = QDate::QDate( year,
+      QDate sD = QDate( year,
                            (*addrIt).date.month(), (*addrIt).date.day() );
 
       if ( (*addrIt).daysTo == 0 ) {
