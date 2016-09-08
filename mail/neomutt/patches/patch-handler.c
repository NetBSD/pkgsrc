$NetBSD: patch-handler.c,v 1.1 2016/09/08 21:56:49 wiz Exp $

--- handler.c.orig	2016-08-27 00:03:28.000000000 +0000
+++ handler.c
@@ -1596,7 +1596,7 @@ static int run_decode_and_handler (BODY 
   int origType;
   char *savePrefix = NULL;
   FILE *fp = NULL;
-#ifndef USE_FMEMOPEN
+#ifndef HAVE_OPEN_MEMSTREAM
   char tempfile[_POSIX_PATH_MAX];
 #endif
   size_t tmplength = 0;
@@ -1606,7 +1606,7 @@ static int run_decode_and_handler (BODY 
 
   fseeko (s->fpin, b->offset, 0);
 
-#ifdef USE_FMEMOPEN
+#ifdef HAVE_OPEN_MEMSTREAM
   char *temp;
   size_t tempsize;
 #endif
@@ -1626,7 +1626,7 @@ static int run_decode_and_handler (BODY 
     {
       /* decode to a tempfile, saving the original destination */
       fp = s->fpout;
-#ifdef USE_FMEMOPEN
+#ifdef HAVE_OPEN_MEMSTREAM
      s->fpout = open_memstream (&temp, &tempsize);
      if (!s->fpout) {
        mutt_error _("Unable to open memory stream!");
@@ -1670,7 +1670,7 @@ static int run_decode_and_handler (BODY 
       /* restore final destination and substitute the tempfile for input */
       s->fpout = fp;
       fp = s->fpin;
-#ifdef USE_FMEMOPEN
+#ifdef HAVE_OPEN_MEMSTREAM
       if (tempsize) {
         s->fpin = fmemopen (temp, tempsize, "r");
       } else { /* fmemopen cannot handle zero-length buffers */
@@ -1708,7 +1708,7 @@ static int run_decode_and_handler (BODY 
 
       /* restore the original source stream */
       safe_fclose (&s->fpin);
-#ifdef USE_FMEMOPEN
+#ifdef HAVE_OPEN_MEMSTREAM
       if (tempsize)
         FREE(&temp);
 #endif
