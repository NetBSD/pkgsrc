$NetBSD: patch-decode.c,v 1.1 2015/04/12 15:54:02 tnn Exp $

Fix CVE-2015-2782. Via Debian security-afl.patch.

--- decode.c.orig	2003-04-12 16:15:58.000000000 +0000
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
