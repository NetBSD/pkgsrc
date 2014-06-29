$NetBSD: patch-vslib_regexp3.cpp,v 1.1 2014/06/29 19:43:54 dholland Exp $

Sprinkle const to make more modern C++ compilers happier.

--- vslib/regexp3.cpp~	2002-04-26 06:40:08.000000000 +0000
+++ vslib/regexp3.cpp
@@ -183,7 +183,7 @@ int regmatch( char *prog); /* 0 failure,
 int regrepeat( char *p);
 char * regnext( char *p);
 char * regprop( char *op);
-void regerror( char *s );
+void regerror( const char *s );
  
 
 char regerror_str[REGERROR_STR_SIZE];
@@ -226,7 +226,7 @@ int regmatchpos( const char* pattern, co
   return res;
 }
 
-void regerror( char *s )
+void regerror( const char *s )
 {
   strcpy( regerror_str, s );
 };
