$NetBSD: patch-src_ptlib_common_getdate.y,v 1.1 2013/10/14 14:36:12 joerg Exp $

--- src/ptlib/common/getdate.y.orig	2013-10-14 12:59:57.000000000 +0000
+++ src/ptlib/common/getdate.y
@@ -107,7 +107,6 @@ struct Variables {
 
 #define YYPURE		1
 #define YYLEX_PARAM	VARIABLE
-#define YYPARSE_PARAM	parseParam
 
 #define yyparse		PTime_yyparse
 #define yylex		PTime_yylex
@@ -120,19 +119,15 @@ struct Variables {
 static int yyparse(void *); 
 static int yylex();
 
-#ifdef __GNUC__
-static int yyerror(char const *msg);
-#else
-static void yyerror(char const *msg);
-#endif
-
+static int yyerror(void *param, char const *msg);
 
 static void SetPossibleDate(struct Variables*, time_t, time_t, time_t);
 
 
 %}
 
-%pure_parser
+%pure-parser
+%parse-param { void * parseParam}
 
 %union {
     time_t		Number;
@@ -1017,16 +1012,10 @@ time_t STDAPICALLTYPE PTimeParse(void * 
 #pragma warning(disable:4028 4100 4211)
 #endif
 
-#ifdef __GNUC__
-int yyerror(const char * s)
+int yyerror(void *parseParam, const char * s)
 {
   return 0;
 }
-#else
-static void yyerror(const char * s)
-{
-}
-#endif
 
 #ifdef _MSC_VER
 #pragma warning(default:4028 4100 4211)
