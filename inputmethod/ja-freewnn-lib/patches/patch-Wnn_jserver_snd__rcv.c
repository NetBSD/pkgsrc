$NetBSD: patch-Wnn_jserver_snd__rcv.c,v 1.2 2026/07/10 23:32:37 tsutsui Exp $

- Appease -Wincompatible-pointer-types that are fatal on gcc14 and later

--- Wnn/jserver/snd_rcv.c.orig	2003-05-11 18:43:16.000000000 +0000
+++ Wnn/jserver/snd_rcv.c
@@ -54,15 +54,16 @@ fopen_write_cur (fn)
 /* JS_FILE_SEND (server recieves) */
 int
 fread_cur (p, size, nitems)
-     char *p;
+     void *p;
      register int size, nitems;
 {
+  char *cp = p;
   register int i, j, xx;
   for (i = 0; i < nitems; i++)
     {
       for (j = 0; j < size; j++)
         {
-          *p++ = xx = xgetc_cur ();
+          *cp++ = xx = xgetc_cur ();
           if (xx == -1)
             return i;
         }
