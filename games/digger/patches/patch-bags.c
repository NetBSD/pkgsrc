$NetBSD: patch-bags.c,v 1.1 2013/10/10 00:07:23 joerg Exp $

--- bags.c.orig	2013-10-09 23:18:02.000000000 +0000
+++ bags.c
@@ -168,7 +168,7 @@ void updatebag(Sint4 bag)
       break;
     case DIR_RIGHT:
     case DIR_LEFT:
-      if (xr==0)
+      if (xr==0) {
         if (y<180 && (getfield(h,v+1)&0xfdf)!=0xfdf) {
           bagdat[bag].dir=DIR_DOWN;
           bagdat[bag].wt=0;
@@ -176,6 +176,7 @@ void updatebag(Sint4 bag)
         }
         else
           baghitground(bag);
+      }
       break;
     case DIR_DOWN:
       if (yr==0)
@@ -188,11 +189,12 @@ void updatebag(Sint4 bag)
             baghitground(bag);
       checkmonscared(bagdat[bag].h);
   }
-  if (bagdat[bag].dir!=DIR_NONE)
+  if (bagdat[bag].dir!=DIR_NONE) {
     if (bagdat[bag].dir!=DIR_DOWN && pushcount!=0)
       pushcount--;
     else
       pushbag(bag,bagdat[bag].dir);
+  }
 }
 
 void baghitground(Sint4 bag)
