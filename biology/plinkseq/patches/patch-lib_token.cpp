$NetBSD: patch-lib_token.cpp,v 1.1 2014/02/08 12:27:14 wiedi Exp $

fix math ambiguity on sunos
--- lib/token.cpp.orig	2012-03-17 17:06:01.000000000 +0000
+++ lib/token.cpp
@@ -1232,7 +1232,7 @@ Token Token::operator^(const Token & rhs
       const int sz = size();
       if ( sz == 0 ) return Token();
       std::vector<double> ans( sz );      
-      if      ( rhs.is_int() )   for (int i=0; i<sz; i++) ans[i] = pow( ivec[i] , rhs.ival );
+      if      ( rhs.is_int() )   for (int i=0; i<sz; i++) ans[i] = pow( ivec[i] , (double) rhs.ival );
       else if ( rhs.is_float() ) for (int i=0; i<sz; i++) ans[i] = pow( ivec[i] , rhs.fval );
       return Token( ans );
     }
@@ -1249,7 +1249,7 @@ Token Token::operator^(const Token & rhs
 
   if ( is_int() ) 
     {
-      if ( rhs.is_int() ) return Token( pow( ival , rhs.ival ) );
+      if ( rhs.is_int() ) return Token( pow( ival , (double) rhs.ival ) );
       if ( rhs.is_float() ) return Token( pow( ival , rhs.fval ) );
     }
   if ( is_float() ) 
@@ -2141,7 +2141,7 @@ Token TokenFunctions::fn_set( const Toke
 
 Token TokenFunctions::fn_sqrt( const Token & tok ) const
 {
-  if ( tok.is_int() ) return Token( sqrt( tok.as_int() ) );
+  if ( tok.is_int() ) return Token( sqrt( (double) tok.as_int() ) );
   if ( tok.is_float() ) return Token( sqrt( tok.as_float() ) );
   if ( tok.is_int_vector() || tok.is_float_vector() ) 
     {
@@ -2154,7 +2154,7 @@ Token TokenFunctions::fn_sqrt( const Tok
 
 Token TokenFunctions::fn_log( const Token & tok ) const
 {
-  if ( tok.is_int() ) return Token( log( tok.as_int() ) );
+  if ( tok.is_int() ) return Token( log( (double) tok.as_int() ) );
   if ( tok.is_float() ) return Token( log( tok.as_float() ) );
   if ( tok.is_int_vector() || tok.is_float_vector() ) 
     {
@@ -2168,7 +2168,7 @@ Token TokenFunctions::fn_log( const Toke
 
 Token TokenFunctions::fn_log10( const Token & tok ) const
 {
-  if ( tok.is_int() ) return Token( log10( tok.as_int() ) );
+  if ( tok.is_int() ) return Token( log10( (double) tok.as_int() ) );
   if ( tok.is_float() ) return Token( log10( tok.as_float() ) );
   if ( tok.is_int_vector() || tok.is_float_vector() ) 
     {
@@ -2181,7 +2181,7 @@ Token TokenFunctions::fn_log10( const To
 
 Token TokenFunctions::fn_exp( const Token & tok ) const
 {
-  if ( tok.is_int() ) return Token( exp( tok.as_int() ) );
+  if ( tok.is_int() ) return Token( exp( (double) tok.as_int() ) );
   if ( tok.is_float() ) return Token( exp( tok.as_float() ) );
   if ( tok.is_int_vector() || tok.is_float_vector() ) 
     {
@@ -2202,10 +2202,10 @@ Token TokenFunctions::fn_pow( const Toke
   
   if ( is_int_type && tok2.is_int() ) 
     {
-      if ( tok.is_scalar() ) return Token( (int)(pow( tok.as_int() , tok2.as_int() )) );
+      if ( tok.is_scalar() ) return Token( (int)(pow( tok.as_int() , (double) tok2.as_int() )) );
       std::vector<int> ans = tok.as_int_vector();
       const int ev = tok2.as_int();
-      for (int i=0; i<ans.size(); i++) ans[i] = (int)(pow( ans[i] , ev ) );
+      for (int i=0; i<ans.size(); i++) ans[i] = (int)(pow( ans[i] , (double) ev ) );
       return Token( ans );
     }
   
