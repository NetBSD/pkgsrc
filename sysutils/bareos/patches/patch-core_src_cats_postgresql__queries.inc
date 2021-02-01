$NetBSD: patch-core_src_cats_postgresql__queries.inc,v 1.2 2021/02/01 09:08:43 kardel Exp $

	disambiguate reference columns

--- core/src/cats/postgresql_queries.inc.orig	2020-12-16 07:46:16.000000000 +0000
+++ core/src/cats/postgresql_queries.inc
@@ -171,7 +171,7 @@ const char *BareosDbPostgresql::query_de
 ,
 
 /* 0016_uar_list_jobs */
-"SELECT JobId, Client.Name as Client, StartTime, Level as JobLevel, JobFiles, JobBytes "
+"SELECT Job.JobId, Client.Name as Client, StartTime, Level as JobLevel, Job.JobFiles, Job.JobBytes "
   "FROM Client, Job "
  "WHERE Client.ClientId = Job.ClientId "
    "AND JobStatus IN ('T','W') "
@@ -180,7 +180,7 @@ const char *BareosDbPostgresql::query_de
 ,
 
 /* 0017_uar_print_jobs */
-"SELECT DISTINCT JobId, Level, JobFiles, JobBytes, StartTime, VolumeName "
+"SELECT DISTINCT JobId, Level, JobFiles, Job.JobBytes, StartTime, VolumeName "
   "FROM Job "
   "JOIN JobMedia "
  "USING (JobId) "
