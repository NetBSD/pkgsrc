$NetBSD: patch-doctype_html.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification
   - string constants are const char *

--- doctype/html.cxx~	2000-02-04 22:46:35.000000000 +0000
+++ doctype/html.cxx
@@ -115,12 +115,12 @@ Author:   	Edward C. Zimmermann, edz@bsn
 Copyright:	Basis Systeme netzwerk, Munich
 @@@-*/
 
-#include <iostream.h>
-#include <stdio.h>
-#include <stdlib.h>
-#include <ctype.h>
-#include <string.h>
-#include <errno.h>
+#include <iostream>
+#include <cstdio>
+#include <cstdlib>
+#include <cctype>
+#include <cstring>
+#include <cerrno>
 #include "isearch.hxx"
 //#include "common.hxx"
 #include "html.hxx"
@@ -183,7 +183,7 @@ static int IsHTMLAttributeTag (const cha
 {
   // HTML Attributes where we are also interested in values
   static struct {
-    char *tag;
+    const char *tag;
     unsigned char len;
   } Tags[] = {
 /*- UNSORTED LIST (lowercase names) -*/ 
@@ -357,7 +357,7 @@ static int IgnoreHTMLTag (const char *ta
 #endif
 
 // Search for the next occurance of an element of tags in tag_list
-static const char *find_next_tag (char *const *tag_list, char *const *tags)
+static const char *find_next_tag (char *const *tag_list, const char *const *tags)
 {
   if (*tag_list == NULL)
     return NULL;
@@ -393,7 +393,7 @@ void HTML::ParseFields (PRECORD NewRecor
   if (fp == NULL)
     {
     error:
-      cout << "Unable to parse HTML file \"" << fn << "\"\n";
+      std::cout << "Unable to parse HTML file \"" << fn << "\"\n";
       return;
     }
 
@@ -451,17 +451,17 @@ void HTML::ParseFields (PRECORD NewRecor
 	  if (StrCaseCmp (*tags_ptr, "dd") == 0)
 	    {
 	      // Look for nearest <DT> or </DL>
-	      static char *tags[] = {"dt", "/dl", NULL};
+	      static const char *tags[] = {"dt", "/dl", NULL};
 	      p = find_next_tag (tags_ptr, tags);
 	      if (p == NULL)
 		{
 		  // Some bogus uses
-		  static char *tags[] = {"dd", "/ul", "/ol", NULL};
+		  static const char *tags[] = {"dd", "/ul", "/ol", NULL};
 		  p = find_next_tag (tags_ptr, tags);
 		  if (p)
 		    {
 		      // Give some information
-		      cout << "HTML Warning: \""
+		      std::cout << "HTML Warning: \""
 			<< fn << "\" offset " << (size_t) (*tags_ptr - RecBuffer) << ": "
 			<< "Bogus use of <" << *tags_ptr << ">, using <" << p << "> as end tag.\n";
 		    }
@@ -470,17 +470,17 @@ void HTML::ParseFields (PRECORD NewRecor
 	  else if (StrCaseCmp (*tags_ptr, "dt") == 0)
 	    {
 	      // look for next <DD> or </DL>
-	      static char *tags[] = {"DD", "/DL", NULL};
+	      static const char *tags[] = {"DD", "/DL", NULL};
 	      p = find_next_tag (tags_ptr, tags);
 	      if (p == NULL)
 		{
 		  // Some bogus uses
-		  static char *tags[] = {"dt", "/ul", "/ol", NULL};
+		  static const char *tags[] = {"dt", "/ul", "/ol", NULL};
 		  p = find_next_tag (tags_ptr, tags);
 		  if (p)
 		    {
 		      // Give some information
-		      cout << "HTML Warning: \""
+		      std::cout << "HTML Warning: \""
 			<< fn << "\" offset " << (*tags_ptr - RecBuffer) << ": "
 			<< "Bogus use of <" << *tags_ptr << ">, using <" << p << "> as end tag.\n";
 		    }
@@ -489,13 +489,13 @@ void HTML::ParseFields (PRECORD NewRecor
 	  else if (StrCaseCmp (*tags_ptr, "li") == 0)
 	    {
 	      // look for next <LI>, </OL> or </UL>
-	      static char *tags[] = {"li", "/ol", "/ul", NULL};
+	      static const char *tags[] = {"li", "/ol", "/ul", NULL};
 	      p = find_next_tag (tags_ptr, tags);
 	    }
 	  else if (StrCaseCmp (*tags_ptr, "tl") == 0)
 	    {
 	      // look for nearest <TL> or </TLI>
-	      static char *tags[] = {"tl", "/tli", NULL};
+	      static const char *tags[] = {"tl", "/tli", NULL};
 	      p = find_next_tag (tags_ptr, tags);
 	    }
 	}			// end code to handle some HTML minimized tags
