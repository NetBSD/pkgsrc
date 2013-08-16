$NetBSD: patch-mDNSShared_dnsextd__parser.y,v 1.1 2013/08/16 10:10:26 jperkin Exp $

Support bison3 syntax.

--- mDNSShared/dnsextd_parser.y.orig	2010-03-17 20:26:12.000000000 +0000
+++ mDNSShared/dnsextd_parser.y
@@ -23,7 +23,7 @@
 #include "DebugServices.h"
 #include "dnsextd.h"
 
-void yyerror( const char* error );
+void yyerror( void *context, const char* error );
 int  yylex(void);
 
 
@@ -81,8 +81,6 @@ static ZoneSpec			*	g_zones;
 static ZoneSpec				g_zoneSpec;
 static const char		*	g_filename;
 
-#define YYPARSE_PARAM  context
-
 void
 SetupOptions
 	(
@@ -92,6 +90,8 @@ SetupOptions
 
 %}
 
+%parse-param { void *context }
+
 %union
 {
 	int			number;
@@ -378,7 +378,7 @@ int yywrap(void);
 
 extern int yylineno;
 
-void yyerror( const char *str )
+void yyerror( void *context, const char *str )
 {
         fprintf( stderr,"%s:%d: error: %s\n", g_filename, yylineno, str );
 }
