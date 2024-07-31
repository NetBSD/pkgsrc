$NetBSD: patch-src_mailfold.c,v 1.1 2024/07/31 22:31:50 vins Exp $

Fix build with gcc-14

--- src/mailfold.c.orig	2024-07-31 22:05:34.826652596 +0000
+++ src/mailfold.c
@@ -373,7 +373,7 @@ void concon(ch)const int ch;   /* flip b
    }
 }
 
-int readmail(rhead,tobesent)int rhead;const long tobesent;
+int readmail(int rhead,const long tobesent)
 { char*chp,*pastend;static size_t contlengthoffset;
   ;{ long dfilled;
      if(rhead==2)		  /* already read, just examine what we have */
