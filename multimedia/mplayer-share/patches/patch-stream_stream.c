$NetBSD: patch-stream_stream.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- stream/stream.c.orig	2025-10-08 03:52:41.721276288 +0000
+++ stream/stream.c
@@ -721,7 +721,7 @@ int parse_chapter_range(const m_option_t
   s = range;
   dvd_chapter = 1;
   dvd_last_chapter = 0;
-  if(*range && isdigit(*range)) {
+  if(*range && isdigit((unsigned char)(*range))) {
     dvd_chapter = strtol(range, (char **) &s, 10);
     if(range == s) {
       mp_msg(MSGT_OPEN, MSGL_ERR, MSGTR_DVDinvalidChapterRange, range);
@@ -737,7 +737,7 @@ int parse_chapter_range(const m_option_t
   ++s;
   if(*s == 0)
       return 0;
-  if(! isdigit(*s)) {
+  if(! isdigit((unsigned char)(*s))) {
     mp_msg(MSGT_OPEN, MSGL_ERR, MSGTR_DVDinvalidChapterRange, range);
     return M_OPT_INVALID;
   }
