$NetBSD: patch-src_parsers_util_scanner.cpp,v 1.1 2022/09/25 11:01:34 he Exp $

Adapt to system where char == unsigned char.

--- src/parsers/util/scanner.cpp.orig	2018-11-19 20:21:17.000000000 +0000
+++ src/parsers/util/scanner.cpp
@@ -18,7 +18,7 @@ Revision History:
 --*/
 #include "parsers/util/scanner.h"
 
-inline char scanner::read_char() {
+inline signed char scanner::read_char() {
     if (m_is_interactive) {
         ++m_pos;
         return m_stream.get();
@@ -58,7 +58,7 @@ inline bool scanner::state_ok() {
 
 void scanner::comment(char delimiter) {
     while(state_ok()) {
-        char ch = read_char();
+        signed char ch = read_char();
         if ('\n' == ch) {
             ++m_line;
         }
@@ -68,7 +68,7 @@ void scanner::comment(char delimiter) {
     }        
 }
 
-scanner::token scanner::read_symbol(char ch) {
+scanner::token scanner::read_symbol(signed char ch) {
     bool escape = false;
     if (m_smt2)
         m_string.pop_back(); // remove leading '|'
@@ -94,7 +94,7 @@ scanner::token scanner::read_symbol(char
 
 
 scanner::token scanner::read_id(char first_char) {
-    char ch;
+    signed char ch;
     m_string.reset();
     m_params.reset();
     m_string.push_back(first_char);
@@ -159,7 +159,7 @@ bool scanner::read_params() {
     unsigned param_num = 0;
     
     while (state_ok()) {
-        char ch = read_char();
+        signed char ch = read_char();
         switch (m_normalized[(unsigned char) ch]) {
         case '0': 
             param_num = 10*param_num + (ch - '0');
@@ -208,7 +208,7 @@ scanner::token scanner::read_number(char
     m_state = INT_TOKEN;
     
     while (true) {
-        char ch = read_char();
+        signed char ch = read_char();
         if (m_normalized[(unsigned char) ch] == '0') {
             m_number = rational(10)*m_number + rational(ch - '0');
             if (m_state == FLOAT_TOKEN) {
@@ -236,7 +236,7 @@ scanner::token scanner::read_string(char
     m_string.reset();
     m_params.reset();
     while (true) {
-        char ch = read_char();
+        signed char ch = read_char();
         
         if (!state_ok()) {
             return m_state;
@@ -265,7 +265,7 @@ scanner::token scanner::read_string(char
 scanner::token scanner::read_bv_literal() {
     TRACE("scanner", tout << "read_bv_literal\n";);
     if (m_bv_token) {
-        char ch     = read_char();
+        signed char ch     = read_char();
         if (ch == 'x') {
             ch = read_char();
             m_number  = rational(0);
@@ -315,7 +315,7 @@ scanner::token scanner::read_bv_literal(
     }
     else {
         // hack for the old parser
-        char ch     = read_char();
+        signed char ch     = read_char();
         bool is_hex = false;
         
         m_state = ID_TOKEN;
@@ -449,7 +449,7 @@ scanner::scanner(std::istream& stream, s
 
 scanner::token scanner::scan() {
     while (state_ok()) {
-        char ch = read_char();        
+        signed char ch = read_char();        
         switch (m_normalized[(unsigned char) ch]) {
         case ' ':
             break;
