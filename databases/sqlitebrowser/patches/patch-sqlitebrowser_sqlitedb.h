$NetBSD: patch-sqlitebrowser_sqlitedb.h,v 1.1 2013/05/26 12:14:56 rodent Exp $

Fixes "call of overloaded 'QString(int)' is ambiguous" error.

--- sqlitebrowser/sqlitedb.h.orig	2009-12-02 17:26:58.000000000 +0000
+++ sqlitebrowser/sqlitedb.h
@@ -41,7 +41,7 @@ typedef QMap<int, QString> resultMap;
 class DBBrowserField
     {    
     public:
-        DBBrowserField() : name( 0 ) { }
+        DBBrowserField() : name( ) { }
         DBBrowserField( const QString& wname,const QString& wtype )
             : name( wname), type( wtype )
         { }
@@ -55,7 +55,7 @@ class DBBrowserField
 class DBBrowserIndex
     {    
     public:
-        DBBrowserIndex() : name( 0 ) { }
+        DBBrowserIndex() : name( ) { }
        DBBrowserIndex( const QString& wname,const QString& wsql )
             : name( wname), sql( wsql )
         { }
@@ -70,7 +70,7 @@ private:
 class DBBrowserTable
     {    
     public:
-        DBBrowserTable() : name( 0 ) { }
+        DBBrowserTable() : name( ) { }
         DBBrowserTable( const QString& wname,const QString& wsql )
             : name( wname), sql( wsql )
         { }
