$NetBSD: patch-maa.h,v 1.2 2012/07/09 19:09:09 joerg Exp $

--- maa.h.orig	2012-07-05 12:00:48.000000000 +0000
+++ maa.h
@@ -438,7 +438,7 @@ extern void           dbg_destroy( void 
 extern void           dbg_set( const char *name );
 extern void           dbg_set_flag( dbg_Type flag );
 extern void           dbg_unset_flag( dbg_Type flag );
-extern __inline__ int dbg_test( dbg_Type flag );
+extern int            dbg_test( dbg_Type flag );
 extern void           dbg_list( FILE *stream );
 
 #define PRINTF(flag,arg)  if (dbg_test(flag)) { log_info arg; }
@@ -450,7 +450,7 @@ typedef unsigned long int flg_Type;
 extern void           flg_register( flg_Type flag, const char *name );
 extern void           flg_destroy( void );
 extern void           flg_set( const char *name );
-extern __inline__ int flg_test( flg_Type flag );
+extern int            flg_test( flg_Type flag );
 extern void           flg_list( FILE *stream );
 extern const          char *flg_name( flg_Type flag );
 
$NetBSD: patch-maa.h,v 1.2 2012/07/09 19:09:09 joerg Exp $

--- maa.h.orig	2012-07-05 12:00:48.000000000 +0000
+++ maa.h
@@ -438,7 +438,7 @@ extern void           dbg_destroy( void 
 extern void           dbg_set( const char *name );
 extern void           dbg_set_flag( dbg_Type flag );
 extern void           dbg_unset_flag( dbg_Type flag );
-extern __inline__ int dbg_test( dbg_Type flag );
+extern int            dbg_test( dbg_Type flag );
 extern void           dbg_list( FILE *stream );
 
 #define PRINTF(flag,arg)  if (dbg_test(flag)) { log_info arg; }
@@ -450,7 +450,7 @@ typedef unsigned long int flg_Type;
 extern void           flg_register( flg_Type flag, const char *name );
 extern void           flg_destroy( void );
 extern void           flg_set( const char *name );
-extern __inline__ int flg_test( flg_Type flag );
+extern int            flg_test( flg_Type flag );
 extern void           flg_list( FILE *stream );
 extern const          char *flg_name( flg_Type flag );
 
