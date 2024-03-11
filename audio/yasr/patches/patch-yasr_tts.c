$NetBSD: patch-yasr_tts.c,v 1.1 2024/03/11 07:52:38 wiz Exp $

Remove non-portable use of WCHAR_T in iconv code.
Fix comment's alignment.

--- yasr/tts.c.orig	2023-04-08 21:22:57.000000000 +0000
+++ yasr/tts.c
@@ -53,7 +53,8 @@ static Tts_synth synth[] = {
   {NULL, NULL, "CANCEL SELF\r\n", NULL, NULL, FALSE, "", "quit\r\n"},
 };
 
-static char *dict[256];
+#define DICT_SIZE 256
+static char *dict[DICT_SIZE];
 static int tts_flushed = 0;
 
 
@@ -67,9 +68,7 @@ dict_read (char *buf)
   {
     c = strtol (buf, &p, 0);
     if (c > 255)
-    {
       return (1);
-    }
     p++;
   }
   else
@@ -88,20 +87,14 @@ dict_write (FILE * fp)
 {
   int i;
 
-  for (i = 0; i < 256; i++)
-  {
+  for (i = 0; i < DICT_SIZE; i++)
     if (dict[i])
     {
       if (i > 31 && i < 127 && i != 35 && i != 91)
-      {
 	(void) fprintf (fp, "%c=%s\n", i, dict[i]);
-      }
       else
-      {
 	(void) fprintf (fp, "0x%.2x=%s\n", i, dict[i]);
-      }
     }
-  }
 }
 
 
@@ -111,9 +104,7 @@ void
 tts_flush ()
 {
   if (tts.outlen)
-  {
     w_speak (tts.buf, tts.outlen);
-  }
 
   tts.outlen = 0;
 
@@ -128,9 +119,7 @@ tts_wait (int usecs)
   if (usecs != -1 && !readable (tts.fd, usecs))
     return;
   while (readable (tts.fd, 0))
-  {
     read (tts.fd, buf, sizeof (buf));
-  }
 }
 #endif
 
@@ -140,9 +129,7 @@ tts_silence ()
   char tmp[1] = { 0 };
 
   if (tts_flushed)
-  {
     return;
-  }
   tts.obufhead = tts.obuftail = tts.flood = 0;
 #ifdef ENABLE_SPEECHD
   if (tts.synth == TTS_SPEECHD)
@@ -200,17 +187,13 @@ tts_obufout (int x)
   int oldoflag;
 
   if (!tts.flood)
-  {
     opt_queue_empty (2);
-  }
   oldoflag = tts.oflag;
   while (tts.obufhead < tts.obuftail)
   {
     len = strlen (tts.obuf + tts.obufhead);
     if (len > 1024)
-    {
       len = 1024;
-    }
     len2 = write (tts.fd, tts.obuf + tts.obufhead, len);
 #ifdef TTSLOG
     (void) write (ofd, tts.obuf + tts.obufhead, len2);
@@ -225,9 +208,7 @@ tts_obufout (int x)
       return;
     }
     while (tts.obufhead < tts.obuftail && !tts.obuf[tts.obufhead])
-    {
       tts.obufhead++;
-    }
   }
   tts.flood = 0;
   tts.oflag = oldoflag;
@@ -242,9 +223,7 @@ tts_addbuf (char *buf, int len, int len2
 
   tts.flood = 1;
   if (len2 == -1)
-  {
     ptr = buf;
-  }
   else
   {
     ptr = buf + len2;
@@ -258,9 +237,7 @@ tts_addbuf (char *buf, int len, int len2
       tts.obuf = realloc (tts.obuf, tts.obuflen);
     }
     else
-    {
       tts_obufpack ();
-    }
   }
   (void) memcpy (tts.obuf + tts.obuftail, ptr, len);
   tts.obuftail += len;
@@ -276,13 +253,9 @@ tts_send (char *buf, int len)
   int len2;
 
   if (!len)
-  {
     return;
-  }
   if (tts_flushed)
-  {
     tts_flushed = 0;
-  }
 #ifndef SILENT
   if (!tts.flood)
   {
@@ -293,9 +266,7 @@ tts_send (char *buf, int len)
 #endif
 
     if (len2 < len)
-    {
       tts_addbuf (buf, len, len2);
-    }
   }
   else
     tts_addbuf (buf, len, 0);
@@ -315,10 +286,8 @@ unspeakable (unsigned char ch)
   if (ch < 32)
     return 1;
   while (*p)
-  {
     if (*p++ == ch)
       return 1;
-  }
   return (0);
 }
 
@@ -412,7 +381,6 @@ tts_out_w (wchar_t *buf, int len)
   char *p;
   int i;
   int xml = 0;			/* what's this? */
-
   if (!len)
     return;
   if (tts.synth == TTS_SPEECHD)
@@ -420,9 +388,7 @@ tts_out_w (wchar_t *buf, int len)
     while (len > 0)
     {
       if (*buf < 0x80)
-      {
 	obuf[obo++] = *buf;
-      }
       else if (*buf < 0x800)
       {
 	obuf[obo++] = 0xc0 | (*buf >> 6);
@@ -514,9 +480,7 @@ tts_out_w (wchar_t *buf, int len)
       }
     }
     else
-    {
       obuf[obo++] = *p;
-    }
     p++;
   }
   tts_send (obuf, obo);
@@ -619,9 +583,7 @@ tts_out (unsigned char *buf, int len)
       }
     }
     else
-    {
       obuf[obo++] = *p;
-    }
     p++;
   }
   tts_send (obuf, obo);
@@ -656,9 +618,7 @@ tts_saychar (wchar_t ch)
   char buf[8];
 
   if (!ch)
-  {
     ch = 32;
-  }
   if (tts.synth == TTS_SPEECHD)
   {
 #ifdef ENABLE_SPEECHD
@@ -674,21 +634,22 @@ tts_saychar (wchar_t ch)
       tts_printf_ll ("CHAR %c\r\n", ch);
 #else
     else if (ch < 0x80)
-    {
       tts_printf_ll ("CHAR %c\r\n", ch);
-    }
     else
     {
-      char buf[8], *cin, *cout;
+      char tmpbuf[MB_CUR_MAX], buf[MB_CUR_MAX], *cin, *cout;
       size_t l1, l2;
       iconv_t cd;
-      cd = iconv_open ("UTF-8", "WCHAR_T");
+      cd = iconv_open ("UTF-8", nl_langinfo (CODESET));
       if (cd == (iconv_t) - 1)
 	return;
-      l1 = sizeof (wchar_t);
-      l2 = 7;
-      cin = (char *) &ch;
+      l1 = wctomb (tmpbuf, ch);
+      if (l1 == -1)
+	return;
+      l2 = sizeof (buf) - 1;
+      cin = tmpbuf;
       cout = buf;
+      
       iconv (cd, &cin, &l1, &cout, &l2);
       iconv_close (cd);
       *cout = 0;
@@ -704,7 +665,8 @@ tts_saychar (wchar_t ch)
     return;
   }
   if (!synth[tts.synth].charoff)
-  {				/* assume on string does everything */
+  {
+    /* assume on string does everything */
     (void) sprintf (ttsbuf, synth[tts.synth].charon, ch);
     tts_send (ttsbuf, strlen (ttsbuf));
     return;
@@ -725,9 +687,7 @@ tts_saychar (wchar_t ch)
   ttsbuf[0] = ch;
   tts_send (ttsbuf, 1);
   if (synth[tts.synth].saychar_needs_flush)
-  {
     tts_send (synth[tts.synth].say + 2, strlen (synth[tts.synth].say) - 2);
-  }
   while (j)
   {
     j -= 2;
@@ -887,9 +847,7 @@ tts_init (int first_call)
 #ifdef TTSLOG
   ofd = open ("tts.log", O_WRONLY | O_CREAT);
   if (ofd == -1)
-  {
     perror ("open");
-  }
 #endif
 
 #ifdef ENABLE_SPEECHD
@@ -920,17 +878,11 @@ tts_init (int first_call)
   else if (tts.port[0] != '|')
   {
     if (tts.synth == TTS_DECTALK)
-    {
       mode = O_NOCTTY | O_RDWR;
-    }
     else if (tts.synth == TTS_EMACSPEAK_SERVER)
-    {
       mode = O_WRONLY;
-    }
     if (first_call)
-    {
       tts.fd = open (portname, mode);
-    }
     if (tts.fd == -1)
     {
       perror ("tts");
@@ -958,21 +910,15 @@ tts_init (int first_call)
     (void) strcpy (buf, tts.port + 1);
     arg[i = 0] = strtok (buf, " ");
     while (i < 7)
-    {
       if (!(arg[++i] = strtok (NULL, " ")))
-      {
 	break;
-      }
-    }
 
     if (first_call)
-    {
       if (openpty (&tts.fd, &tts.fd_slave, NULL, NULL, NULL) == -1)
       {
 	perror ("openpty");
 	exit (1);
       }
-    }
 
     if (!(tts.pid = fork ()))
     {
@@ -989,9 +935,7 @@ tts_init (int first_call)
     }
     (void) usleep (10000);
     if (tts.pid == -1)
-    {
       perror ("forkpty");
-    }
   }
   if (tts.synth == TTS_SPEECHD)
   {
@@ -1043,10 +987,8 @@ void
 tts_addchr (wchar_t ch)
 {
   tts.buf[tts.outlen++] = ch;
-  if (tts.outlen > 250)
-  {
+  if (tts.outlen > TTS_BUF_SIZE)
     tts_flush ();
-  }
 }
 
 
@@ -1065,9 +1007,7 @@ tts_initsynth (int *argp)
     }
   }
   if (!ui.silent)
-  {
     tts_say (_("Synthesizer reinitialized."));
-  }
 }
 
 
@@ -1078,9 +1018,7 @@ tts_reinit (int *argp)
   int pid = tts.pid;
 
   if (pid == 0)
-  {
     return;
-  }
 
   tts.reinit = 1;		/* Start reinit */
 
@@ -1090,20 +1028,14 @@ tts_reinit (int *argp)
   if (kill (pid, SIGTERM) != 0)
   {
     if (errno == ESRCH)
-    {
       tts_reinit2 ();
-    }
     else
-    {
       kill (pid, SIGKILL);
-    }
   }
 
   /* wait init completion (tts.fd must be available) */
   while (tts.reinit)
-  {
     usleep (100000);
-  }
 }
 
 
