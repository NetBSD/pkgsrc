$NetBSD: patch-richmail_richlex.c,v 1.1 2025/10/12 00:57:39 mrg Exp $

Port for GCC 14.


--- richmail/richlex.c.orig	1994-02-02 18:29:37.000000000 -0800
+++ richmail/richlex.c	2025-10-11 17:43:11.259027887 -0700
@@ -43,6 +43,7 @@
 
 #include <stdio.h>
 #include <ctype.h>
+#include <string.h>
 #include "richlex.h"
 #include "richset.h"
 
@@ -105,6 +106,7 @@ static	int	PushbackExtract=0;
 /*
  * Reset the richtext parsing mechanism.
  */
+void
 richtextreset()
 {
     StackSize = 0;
@@ -191,7 +193,7 @@ static int richtextmatchup()
  * Determine if the current token is one of the singleton
  * richtext commands: <nl>, <lt>, <np>.
  */
-static richtextsingle(TextEnriched)
+static int richtextsingle(TextEnriched)
 int TextEnriched;
 {
     return (charsetsingle (NextToken) ||
@@ -416,7 +418,7 @@ int nofill; /* Inside a nofill env we pa
 /*
  * Output a string via "RichtextPutc".
  */
-static richtextoutstr(str,outparam)
+static void richtextoutstr(str,outparam)
 char *str;
 void *outparam;
 {
@@ -430,6 +432,7 @@ void *outparam;
  * Read the input stream, correct the richtext, and write the
  * results to the output stream.
  */
+void
 richtextcorrect(inparam,outparam,TextEnriched)
 void *inparam,*outparam;
 int TextEnriched;
@@ -459,6 +462,7 @@ int TextEnriched;
  * Change the encoding used for characters not present in
  * richtext command sequences.
  */
+void
 richtextencoding(encoding)
 int	encoding;
 {
