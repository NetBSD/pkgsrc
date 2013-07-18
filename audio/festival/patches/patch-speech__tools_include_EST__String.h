$NetBSD: patch-speech__tools_include_EST__String.h,v 1.1 2013/07/18 11:57:42 joerg Exp $

--- speech_tools/include/EST_String.h.orig	2013-07-17 14:40:20.000000000 +0000
+++ speech_tools/include/EST_String.h
@@ -574,10 +574,10 @@ public:
       */
     //@{
     friend int fcompare(const EST_String &a, const EST_String &b, 
-			const unsigned char *table=NULL);
+			const unsigned char *table);
 
     friend int fcompare(const EST_String &a, const char *b, 
-				const unsigned char *table=NULL);
+				const unsigned char *table);
     ///
     friend inline int fcompare(const EST_String &a, const EST_String &b, 
 			       const EST_String &table) 
@@ -643,6 +643,12 @@ int operator == (const char *a, const ES
 int operator == (const EST_String &a, const EST_String &b);
 ostream &operator << (ostream &s, const EST_String &str);
 
+int fcompare(const EST_String &a, const EST_String &b, 
+	     const unsigned char *table=NULL);
+ 
+int fcompare(const EST_String &a, const char *b, 
+	     const unsigned char *table=NULL);
+
 #include "EST_Regex.h"
 
 #endif	
