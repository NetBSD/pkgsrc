$NetBSD: patch-src_doc2dbsgml.ll,v 1.2 2013/04/30 22:16:12 joerg Exp $

--- src/doc2dbsgml.ll.orig	2002-05-09 06:11:14.000000000 +0000
+++ src/doc2dbsgml.ll
@@ -22,12 +22,14 @@
 
 %{
 #include <assert.h>
-#include <fstream.h>
-#include <iostream.h>
+#include <fstream>
+#include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
+using namespace std;
+
 #include "classgraph.h"
 #include "doc.h"
 
@@ -53,7 +55,7 @@ static int	skip          = 0;
 static int	tab           = 0;
 static int	yyLineNr      = 0;
 static Entry*	ref           = 0;
-static Entry*	noref         = ref + 1;
+static Entry*	noref         = ::ref + 1;
 static char	yyFileName[264];
 static bool		mathmode      = false;
 static int	tabFlag	      = 0;
@@ -142,28 +144,28 @@ static void closeVerbMode()
 			}
 
 <Ref>[^}]*		{
-			if(ref == 0)
+			if(::ref == 0)
 			    {
 			    McString tmp = yytext;
-			    ref = getRefEntry(tmp, current);
+			    ::ref = getRefEntry(tmp, current);
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
-			ref = 0;
+			::ref = 0;
 			BEGIN(0);
 			}
 
