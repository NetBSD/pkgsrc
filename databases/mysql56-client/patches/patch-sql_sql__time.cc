$NetBSD: patch-sql_sql__time.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_time.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_time.cc
@@ -105,9 +105,9 @@ uint calc_week(MYSQL_TIME *l_time, uint 
   uint days;
   ulong daynr=calc_daynr(l_time->year,l_time->month,l_time->day);
   ulong first_daynr=calc_daynr(l_time->year,1,1);
-  bool monday_first= test(week_behaviour & WEEK_MONDAY_FIRST);
-  bool week_year= test(week_behaviour & WEEK_YEAR);
-  bool first_weekday= test(week_behaviour & WEEK_FIRST_WEEKDAY);
+  bool monday_first= my_test(week_behaviour & WEEK_MONDAY_FIRST);
+  bool week_year= my_test(week_behaviour & WEEK_YEAR);
+  bool first_weekday= my_test(week_behaviour & WEEK_FIRST_WEEKDAY);
 
   uint weekday=calc_weekday(first_daynr, !monday_first);
   *year=l_time->year;
