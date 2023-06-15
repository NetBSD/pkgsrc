$NetBSD: patch-and.c,v 1.1 2023/06/15 09:55:25 hauke Exp $

<values.h> is non-portable, replace with <limits.h> definitions.

--- and.c.orig	2004-04-05 19:19:01.000000000 +0000
+++ and.c
@@ -47,7 +47,6 @@
 #include <sys/types.h>
 #include <signal.h>
 #include <regex.h>
-#include <values.h>
 
 #define DEBUG 0
 
@@ -704,7 +703,7 @@ int and_getnice (int uid, int gid, char 
   /* Strategy: each priority database accumulates accuracy points
      for every aspect: user, group, command, parent. An exact hit is 
      worth the configured weight of the aspect (1, 2, 4, 8); a joker
-     is worth 0; and a miss is with -MAXINT, effectively eliminating
+     is worth 0; and a miss is with -INT_MAX, effectively eliminating
      the entry (veto). At the end, the highest rated entry is
       used to determine the new nice level. */
   for (i=0; i<and_db.n; i++) {
@@ -714,7 +713,7 @@ int and_getnice (int uid, int gid, char 
     } else if (and_db.entry[i].uid == -1) {
       exactness[i] = 0;
     } else {
-      exactness[i] = -MAXINT;
+      exactness[i] = -INT_MAX;
     }
     /* group id */
     if (gid == and_db.entry[i].gid) {
@@ -722,7 +721,7 @@ int and_getnice (int uid, int gid, char 
     } else if (and_db.entry[i].gid == -1) {
       exactness[i] += 0;
     } else {
-      exactness[i] = -MAXINT;
+      exactness[i] = -INT_MAX;
     }
     /* command */
     if (command!=NULL && regexec(and_db.entry[i].command,command,0,0,0) == 0) {
@@ -730,7 +729,7 @@ int and_getnice (int uid, int gid, char 
     } else if (strcmp(and_db.entry[i].command_str,"*") == 0) {
       exactness[i] += 0;
     } else {
-      exactness[i] = -MAXINT;
+      exactness[i] = -INT_MAX;
     }
     /* parent */
     par = parent;
@@ -745,7 +744,7 @@ int and_getnice (int uid, int gid, char 
         exactness[i] += 0;
         break;
       } else if (last) {
-        exactness[i] = -MAXINT;
+        exactness[i] = -INT_MAX;
         break;
       }
       par = par->parent;
