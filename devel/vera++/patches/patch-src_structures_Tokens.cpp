$NetBSD: patch-src_structures_Tokens.cpp,v 1.1 2013/05/11 21:31:21 joerg Exp $

--- src/structures/Tokens.cpp.orig	2013-05-10 14:39:26.000000000 +0000
+++ src/structures/Tokens.cpp
@@ -91,7 +91,7 @@ typedef map<SourceFiles::FileName, Token
 
 FileTokenCollection fileTokens_;
 
-typedef vector<function<bool (wave::token_id)> > CompiledFilterSequence;
+typedef vector<boost::function<bool (wave::token_id)> > CompiledFilterSequence;
 
 wave::token_id tokenIdFromTokenFilter(const Tokens::TokenFilter & filter)
 {
