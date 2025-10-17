$NetBSD: patch-odbcinst_SQLSetConfigMode.c,v 1.1 2025/10/17 13:15:29 jperkin Exp $

Avoid conflict with system mutex_entry() / mutex_exit().

--- odbcinst/SQLSetConfigMode.c.orig	2025-10-17 13:11:08.381130630 +0000
+++ odbcinst/SQLSetConfigMode.c
@@ -30,7 +30,7 @@ static int __config_mode = ODBC_BOTH_DSN
 static pth_mutex_t mutex_config = PTH_MUTEX_INIT;
 static int pth_init_called = 0;
 
-static int mutex_entry( pth_mutex_t *mutex )
+static int sql_mutex_entry( pth_mutex_t *mutex )
 {
     if ( !pth_init_called )
     {
@@ -40,7 +40,7 @@ static int mutex_entry( pth_mutex_t *mut
     return pth_mutex_acquire( mutex, 0, NULL );
 }
 
-static int mutex_exit( pth_mutex_t *mutex )
+static int sql_mutex_exit( pth_mutex_t *mutex )
 {
     return pth_mutex_release( mutex );
 }
@@ -51,12 +51,12 @@ static int mutex_exit( pth_mutex_t *mute
                 
 static pthread_mutex_t mutex_config = PTHREAD_MUTEX_INITIALIZER;
 
-static int mutex_entry( pthread_mutex_t *mutex )
+static int sql_mutex_entry( pthread_mutex_t *mutex )
 {
     return pthread_mutex_lock( mutex );
 }
 
-static int mutex_exit( pthread_mutex_t *mutex )
+static int sql_mutex_exit( pthread_mutex_t *mutex )
 {
     return pthread_mutex_unlock( mutex );
 }
@@ -67,31 +67,31 @@ static int mutex_exit( pthread_mutex_t *
 
 static mutex_t mutex_config;
 
-static int mutex_entry( mutex_t *mutex )
+static int sql_mutex_entry( mutex_t *mutex )
 {
     return mutex_lock( mutex );
 }
 
-static int mutex_exit( mutex_t *mutex )
+static int sql_mutex_exit( mutex_t *mutex )
 {
     return mutex_unlock( mutex );
 }
 
 #else
 
-#define mutex_entry(x)
-#define mutex_exit(x)
+#define sql_mutex_entry(x)
+#define sql_mutex_exit(x)
 
 #endif
 
 void __lock_config_mode( void )
 {
-    mutex_entry( &mutex_config );
+    sql_mutex_entry( &mutex_config );
 }
 
 void __unlock_config_mode( void )
 {
-    mutex_exit( &mutex_config );
+    sql_mutex_exit( &mutex_config );
 }
 
 void __set_config_mode( int mode )
