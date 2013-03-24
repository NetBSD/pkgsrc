$NetBSD: patch-driver_myutil.h,v 1.1 2013/03/24 17:03:15 joerg Exp $

--- driver/myutil.h.orig	2013-03-23 16:08:29.000000000 +0000
+++ driver/myutil.h
@@ -338,7 +338,7 @@ char * add_to_buffer(NET *net,char *to,c
 MY_LIMIT_CLAUSE find_position4limit(CHARSET_INFO* cs, char *query,
                                     char * query_end);
 BOOL myodbc_isspace(CHARSET_INFO* cs, const char * begin, const char *end);
-BOOL got_out_parameters(stmt);
+BOOL got_out_parameters(STMT *stmt);
 
 /* handle.c*/
 BOOL          allocate_param_bind(DYNAMIC_ARRAY **param_bind, uint elements);
