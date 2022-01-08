$NetBSD: patch-decode.c,v 1.2 2022/01/08 14:43:09 tnn Exp $

Fix CVE-2015-2782. Via Debian security-afl.patch.

Fix out-of-bounds read via Debian out-of-bounds-read.patch.

--- decode.c.orig	2022-01-08 14:27:21.037706349 +0000
+++ decode.c
@@ -255,7 +255,7 @@ void read_pt_len(int nn, int nbit, int i
    if(i==i_special)
    {
     c=getbits(2);
-    while(--c>=0)
+    while(--c>=0&&i<nn)
      pt_len[i++]=0;
    }
   }
@@ -314,10 +314,10 @@ void read_c_len()
      c=getbits(CBIT);
      c+=20;
     }
-    while(--c>=0)
+    while(--c>=0&&i<NC)
      c_len[i++]=0;
    }
-   else
+   else if (i<NC)
     c_len[i++]=(unsigned char)(c-2);
   }
   while(i<NC)
@@ -416,10 +416,10 @@ static void NEAR decode_end()
 
 void decode(int action)
 {
- short i;
- short r;
- short c;
- static short j;
+ int i;
+ int r;
+ int c;
+ static int j;
 
  #if SFX_LEVEL>=ARJSFXV
  if(!setjmp(decode_proc))
@@ -450,9 +450,12 @@ void decode(int action)
    {
     j=c-(UCHAR_MAX+1-THRESHOLD);
     count-=(unsigned long)j;
-    i=r-decode_p()-1;
+    int P = decode_p();
+    i=r-P-1;
     if(i<0)
      i+=DICSIZ;
+    if(i<0)
+      goto termination;
     if(r>i&&r<DICSIZ-MAXMATCH-1)
     {
      while(--j>=0)
