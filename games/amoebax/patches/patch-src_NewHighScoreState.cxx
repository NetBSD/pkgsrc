$NetBSD: patch-src_NewHighScoreState.cxx,v 1.1 2025/09/29 14:06:05 nia Exp $

Build fixes for modern clang; via FreeBSD Ports

--- src/NewHighScoreState.cxx.orig	2009-02-28 17:38:34.000000000 +0000
+++ src/NewHighScoreState.cxx
@@ -396,7 +396,7 @@ NewHighScoreState::unicodeCharacterPress
     // FIXME: We are only interessted with ASCII values.
     if ( 0 == (code & 0xff80) )
     {
-        char character[2] = {toupper (static_cast<char>(code & 0x7f)), '\0'};
+        char character[2] = {static_cast<char>(toupper (static_cast<char>(code & 0x7f)), '\0')};
         std::string::size_type characterPos =
             m_CursorValues.find (std::string (character));
         if ( std::string::npos != characterPos )
