$NetBSD: patch-tcadb.c,v 1.1 2013/10/25 20:27:18 jperkin Exp $

Fix return types.

--- tcadb.c.orig	2012-08-18 02:08:38.000000000 +0000
+++ tcadb.c
@@ -3743,7 +3743,7 @@ static bool tcadbmulout(ADBMUL *mul, con
    record. */
 static void *tcadbmulget(ADBMUL *mul, const void *kbuf, int ksiz, int *sp){
   assert(mul && kbuf && ksiz >= 0 && sp);
-  if(!mul->adbs) return false;
+  if(!mul->adbs) return NULL;
   int idx = tcadbmulidx(mul, kbuf, ksiz);
   TCADB *adb = mul->adbs[idx];
   return tcadbget(adb, kbuf, ksiz, sp);
@@ -3792,7 +3792,7 @@ static bool tcadbmuliterinit(ADBMUL *mul
    `NULL'. */
 static void *tcadbmuliternext(ADBMUL *mul, int *sp){
   assert(mul && sp);
-  if(!mul->adbs || mul->iter < 0) return false;
+  if(!mul->adbs || mul->iter < 0) return NULL;
   while(mul->iter < mul->num){
     TCADB *adb = mul->adbs[mul->iter];
     char *rv = tcadbiternext(adb, sp);
