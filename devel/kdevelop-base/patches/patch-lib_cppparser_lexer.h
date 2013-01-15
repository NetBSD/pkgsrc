$NetBSD: patch-lib_cppparser_lexer.h,v 1.1 2013/01/15 15:20:44 joerg Exp $

--- lib/cppparser/lexer.h.orig	2013-01-14 22:00:13.000000000 +0000
+++ lib/cppparser/lexer.h
@@ -346,7 +346,7 @@ private:
 };
 
 
-inline Token::Token(const QString & text = "")
+inline Token::Token(const QString & text)
     : m_type( -1 ),
       m_position( 0 ),
       m_length( 0 ),
