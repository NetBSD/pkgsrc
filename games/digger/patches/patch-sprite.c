$NetBSD: patch-sprite.c,v 1.1 2013/10/10 00:07:23 joerg Exp $

--- sprite.c.orig	2013-10-09 23:15:14.000000000 +0000
+++ sprite.c
@@ -262,10 +262,11 @@ void bcollides(int spr)
     next=-1;
     for (spc=firstt[i];spc<lastt[i];spc++)
       if (sprenf[spc] && spc!=spr)
-        if (bcollide(spr,spc))
+        if (bcollide(spr,spc)) {
           if (next==-1)
             first[i]=next=spc;
           else
             coll[next=(coll[next]=spc)]=-1;
+        }
   }
 }
