$NetBSD: patch-tcbdb.c,v 1.1 2013/10/25 20:27:18 jperkin Exp $

Fix return types.

--- tcbdb.c.orig	2012-08-18 02:08:38.000000000 +0000
+++ tcbdb.c
@@ -1137,16 +1137,16 @@ bool tcbdbcurout(BDBCUR *cur){
 void *tcbdbcurkey(BDBCUR *cur, int *sp){
   assert(cur && sp);
   TCBDB *bdb = cur->bdb;
-  if(!BDBLOCKMETHOD(bdb, false)) return false;
+  if(!BDBLOCKMETHOD(bdb, false)) return NULL;
   if(!bdb->open){
     tcbdbsetecode(bdb, TCEINVALID, __FILE__, __LINE__, __func__);
     BDBUNLOCKMETHOD(bdb);
-    return false;
+    return NULL;
   }
   if(cur->id < 1){
     tcbdbsetecode(bdb, TCENOREC, __FILE__, __LINE__, __func__);
     BDBUNLOCKMETHOD(bdb);
-    return false;
+    return NULL;
   }
   const char *kbuf, *vbuf;
   int ksiz, vsiz;
@@ -1174,16 +1174,16 @@ char *tcbdbcurkey2(BDBCUR *cur){
 const void *tcbdbcurkey3(BDBCUR *cur, int *sp){
   assert(cur && sp);
   TCBDB *bdb = cur->bdb;
-  if(!BDBLOCKMETHOD(bdb, false)) return false;
+  if(!BDBLOCKMETHOD(bdb, false)) return NULL;
   if(!bdb->open){
     tcbdbsetecode(bdb, TCEINVALID, __FILE__, __LINE__, __func__);
     BDBUNLOCKMETHOD(bdb);
-    return false;
+    return NULL;
   }
   if(cur->id < 1){
     tcbdbsetecode(bdb, TCENOREC, __FILE__, __LINE__, __func__);
     BDBUNLOCKMETHOD(bdb);
-    return false;
+    return NULL;
   }
   const char *kbuf, *vbuf;
   int ksiz, vsiz;
@@ -1203,16 +1203,16 @@ const void *tcbdbcurkey3(BDBCUR *cur, in
 void *tcbdbcurval(BDBCUR *cur, int *sp){
   assert(cur && sp);
   TCBDB *bdb = cur->bdb;
-  if(!BDBLOCKMETHOD(bdb, false)) return false;
+  if(!BDBLOCKMETHOD(bdb, false)) return NULL;
   if(!bdb->open){
     tcbdbsetecode(bdb, TCEINVALID, __FILE__, __LINE__, __func__);
     BDBUNLOCKMETHOD(bdb);
-    return false;
+    return NULL;
   }
   if(cur->id < 1){
     tcbdbsetecode(bdb, TCENOREC, __FILE__, __LINE__, __func__);
     BDBUNLOCKMETHOD(bdb);
-    return false;
+    return NULL;
   }
   const char *kbuf, *vbuf;
   int ksiz, vsiz;
@@ -1240,16 +1240,16 @@ char *tcbdbcurval2(BDBCUR *cur){
 const void *tcbdbcurval3(BDBCUR *cur, int *sp){
   assert(cur && sp);
   TCBDB *bdb = cur->bdb;
-  if(!BDBLOCKMETHOD(bdb, false)) return false;
+  if(!BDBLOCKMETHOD(bdb, false)) return NULL;
   if(!bdb->open){
     tcbdbsetecode(bdb, TCEINVALID, __FILE__, __LINE__, __func__);
     BDBUNLOCKMETHOD(bdb);
-    return false;
+    return NULL;
   }
   if(cur->id < 1){
     tcbdbsetecode(bdb, TCENOREC, __FILE__, __LINE__, __func__);
     BDBUNLOCKMETHOD(bdb);
-    return false;
+    return NULL;
   }
   const char *kbuf, *vbuf;
   int ksiz, vsiz;
@@ -1992,13 +1992,13 @@ static BDBLEAF *tcbdbleafload(TCBDB *bdb
   rsiz = tchdbget3(bdb->hdb, hbuf, step, wbuf, BDBPAGEBUFSIZ);
   if(rsiz < 1){
     tcbdbsetecode(bdb, TCEMISC, __FILE__, __LINE__, __func__);
-    return false;
+    return NULL;
   } else if(rsiz < BDBPAGEBUFSIZ){
     rp = wbuf;
   } else {
     if(!(rbuf = tchdbget(bdb->hdb, hbuf, step, &rsiz))){
       tcbdbsetecode(bdb, TCEMISC, __FILE__, __LINE__, __func__);
-      return false;
+      return NULL;
     }
     rp = rbuf;
   }
