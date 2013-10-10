$NetBSD: patch-sound.c,v 1.1 2013/10/10 00:07:23 joerg Exp $

--- sound.c.orig	2013-10-09 23:16:12.000000000 +0000
+++ sound.c
@@ -240,7 +240,7 @@ void soundfalloff(void)
 
 void soundfallupdate(void)
 {
-  if (soundfallflag)
+  if (soundfallflag) {
     if (soundfalln<1) {
       soundfalln++;
       if (soundfallf)
@@ -255,6 +255,7 @@ void soundfallupdate(void)
       else
         soundfallf=TRUE;
     }
+  }
 }
 
 
@@ -276,13 +277,14 @@ void soundbreakoff(void)
 
 void soundbreakupdate(void)
 {
-  if (soundbreakflag)
+  if (soundbreakflag) {
     if (soundbreakduration!=0) {
       soundbreakduration--;
       t2val=soundbreakvalue;
     }
     else
       soundbreakflag=FALSE;
+  }
 }
 
 
@@ -344,7 +346,7 @@ void soundfireupdate(void)
   bool f=FALSE;
   for (n=0;n<FIREBALLS;n++) {
     sff[n]=FALSE;
-    if (soundfireflag[n])
+    if (soundfireflag[n]) {
       if (soundfiren[n]==1) {
         soundfiren[n]=0;
         soundfirevalue[n]+=soundfirevalue[n]/55;
@@ -355,6 +357,7 @@ void soundfireupdate(void)
       }
       else
         soundfiren[n]++;
+    }
   }
   if (f) {
     do {
@@ -390,7 +393,7 @@ void soundexplodeupdate(void)
   bool f=FALSE;
   for (n=0;n<FIREBALLS;n++) {
     sef[n]=FALSE;
-    if (soundexplodeflag[n])
+    if (soundexplodeflag[n]) {
       if (soundexplodeduration[n]!=0) {
         soundexplodevalue[n]=soundexplodevalue[n]-(soundexplodevalue[n]>>3);
         soundexplodeduration[n]--;
@@ -399,6 +402,7 @@ void soundexplodeupdate(void)
       }
       else
         soundexplodeflag[n]=FALSE;
+    }
   }
   if (f) {
     do {
@@ -480,7 +484,7 @@ void soundemeraldoff(void)
 
 void soundemeraldupdate(void)
 {
-  if (soundemeraldflag)
+  if (soundemeraldflag) {
     if (soundemeraldduration!=0) {
       if (soundemeraldn==0 || soundemeraldn==1)
         t2val=emerfreq;
@@ -492,6 +496,7 @@ void soundemeraldupdate(void)
     }
     else
       soundemeraldoff();
+  }
 }
 
 
@@ -552,7 +557,7 @@ void soundeatmoff(void)
 
 void soundeatmupdate(void)
 {
-  if (soundeatmflag)
+  if (soundeatmflag) {
     if (soundeatmn!=0) {
       if (soundeatmduration!=0) {
         if ((soundeatmduration%4)==1)
@@ -570,6 +575,7 @@ void soundeatmupdate(void)
     }
     else
       soundeatmflag=FALSE;
+  }
 }
 
 
