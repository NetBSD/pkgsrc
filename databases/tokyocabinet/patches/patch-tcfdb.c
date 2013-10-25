$NetBSD: patch-tcfdb.c,v 1.1 2013/10/25 20:27:18 jperkin Exp $

Fix return types.

--- tcfdb.c.orig	2012-08-18 02:08:38.000000000 +0000
+++ tcfdb.c
@@ -479,11 +479,11 @@ bool tcfdbout3(TCFDB *fdb, const char *k
 /* Retrieve a record in a fixed-length database object. */
 void *tcfdbget(TCFDB *fdb, int64_t id, int *sp){
   assert(fdb && sp);
-  if(!FDBLOCKMETHOD(fdb, false)) return false;
+  if(!FDBLOCKMETHOD(fdb, false)) return NULL;
   if(fdb->fd < 0){
     tcfdbsetecode(fdb, TCEINVALID, __FILE__, __LINE__, __func__);
     FDBUNLOCKMETHOD(fdb);
-    return false;
+    return NULL;
   }
   if(id == FDBIDMIN){
     id = fdb->min;
@@ -493,11 +493,11 @@ void *tcfdbget(TCFDB *fdb, int64_t id, i
   if(id < 1 || id > fdb->limid){
     tcfdbsetecode(fdb, TCEINVALID, __FILE__, __LINE__, __func__);
     FDBUNLOCKMETHOD(fdb);
-    return false;
+    return NULL;
   }
   if(!FDBLOCKRECORD(fdb, false, id)){
     FDBUNLOCKMETHOD(fdb);
-    return false;
+    return NULL;
   }
   const void *vbuf = tcfdbgetimpl(fdb, id, sp);
   char *rv = vbuf ? tcmemdup(vbuf, *sp) : NULL;
@@ -658,7 +658,7 @@ char *tcfdbiternext3(TCFDB *fdb){
 /* Get range matching decimal keys in a fixed-length database object. */
 uint64_t *tcfdbrange(TCFDB *fdb, int64_t lower, int64_t upper, int max, int *np){
   assert(fdb && np);
-  if(!FDBLOCKMETHOD(fdb, true)) return false;
+  if(!FDBLOCKMETHOD(fdb, true)) return NULL;
   if(fdb->fd < 0){
     tcfdbsetecode(fdb, TCEINVALID, __FILE__, __LINE__, __func__);
     FDBUNLOCKMETHOD(fdb);
@@ -2289,7 +2289,7 @@ static const void *tcfdbgetimpl(TCFDB *f
   uint64_t nsiz = FDBHEADSIZ + id * fdb->rsiz;
   if(nsiz > fdb->fsiz){
     tcfdbsetecode(fdb, TCENOREC, __FILE__, __LINE__, __func__);
-    return false;
+    return NULL;
   }
   unsigned char *rp = rec;
   uint32_t osiz;
@@ -2312,7 +2312,7 @@ static const void *tcfdbgetimpl(TCFDB *f
   }
   if(osiz == 0 && *rp == 0){
     tcfdbsetecode(fdb, TCENOREC, __FILE__, __LINE__, __func__);
-    return false;
+    return NULL;
   }
   *sp = osiz;
   return rp;
