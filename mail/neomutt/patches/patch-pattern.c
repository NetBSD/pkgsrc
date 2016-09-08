$NetBSD: patch-pattern.c,v 1.1 2016/09/08 21:56:49 wiz Exp $

--- pattern.c.orig	2016-08-27 00:03:28.000000000 +0000
+++ pattern.c
@@ -162,7 +162,7 @@ msg_search (CONTEXT *ctx, pattern_t* pat
   HEADER *h = ctx->hdrs[msgno];
   char *buf;
   size_t blen;
-#ifdef USE_FMEMOPEN
+#ifdef HAVE_OPEN_MEMSTREAM
   char *temp;
   size_t tempsize;
 #else
@@ -178,7 +178,7 @@ msg_search (CONTEXT *ctx, pattern_t* pat
       memset (&s, 0, sizeof (s));
       s.fpin = msg->fp;
       s.flags = MUTT_CHARCONV;
-#ifdef USE_FMEMOPEN
+#ifdef HAVE_OPEN_MEMSTREAM
       s.fpout = open_memstream (&temp, &tempsize);
       if (!s.fpout) {
 	mutt_perror ("Error opening memstream");
@@ -207,7 +207,7 @@ msg_search (CONTEXT *ctx, pattern_t* pat
 	  if (s.fpout)
 	  {
 	    safe_fclose (&s.fpout);
-#ifdef USE_FMEMOPEN
+#ifdef HAVE_OPEN_MEMSTREAM
             FREE(&temp);
 #else
 	    unlink (tempfile);
@@ -220,7 +220,7 @@ msg_search (CONTEXT *ctx, pattern_t* pat
 	mutt_body_handler (h->content, &s);
       }
 
-#ifdef USE_FMEMOPEN
+#ifdef HAVE_OPEN_MEMSTREAM
       fclose (s.fpout);
       lng = tempsize;
 
@@ -290,7 +290,7 @@ msg_search (CONTEXT *ctx, pattern_t* pat
     if (option (OPTTHOROUGHSRC))
     {
       safe_fclose (&fp);
-#ifdef USE_FMEMOPEN
+#ifdef HAVE_OPEN_MEMSTREAM
       if (tempsize)
         FREE(&temp);
 #else
