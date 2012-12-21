$NetBSD: patch-doctype_mailfolder.cxx,v 1.1 2012/12/21 10:29:47 dholland Exp $

Chase after the C++ standard:
   - use the newfangled names for C++ headers
   - use "std" qualification
   - string constants are const char *

--- doctype/mailfolder.cxx~	1998-05-12 16:48:33.000000000 +0000
+++ doctype/mailfolder.cxx
@@ -115,12 +115,12 @@ Author:		Edward C. Zimmermann, edz@bsn.c
 Distribution:   Isite modifications by A. Warnock (warnock@clark.net)
 @@@-*/
 
-#include <iostream.h>
-#include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
-#include <errno.h>
-#include <ctype.h>
+#include <iostream>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
+#include <cerrno>
+#include <cctype>
 #include "isearch.hxx"
 #include "mailfolder.hxx"
 #include "doc_conf.hxx"
@@ -182,7 +182,7 @@ GDT_BOOLEAN MAILFOLDER::accept_tag(const
 #if RESTRICT_MAIL_FIELDS
   // Mail tags that we want, if it is not
   // here then we igonre it.
-  static char * Keywords[] = {
+  static const char * Keywords[] = {
     /* Must be sorted! */
     "Bcc",
     "Cc",
@@ -252,7 +252,7 @@ void MAILFOLDER::ParseRecords (const REC
   PFILE Fp = fopen (Fn, "rb");
   if (!Fp)
     {
-      cout << "Could not access '" << Fn << "'\n";
+      std::cout << "Could not access '" << Fn << "'\n";
       return;			// File not accessed
 
     }
@@ -362,11 +362,11 @@ void MAILFOLDER::ParseFields (PRECORD Ne
       if (tags)
 	{
 	  delete tags;
-	  cout << "Warning: No `" << doctype << "' fields/tags in \"" << fn << "\" record.\n";
+	  std::cout << "Warning: No `" << doctype << "' fields/tags in \"" << fn << "\" record.\n";
 	}
       else
 	{
-	  cout << "Unable to parse `" << doctype << "' record in \"" << fn << "\".\n";
+	  std::cout << "Unable to parse `" << doctype << "' record in \"" << fn << "\".\n";
 	}
       delete [] RecBuffer;
       return;
@@ -394,11 +394,11 @@ void MAILFOLDER::ParseFields (PRECORD Ne
       if (strncmp(*tags_ptr, "Content-Type", 12) == 0)
 	{
 	  if (strstr(*tags_ptr, "X-sun-attachment")) 
-	    cout << "MAILFOLDER: record in \"" << fn << "\" is " << *tags_ptr << "\n";
+	    std::cout << "MAILFOLDER: record in \"" << fn << "\" is " << *tags_ptr << "\n";
 	}
       else if (strncmp(*tags_ptr, "Content-Transfer-Encoding", 12) == 0)
 	{
-	  cout << "MAILFOLDER: record in \"" << fn << "\" is " << *tags_ptr << "\n";
+	  std::cout << "MAILFOLDER: record in \"" << fn << "\" is " << *tags_ptr << "\n";
 	}
 #endif
       PCHR p = tags_ptr[1];
@@ -550,10 +550,10 @@ GDT_BOOLEAN MAILFOLDER::IsMailFromLine (
   static char magic[] = "From "; // Mail magic
 
 #define MAX_FIELDS 10
-  char *fields[MAX_FIELDS];
+  const char *fields[MAX_FIELDS];
   const char *sender_tail;
   register const char *lp;
-  register char **fp;
+  register const char **fp;
   register int n, i;
   // Email (RFC822) has English language dates from 1 Jan 1970 on
   static char legal_day[] = "SunMonTueWedThuFriSat";
