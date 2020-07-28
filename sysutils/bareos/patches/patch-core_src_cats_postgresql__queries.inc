$NetBSD: patch-core_src_cats_postgresql__queries.inc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	Disambuguate reference columns

--- core/src/cats/postgresql_queries.inc.orig	2019-01-31 11:53:07.846130361 +0000
+++ core/src/cats/postgresql_queries.inc
@@ -170,7 +170,7 @@ const char *BareosDbPostgresql::query_de
 ,
 
 /* 0016_uar_list_jobs */
-"SELECT JobId, Client.Name as Client, StartTime, Level as JobLevel, JobFiles, JobBytes "
+"SELECT Job.JobId, Client.Name as Client, StartTime, Level as JobLevel, Job.JobFiles, Job.JobBytes "
   "FROM Client, Job "
  "WHERE Client.ClientId = Job.ClientId "
    "AND JobStatus IN ('T','W') "
@@ -179,7 +179,7 @@ const char *BareosDbPostgresql::query_de
 ,
 
 /* 0017_uar_print_jobs */
-"SELECT DISTINCT JobId, Level, JobFiles, JobBytes, StartTime, VolumeName "
+"SELECT DISTINCT JobId, Level, JobFiles, Job.JobBytes, StartTime, VolumeName "
   "FROM Job "
   "JOIN JobMedia "
  "USING (JobId) "
