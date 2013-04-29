$NetBSD: patch-libmysql_libmysql.c,v 1.1 2013/04/29 21:16:56 joerg Exp $

--- libmysql/libmysql.c.orig	2013-04-28 13:52:54.000000000 +0000
+++ libmysql/libmysql.c
@@ -2071,7 +2071,7 @@ static my_bool execute(MYSQL_STMT *stmt,
   buff[4]= (char) stmt->flags;
   int4store(buff+5, 1);                         /* iteration count */
 
-  res= test(cli_advanced_command(mysql, COM_STMT_EXECUTE, buff, sizeof(buff),
+  res= my_test(cli_advanced_command(mysql, COM_STMT_EXECUTE, buff, sizeof(buff),
                                  (uchar*) packet, length, 1, stmt) ||
             (*mysql->methods->read_query_result)(mysql));
   stmt->affected_rows= mysql->affected_rows;
@@ -2559,7 +2559,7 @@ int STDCALL mysql_stmt_execute(MYSQL_STM
     reinit_result_set_metadata(stmt);
     prepare_to_fetch_result(stmt);
   }
-  DBUG_RETURN(test(stmt->last_errno));
+  DBUG_RETURN(my_test(stmt->last_errno));
 }
 
 
@@ -3179,7 +3179,7 @@ static void fetch_string_with_conversion
     int err;
     double data= my_strntod(&my_charset_latin1, value, length, &endptr, &err);
     float fdata= (float) data;
-    *param->error= (fdata != data) | test(err);
+    *param->error= (fdata != data) | my_test(err);
     floatstore(buffer, fdata);
     break;
   }
@@ -3187,7 +3187,7 @@ static void fetch_string_with_conversion
   {
     int err;
     double data= my_strntod(&my_charset_latin1, value, length, &endptr, &err);
-    *param->error= test(err);
+    *param->error= my_test(err);
     doublestore(buffer, data);
     break;
   }
@@ -3196,7 +3196,7 @@ static void fetch_string_with_conversion
     MYSQL_TIME_STATUS status;
     MYSQL_TIME *tm= (MYSQL_TIME *)buffer;
     str_to_time(value, length, tm, &status);
-    *param->error= test(status.warnings);
+    *param->error= my_test(status.warnings);
     break;
   }
   case MYSQL_TYPE_DATE:
@@ -3206,7 +3206,7 @@ static void fetch_string_with_conversion
     MYSQL_TIME_STATUS status;
     MYSQL_TIME *tm= (MYSQL_TIME *)buffer;
     (void) str_to_datetime(value, length, tm, TIME_FUZZY_DATE, &status);
-    *param->error= test(status.warnings) &&
+    *param->error= my_test(status.warnings) &&
                    (param->buffer_type == MYSQL_TYPE_DATE &&
                     tm->time_type != MYSQL_TIMESTAMP_DATE);
     break;
@@ -3331,7 +3331,7 @@ static void fetch_long_with_conversion(M
     int error;
     value= number_to_datetime(value, (MYSQL_TIME *) buffer, TIME_FUZZY_DATE,
                               &error);
-    *param->error= test(error);
+    *param->error= my_test(error);
     break;
   }
   default:
@@ -3679,7 +3679,7 @@ static void fetch_result_with_conversion
 static void fetch_result_tinyint(MYSQL_BIND *param, MYSQL_FIELD *field,
                                  uchar **row)
 {
-  my_bool field_is_unsigned= test(field->flags & UNSIGNED_FLAG);
+  my_bool field_is_unsigned= my_test(field->flags & UNSIGNED_FLAG);
   uchar data= **row;
   *(uchar *)param->buffer= data;
   *param->error= param->is_unsigned != field_is_unsigned && data > INT_MAX8;
@@ -3689,7 +3689,7 @@ static void fetch_result_tinyint(MYSQL_B
 static void fetch_result_short(MYSQL_BIND *param, MYSQL_FIELD *field,
                                uchar **row)
 {
-  my_bool field_is_unsigned= test(field->flags & UNSIGNED_FLAG);
+  my_bool field_is_unsigned= my_test(field->flags & UNSIGNED_FLAG);
   ushort data= (ushort) sint2korr(*row);
   shortstore(param->buffer, data);
   *param->error= param->is_unsigned != field_is_unsigned && data > INT_MAX16;
@@ -3700,7 +3700,7 @@ static void fetch_result_int32(MYSQL_BIN
                                MYSQL_FIELD *field __attribute__((unused)),
                                uchar **row)
 {
-  my_bool field_is_unsigned= test(field->flags & UNSIGNED_FLAG);
+  my_bool field_is_unsigned= my_test(field->flags & UNSIGNED_FLAG);
   uint32 data= (uint32) sint4korr(*row);
   longstore(param->buffer, data);
   *param->error= param->is_unsigned != field_is_unsigned && data > INT_MAX32;
@@ -3711,7 +3711,7 @@ static void fetch_result_int64(MYSQL_BIN
                                MYSQL_FIELD *field __attribute__((unused)),
                                uchar **row)
 {
-  my_bool field_is_unsigned= test(field->flags & UNSIGNED_FLAG);
+  my_bool field_is_unsigned= my_test(field->flags & UNSIGNED_FLAG);
   ulonglong data= (ulonglong) sint8korr(*row);
   *param->error= param->is_unsigned != field_is_unsigned && data > LONGLONG_MAX;
   longlongstore(param->buffer, data);
@@ -4705,7 +4705,7 @@ my_bool STDCALL mysql_stmt_close(MYSQL_S
   my_free(stmt->extension);
   my_free(stmt);
 
-  DBUG_RETURN(test(rc));
+  DBUG_RETURN(my_test(rc));
 }
 
 /*
