$NetBSD: patch-shell.c,v 1.1.2.2 2021/10/17 10:12:03 tm Exp $

Fix Segmentation fault in idxGetTableInfo (CVE-2021-36690)
https://sqlite.org/src/info/b1e0c22ec981cf5f

--- shell.c.orig	2021-06-18 18:52:24.000000000 +0000
+++ shell.c
@@ -9852,11 +9852,13 @@ static int idxGetTableInfo(
   rc = idxPrintfPrepareStmt(db, &p1, pzErrmsg, "PRAGMA table_xinfo=%Q", zTab);
   while( rc==SQLITE_OK && SQLITE_ROW==sqlite3_step(p1) ){
     const char *zCol = (const char*)sqlite3_column_text(p1, 1);
+    const char *zColSeq = 0;
     nByte += 1 + STRLEN(zCol);
     rc = sqlite3_table_column_metadata(
-        db, "main", zTab, zCol, 0, &zCol, 0, 0, 0
+        db, "main", zTab, zCol, 0, &zColSeq, 0, 0, 0
     );
-    nByte += 1 + STRLEN(zCol);
+    if( zColSeq==0 ) zColSeq = "binary";
+    nByte += 1 + STRLEN(zColSeq);
     nCol++;
     nPk += (sqlite3_column_int(p1, 5)>0);
   }
@@ -9876,6 +9878,7 @@ static int idxGetTableInfo(
   nCol = 0;
   while( rc==SQLITE_OK && SQLITE_ROW==sqlite3_step(p1) ){
     const char *zCol = (const char*)sqlite3_column_text(p1, 1);
+    const char *zColSeq = 0;
     int nCopy = STRLEN(zCol) + 1;
     pNew->aCol[nCol].zName = pCsr;
     pNew->aCol[nCol].iPk = (sqlite3_column_int(p1, 5)==1 && nPk==1);
@@ -9883,12 +9886,13 @@ static int idxGetTableInfo(
     pCsr += nCopy;
 
     rc = sqlite3_table_column_metadata(
-        db, "main", zTab, zCol, 0, &zCol, 0, 0, 0
+        db, "main", zTab, zCol, 0, &zColSeq, 0, 0, 0
     );
     if( rc==SQLITE_OK ){
-      nCopy = STRLEN(zCol) + 1;
+      if( zColSeq==0 ) zColSeq = "binary";
+      nCopy = STRLEN(zColSeq) + 1;
       pNew->aCol[nCol].zColl = pCsr;
-      memcpy(pCsr, zCol, nCopy);
+      memcpy(pCsr, zColSeq, nCopy);
       pCsr += nCopy;
     }
 
