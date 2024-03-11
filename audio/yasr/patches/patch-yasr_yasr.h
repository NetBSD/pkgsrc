$NetBSD: patch-yasr_yasr.h,v 1.1 2024/03/11 07:52:38 wiz Exp $

Remove size of array declarations defined elsewhere

--- yasr/yasr.h.orig	2023-04-08 21:22:57.000000000 +0000
+++ yasr/yasr.h
@@ -128,6 +128,7 @@ enum mpunct
 
 #define OPT_STR_SIZE 256
 
+#define TTS_BUF_SIZE 256
 typedef struct Tts Tts;
 struct Tts
 {
@@ -140,7 +141,7 @@ struct Tts
   int obufhead, obuflen, obuftail;
   int oflag;			/* set to 1 every time tts_send is called */
   int outlen;
-  wchar_t buf[256];
+  wchar_t buf[TTS_BUF_SIZE];
   int synth;
   pid_t pid;
   char port[OPT_STR_SIZE];
@@ -304,11 +305,11 @@ extern int cl_synthport;
 extern Opt opt[];
 extern int synthopt;
 extern char *conffile;
-extern unsigned char buf[256];
-extern int kbuf[100];
+extern char buf[];
+extern int kbuf[];
 extern int kbuflen;
-extern char usershell[OPT_STR_SIZE];
-extern char ttsbuf[80];
+extern char usershell[];
+extern char ttsbuf[];
 extern Voices voices;
 extern int special;
 extern char charmap[];
