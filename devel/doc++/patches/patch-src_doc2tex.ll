$NetBSD: patch-src_doc2tex.ll,v 1.2 2013/04/30 22:16:12 joerg Exp $

--- src/doc2tex.ll.orig	2000-11-05 16:21:16.000000000 +0000
+++ src/doc2tex.ll
@@ -23,8 +23,8 @@
 
 %{
 #include <assert.h>
-#include <fstream.h>
-#include <iostream.h>
+#include <fstream>
+#include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -33,6 +33,8 @@
 #include "classgraph.h"
 #include "doc.h"
 
+using namespace std;
+
 #define YY_DECL int yylex()
 
 #undef	YY_INPUT
@@ -58,7 +60,7 @@ static int	yyLineNr	= 0;
 static int	texBracketCount	= 0;
 static McString	refStr		= "";
 static Entry*	ref		= 0;
-static Entry*	noref		= ref + 1;
+static Entry*	noref		= ::ref + 1;
 static char	yyFileName[264];
 bool		mathmode	= false;
 static int	tabFlag		= 0;
@@ -184,30 +186,30 @@ static void closeVerbMode()
 			}
 
 <Ref>[^}]*		{
-			if(ref == 0)
+			if(::ref == 0)
 			    {
 			    refStr = McString(yytext, 0, yyleng - 2);
-			    ref = getRefEntry(refStr, current);
+			    ::ref = getRefEntry(refStr, current);
 			    }
 			REJECT;
 			}
 
 <Ref>"}"		{
-			if(ref && ref != noref)
+			if(::ref && ::ref != noref)
 			    {
 			    fprintf(out, " ($\\rightarrow$ ");
-			    if(MAKE_DOC(ref))
+			    if(MAKE_DOC(::ref))
 				{
-				ref->dumpNumber(out);
+				::ref->dumpNumber(out);
 				fprintf(out, ",");
 				}
 			    fprintf(out, " {\\em page }\\pageref{cxx.");
-			    ref->dumpNumber(out);
+			    ::ref->dumpNumber(out);
 			    fprintf(out, "})");
 			    }
 			else
 			    fprintf(out, refStr.c_str());
-			ref = 0;
+			::ref = 0;
 			refStr.clear();
 			BEGIN(0);
 			}
@@ -244,28 +246,28 @@ static void closeVerbMode()
 			}
 
 <Link>[^ ]*		{
-			if(ref == 0)
+			if(::ref == 0)
 			    {
 			    McString tmp = yytext;
-			    ref = getRefEntry(tmp, current);
+			    ::ref = getRefEntry(tmp, current);
 			    }
 			REJECT;
 			}
 
 <Link>"}"		{
-			if(ref && ref != noref)
+			if(::ref && ::ref != noref)
 			    {
 			    fprintf(out, " ($\\rightarrow$ ");
-			    if(MAKE_DOC(ref))
+			    if(MAKE_DOC(::ref))
 				{
-				ref->dumpNumber(out);
+				::ref->dumpNumber(out);
 				fprintf(out, ",");
 				}
 			    fprintf(out, " {\\em page }\\pageref{cxx.");
-			    ref->dumpNumber(out);
+			    ::ref->dumpNumber(out);
 			    fprintf(out, "})");
 			    }
-			ref = 0;
+			::ref = 0;
 			BEGIN(0);
 			}
 
