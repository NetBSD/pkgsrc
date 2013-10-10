$NetBSD: patch-main.c,v 1.1 2013/10/10 00:07:23 joerg Exp $

--- main.c.orig	2013-10-09 23:12:38.000000000 +0000
+++ main.c
@@ -602,11 +602,12 @@ void parsecmd(int argc,char *argv[])
       if (word[1]=='L' || word[1]=='l' || word[1]=='R' || word[1]=='r' ||
           word[1]=='P' || word[1]=='p' || word[1]=='S' || word[1]=='s' ||
           word[1]=='E' || word[1]=='e' || word[1]=='G' || word[1]=='g' ||
-          word[1]=='A' || word[1]=='a' || word[1]=='I' || word[1]=='i')
+          word[1]=='A' || word[1]=='a' || word[1]=='I' || word[1]=='i') {
         if (word[2]==':')
           i=3;
         else
           i=2;
+      }
       if (word[1]=='L' || word[1]=='l') {
         j=0;
         while (word[i]!=0)
@@ -639,7 +640,7 @@ void parsecmd(int argc,char *argv[])
         gs=TRUE;
       }
       if (word[1]=='I' || word[1]=='i')
-        sscanf(word+i,"%u",&startlev);
+        sscanf(word+i,"%hu",&startlev);
       if (word[1]=='U' || word[1]=='u')
         unlimlives=TRUE;
 #ifndef _WINDOWS        
@@ -705,13 +706,14 @@ void parsecmd(int argc,char *argv[])
         ginit();
         gpal(0);
       }
-      if (word[1]=='K' || word[1]=='k')
+      if (word[1]=='K' || word[1]=='k') {
         if (word[2]=='A' || word[2]=='a')
           redefkeyb(TRUE);
         else
           redefkeyb(FALSE);
+      }
       if (word[1]=='A' || word[1]=='a') {
-        sscanf(word+i,"%u,%x,%u,%u,%u,%u",&sound_device,&sound_port,&sound_irq,
+        sscanf(word+i,"%hu,%hx,%hu,%hu,%hu,%hu",&sound_device,&sound_port,&sound_irq,
                &sound_dma,&sound_rate,&sound_length);
         killsound();
         volume=1;
