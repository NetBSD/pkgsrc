$NetBSD: patch-delta.c,v 1.1 2015/09/14 13:33:21 joerg Exp $

--- delta.c.orig	2015-09-14 08:28:47.000000000 +0000
+++ delta.c
@@ -126,12 +126,12 @@ static rs_result rs_delta_s_scan(rs_job_
 static rs_result rs_delta_s_flush(rs_job_t *job);
 static rs_result rs_delta_s_end(rs_job_t *job);
 void rs_getinput(rs_job_t *job);
-inline int rs_findmatch(rs_job_t *job, rs_long_t *match_pos, size_t *match_len);
-inline rs_result rs_appendmatch(rs_job_t *job, rs_long_t match_pos, size_t match_len);
-inline rs_result rs_appendmiss(rs_job_t *job, size_t miss_len);
-inline rs_result rs_appendflush(rs_job_t *job);
-inline rs_result rs_processmatch(rs_job_t *job);
-inline rs_result rs_processmiss(rs_job_t *job);
+static inline int rs_findmatch(rs_job_t *job, rs_long_t *match_pos, size_t *match_len);
+static inline rs_result rs_appendmatch(rs_job_t *job, rs_long_t match_pos, size_t match_len);
+static inline rs_result rs_appendmiss(rs_job_t *job, size_t miss_len);
+static inline rs_result rs_appendflush(rs_job_t *job);
+static inline rs_result rs_processmatch(rs_job_t *job);
+static inline rs_result rs_processmiss(rs_job_t *job);
 
 /**
  * \brief Get a block of data if possible, and see if it matches.
@@ -255,7 +255,7 @@ void rs_getinput(rs_job_t *job) {
  * forwards beyond the block boundaries. Extending backwards would require
  * decrementing scoop_pos as appropriate.
  */
-inline int rs_findmatch(rs_job_t *job, rs_long_t *match_pos, size_t *match_len) {
+static inline int rs_findmatch(rs_job_t *job, rs_long_t *match_pos, size_t *match_len) {
     /* calculate the weak_sum if we don't have one */
     if (job->weak_sum.count == 0) {
         /* set match_len to min(block_len, scan_avail) */
@@ -282,7 +282,7 @@ inline int rs_findmatch(rs_job_t *job, r
 /**
  * Append a match at match_pos of length match_len to the delta, extending
  * a previous match if possible, or flushing any previous miss/match. */
-inline rs_result rs_appendmatch(rs_job_t *job, rs_long_t match_pos, size_t match_len)
+static inline rs_result rs_appendmatch(rs_job_t *job, rs_long_t match_pos, size_t match_len)
 {
     rs_result result=RS_DONE;
     
@@ -313,7 +313,7 @@ inline rs_result rs_appendmatch(rs_job_t
  * 
  * This also breaks misses up into block_len segments to avoid accumulating
  * too much in memory. */
-inline rs_result rs_appendmiss(rs_job_t *job, size_t miss_len)
+static inline rs_result rs_appendmiss(rs_job_t *job, size_t miss_len)
 {
     rs_result result=RS_DONE;
     
@@ -330,7 +330,7 @@ inline rs_result rs_appendmiss(rs_job_t 
 /**
  * Flush any accumulating hit or miss, appending it to the delta.
  */
-inline rs_result rs_appendflush(rs_job_t *job)
+static inline rs_result rs_appendflush(rs_job_t *job)
 {
     /* if last is a match, emit it and reset last by resetting basis_len */
     if (job->basis_len) {
@@ -361,7 +361,7 @@ inline rs_result rs_appendflush(rs_job_t
  * scoop_pos appropriately. In the future this could be used for something
  * like context compressing of miss data. Note that it also calls
  * rs_tube_catchup to output any pending output. */
-inline rs_result rs_processmatch(rs_job_t *job)
+static inline rs_result rs_processmatch(rs_job_t *job)
 {
     job->scoop_avail-=job->scoop_pos;
     job->scoop_next+=job->scoop_pos;
@@ -383,7 +383,7 @@ inline rs_result rs_processmatch(rs_job_
  * 
  * In the future this could do compression of miss data before outputing
  * it. */
-inline rs_result rs_processmiss(rs_job_t *job)
+static inline rs_result rs_processmiss(rs_job_t *job)
 {
     rs_tube_copy(job, job->scoop_pos);
     job->scoop_pos=0;
