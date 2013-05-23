$NetBSD: patch-prot.c,v 1.1 2013/05/23 14:57:32 joerg Exp $

--- prot.c.orig	1999-11-09 07:23:46.000000000 +0000
+++ prot.c
@@ -1,9 +1,10 @@
 #include "hasshsgr.h"
 #include "prot.h"
+#include <unistd.h>
 
 /* XXX: there are more portability problems here waiting to leap out at me */
 
-int prot_gid(gid) int gid;
+int prot_gid(gid_t gid)
 {
 #ifdef HASSHORTSETGROUPS
   short x[2];
@@ -15,7 +16,7 @@ int prot_gid(gid) int gid;
   return setgid(gid); /* _should_ be redundant, but on some systems it isn't */
 }
 
-int prot_uid(uid) int uid;
+int prot_uid(uid_t uid)
 {
   return setuid(uid);
 }
